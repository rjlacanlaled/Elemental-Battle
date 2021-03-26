//
//  ElementalCreature.h
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#ifndef ElementalCreature_h
#define ElementalCreature_h

#include "Creature.h"
#include "ElementType.h"
#include "Stats.h"
#include "CharacterType.h"

class ElementalCreature : public Creature{
    
public:
    ElementalCreature(){}
    virtual ~ElementalCreature(){}
    
    virtual string          getName();
    virtual Stats*          getStats();
    virtual ElementType*    getElementType();
    virtual int             getCurrentHp();
    virtual CharacterType   getCharacterType();
    virtual void            setName(string name);
    virtual void            setStats(Stats* stats);
    virtual void            setCurrentHp(int hp);
    virtual void            setElementType(ElementType* elementType);
    virtual void            attack(int damageToInflict,
                                   ElementalCreature* defender);
    virtual void            takeDamage(int damageToTake);
    virtual bool            isDead();
    virtual int             regenHp(int percentage = 100);
    
protected:
    ElementType* mElementType;
    int mCurrentHp;
    CharacterType mCharacterType;
};

#endif /* ElementalCreature_h */
