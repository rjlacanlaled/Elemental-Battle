//
//  ElementalCreatureFactory.cpp
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include "ElementalCreatureFactory.h"

// Returns an ElementalCreature object
ElementalCreature*
    ElementalCreatureFactory::
        createCreature(ElementalCreatureType elemCreatureType){
    
            switch (elemCreatureType) {
                case MAGE:
                    
                    return new Mage();
                    break;
                    
                case SALAMANDER:
                    
                    return new Salamander();
                    break;
                    
                case GOLEM:
                    
                    return new Golem();
                    break;
                    
                case HARPY:
                    
                    return new Harpy();
                    break;
                    
                case SERPENT:
            
                    return new Serpent();
                    break;
                    
                case DEMIGOD:
                    
                    return new Demigod();
                    break;
                    
                default:
                    
                    throw invalid_argument("Elemental creature type not found!");
                    break;
            }
    
}
