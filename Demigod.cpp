//
//  Demigod.cpp
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include "Demigod.h"
#include <iostream>

Demigod::Demigod(){
    
    mName = NAME;
    mElementType = new ElementType(ALL, ALL, NONE);
    mCharacterType = NPC;
    
}
