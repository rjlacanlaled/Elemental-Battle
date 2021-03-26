//
//  ElementType.h
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#ifndef ElementType_h
#define ElementType_h

#include "Element.h"
#include <string>
using namespace std;

class ElementType{
    
public:
    ElementType();
    ~ElementType(){}
    ElementType(Element type, Element strength, Element weakness);
    
    Element   getType();
    Element   getWeakness();
    Element   getStrength();
    void      setType(Element type);
    void      setWeakness(Element weakness);
    void      setStrength(Element strength);
    string    toString(Element element);
    
    
private:
    Element mType;
    Element mWeakness;
    Element mStrength;
};

#endif /* ElementType_h */
