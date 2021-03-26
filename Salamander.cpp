//
//  Salamander.cpp
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include "Salamander.h"
#include <iostream>

Salamander::Salamander(){
    
    mName = NAME;
    mElementType = new ElementType(FIRE, EARTH, WATER);
    mCharacterType = NPC;
}

