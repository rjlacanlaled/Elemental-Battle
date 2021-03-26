//
//  Golem.cpp
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include "Golem.h"
#include <iostream>

Golem::Golem(){
    
    mName = NAME;
    mElementType = new ElementType(EARTH, WIND, FIRE);
    mCharacterType = NPC;
}
