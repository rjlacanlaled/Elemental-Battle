//
//  Serpent.h
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#ifndef Serpent_h
#define Serpent_h

#include "ElementalCreature.h"
#include "Element.h"

class Serpent : public ElementalCreature{
    
    const string NAME = "Serpent";
    
public:
    Serpent();
    virtual ~Serpent(){}
    
};

#endif /* Serpent_h */
