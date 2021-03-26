//
//  Harpy.cpp
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include "Harpy.h"
#include <iostream>

Harpy::Harpy(){
    
    mName = NAME;
    mElementType = new ElementType(WIND, WATER, EARTH);
    mCharacterType = NPC;
}
