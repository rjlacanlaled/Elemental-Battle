//
//  ElementalCreatureFactory.h
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#ifndef ElementalCreatureFactory_h
#define ElementalCreatureFactory_h

#include "ElementalCreature.h"
#include "ElementalCreatureType.h"
#include "Mage.h"
#include "Demigod.h"
#include "Salamander.h"
#include "Golem.h"
#include "Harpy.h"
#include "Serpent.h"

class ElementalCreatureFactory{
    
public:
    ElementalCreatureFactory(){}
    virtual ~ElementalCreatureFactory(){}
    
    virtual ElementalCreature* createCreature(ElementalCreatureType elemCreatureType);
    
};

#endif /* ElementalCreatureFactory_h */
