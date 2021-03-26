//
//  Serpent.cpp
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include "Serpent.h"
#include <iostream>

Serpent::Serpent(){
    
    mName = NAME;
    mElementType = new ElementType(WATER, FIRE, WIND);
    mCharacterType = NPC;
}
