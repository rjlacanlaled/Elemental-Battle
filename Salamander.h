//
//  Salamander.h
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#ifndef Salamander_h
#define Salamander_h

#include "ElementalCreature.h"
#include "Element.h"

class Salamander : public ElementalCreature{
    
    const string NAME = "Salamander";
    
public:
    Salamander();
    virtual ~Salamander(){}
    
};

#endif /* Salamander_h */
