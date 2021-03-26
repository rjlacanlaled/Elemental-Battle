//
//  Mage.cpp
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include "Mage.h"
#include <iostream>

Mage::Mage(){
    
    mName = "Mage";
    mElementType = new ElementType(NONE, NONE, NONE);
    mCharacterType = Player;
}


