//
// Created by gianluca on 13/09/19.
//

#ifndef MELONE_ENTITYBASE_H
#define MELONE_ENTITYBASE_H

#include "EntityManager.h"
#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

enum class EntityType{ Base, Enemy, Player };

enum class EntityState{ Idle, Walking, Jumping, Attacking, Hurt, Dying };

struct TileInfo;

struct CollisionElement{
    CollisionElement(float l_area, TileInfo* l_info, const sf::FloatRect& l_bounds)
            :m_area(l_area), m_tile(l_info), m_tileBounds(l_bounds){}
    float m_area;
    TileInfo* m_tile;
    sf::FloatRect m_tileBounds;
};

using Collisions = std::vector<CollisionElement>;
bool SortCollisions(const CollisionElement& l_1, const CollisionElement& l_2);

class EntityManager;

class EntityBase {
    friend  class EntityManager;
public:
    EntityBase(EntityManager* l_entityMgr);
    virtual ~EntityBase();

    const sf::Vector2f& GetPosition()const;
    const sf::Vector2f& GetSize()const;
    EntityState GetState()const;
    std::string GetName()const;
    unsigned int GetId()const;
    EntityType GetType()const;
    void SetPosition(float l_x, float l_y);
    void SetPosition(const sf::Vector2f& l_pos);
    void SetSize(float l_x, float l_y);
    void SetState(const EntityState& l_state);

    void Move(float l_x, float l_y);
    void AddVelocity(float l_x, float l_y);
    void Accelerate(float l_x, float l_y);
    void SetAcceleration(float l_x, float l_y);
    void ApplayFriction(float l_x, float l_y);
    virtual  void Update(float l_dT);
    virtual void Draw(sf::RenderWindow* l_wind) = 0;
protected:
    void UpdateAABB();
    void CheckCollisions();
    void ResolveCollisions();
    virtual void OnEntityCollision(EntityBase* l_collider, bool l_attck)=0;
    std::string m_name;
    EntityType m_type;
    unsigned int m_id;
    sf::Vector2f m_position;//current
    sf::Vector2f m_positionOld;
    sf::Vector2f m_velocity;
    sf::Vector2f m_maxVelocity;
    sf::Vector2f m_speed;
    sf::Vector2f m_acceleration;
    sf::Vector2f m_friction;
    TileInfo* m_referenceTile;
    sf::Vector2f m_size;
    sf::FloatRect m_AABB;
    EntityState m_state;
    bool m_collidingOnX;
    bool m_collidingOnY;
    Collisions m_collisions;
    EntityManager* m_entityManager;
};


#endif //MELONE_ENTITYBASE_H
