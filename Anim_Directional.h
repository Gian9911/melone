//
// Created by gianluca on 04/09/19.
//

#ifndef MELONE_ANIM_DIRECTIONAL_H
#define MELONE_ANIM_DIRECTIONAL_H


#include "Anim_Base.h"
#include "SpriteSheet.h"

class Anim_Directional : public Anim_Base {
protected:
    void FrameStep();
    void CropSprite();
    void ReadIn(std::stringstream& l_stream);
};


#endif //MELONE_ANIM_DIRECTIONAL_H
