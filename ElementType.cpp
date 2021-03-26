//
//  ElementType.cpp
//  Phase 1 - Practical
//
//  Created by RJ Lacanlale on 11/26/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include <stdio.h>

#include "ElementType.h"

ElementType::ElementType(){
    
    mType = NONE;
    mStrength = NONE;
    mWeakness = NONE;
    
}

ElementType::ElementType(Element type, Element strength, Element weakness){
    
    mType = type;
    mStrength = strength;
    mWeakness = weakness;
    
}

void ElementType::setType(Element type){
    
    mType = type;
    
}

void ElementType::setWeakness(Element weakness){
    
    mWeakness = weakness;
    
}

void ElementType::setStrength(Element strength){
    
    mStrength = strength;

}

Element ElementType::getType(){
    
    return mType;
    
}

Element ElementType::getWeakness(){
    
    return mWeakness;
    
}

Element ElementType::getStrength(){
    
    return mStrength;
    
}


string ElementType::toString(Element element){
    
    string elementStr = "";
    
    switch (element) {
        case EARTH:
            
            elementStr = "Earth";
            break;
            
        case FIRE:
            
            elementStr = "Fire";
            break;
            
        case WATER:
            
            elementStr = "Water";
            break;
            
        case WIND:
            elementStr = "Wind";
            break;
        
        case ALL:
            elementStr = "All";
            break;
        
        case NONE:
            elementStr = "None";
            break;
        
        default:
            throw new invalid_argument("Element not found!");
            break;
            
    }
    
    return elementStr;
    
}
