//
//  Harpy.h
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#ifndef Harpy_h
#define Harpy_h

#include "ElementalCreature.h"
#include "Element.h"

class Harpy : public ElementalCreature{
    
    const string NAME = "Harpy";
    
public:
    Harpy();
    virtual ~Harpy(){}
    
};

#endif /* Harpy_h */
