//
//  Golem.h
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#ifndef Golem_h
#define Golem_h

#include "ElementalCreature.h"
#include "Element.h"

class Golem : public ElementalCreature{
    
    const string NAME = "Golem";
    
public:
    Golem();
    virtual ~Golem(){}
    
};

#endif /* Golem_h */
