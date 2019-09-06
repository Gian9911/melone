//
// Created by gianluca on 05/09/19.
//

#include <cmath>
#include "Map.h"
Map::Map(SharedContext *l_context, BaseState *l_currentState) : m_context(l_context), m_defaultTile(l_context),
m_maxMapSize(32,32), m_tileCount(0), m_tileSetCount(0), m_mapGravity(512.f), m_loadNextMap(false),
m_currentState(l_currentState){
    m_context->m_gameMap = this;
    LoadTiles("tiles.cfg");
}

Map::~Map() {
    PurgeMap();
    PurgeTileSet();
    m_context->m_gameMap = nullptr;
}

Tile* Map::GetTile(unsigned int l_x, unsigned int l_y) {
    auto itr = m_tileMap.find(ConvertCoords(l_x, l_y));
    return ( itr != m_tileMap.end() ? itr->second:nullptr);
}

unsigned int Map::ConvertCoords(unsigned int l_x, unsigned int l_y) {
    return (l_x * m_maxMapSize.x) + l_y;
}

void Map::Update(float l_dT) {
    if (m_loadNextMap){
        PurgeMap();
        m_loadNextMap = false;
        if (m_nextMap != ""){
            LoadMap("media/maps/"+m_nextMap);
        }else{
            m_currentState->GetStateManager()->SwitchTo(StateType::GameOver);
        }
        m_nextMap = "";
    }
    sf::FloatRect viewSpace = m_context->m_wind->GetViewSpace();
    m_background.setPosition(viewSpace.left, viewSpace.top);
}

TileInfo* Map::GetDefaultTile(){ return &m_defaultTile; }
float Map::GetGravity()const{ return m_mapGravity; }
unsigned int Map::GetTileSize()const{ return Sheet::Tile_Size; }
const sf::Vector2u& Map::GetMapSize()const{ return m_maxMapSize; }
const sf::Vector2f& Map::GetPlayerStart()const{ return m_playerStart; }

void Map::Draw() {
    sf::RenderWindow* l_wind = m_context->m_wind->GetRenderindow();
    l_wind->draw(m_background);
    sf::FloatRect viewSpace = m_context->m_wind->GetViewSpace();
    sf::Vector2i tileBegin( floor(viewSpace.left /Sheet::Tile_Size),floor(viewSpace.top/Sheet::Tile_Size));
    sf::Vector2i tileEnd(ceil((viewSpace.left + viewSpace.width)/Sheet::Tile_Size),
            ceil((viewSpace.top + viewSpace.height)/Sheet::Tile_Size));

    unsigned int count = 0;
    for (int x = tileBegin.x; x<=tileEnd.x;++x){
        for (int y = tileBegin.y; y <= tileEnd.y;++y){
            if ( x < 0 || y < 0){ continue;}
            Tile* tile = GetTile(x,y);
            if (!tile){ continue;}
            sf::Sprite& sprite = tile->m_properties->m_sprite;
            sprite.setPosition(x* Sheet::Tile_Size, y*Sheet::Tile_Size);
            l_wind->draw(sprite);
            ++count;
        }
    }
}

void Map::PurgeMap() {
    m_tileCount = 0;
    for (auto &itr:m_tileMap){
        delete itr.second;
    }
    m_tileMap.clear();
    m_context->m_entityManager->Purge();
    if( m_backgroundTexture == ""){ return;}
    m_context->m_textureManager->ReleaseResource(m_backgroundTexture);
    m_backgroundTexture == "";
}

void Map::PurgeTileSet() {
    for (auto &itr : m_tileSet){
        delete itr.second;
    }
    m_tileSet.clear();
    m_tileSetCount = 0;
}

void Map::LoadTiles(const std::string &l_path) {
    std::ifstream file;
    file.open(Utils::GetWorkingDirectory()+l_path);
    if(!file.is_open()){
        std::cout << "!Faled loading tile set file : " << l_path << std::endl;
        return;
    }
    std::string line;
    while(std::getline(file,line)){
        if(line[0]=='|'){ continue;}
        std::stringstream keystream(line);
        int tileId;
        keystream>>tileId;
        if(tileId<0){continue;}
        TileInfo* tile = new TileInfo(m_context,"TileSheet", tileId);
        keystream >> tile->m_name >> tile->m_deadly;
        if(!m_tileSet.emplace(tileId,tile).second){
            std::cout <<"!Duplicate tile type: "<<tile->m_name<<std::endl;
            delete tile;
        }
    }
    file.close();
}

