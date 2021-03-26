//
//  ElementalCreature.cpp
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include "ElementalCreature.h"
#include <iostream>
using namespace std;


string ElementalCreature::getName(){
    
    return mName;
    
}

Stats* ElementalCreature::getStats(){
    
    return mStats;
}

ElementType* ElementalCreature::getElementType(){
    
    return mElementType;
    
}

int ElementalCreature::getCurrentHp(){
    
    return mCurrentHp;
    
}

CharacterType ElementalCreature::getCharacterType(){
    
    return mCharacterType;
    
}

void ElementalCreature::setName(string name){
    
    
    mName = name;
    
}

void ElementalCreature::setStats(Stats* stats){
    
    mStats = stats;
    
    if(mStats->mHp > 999){
        
        mStats->mHp = 999;
        
    }
    
    if(mStats->mAgi > 300){
        
        mStats->mAgi = 300;
        
    }
    
    if(mStats->mDex > 300){
        
        mStats->mDex = 300;
        
    }
    
    if(mStats->mInt > 300){
        
        mStats->mInt = 300;
        
    }
    
    if(mStats->mVit > 300){
        
        mStats->mVit = 300;
        
    }
    
    
    mCurrentHp = mStats->mHp;
}
void ElementalCreature::setElementType(ElementType* elementType){
    
    mElementType = elementType;
    
}

void ElementalCreature::setCurrentHp(int hp){
    
    mCurrentHp = hp;
    
}


void ElementalCreature::attack(int damageToInflict,
                        ElementalCreature* defender){
    
    if(damageToInflict < 1){
        
        damageToInflict = 1;
        
    }
    
    defender->takeDamage(damageToInflict);
    
}

void ElementalCreature::takeDamage(int damageToTake){
    
    mCurrentHp -= damageToTake;
    
    if(mCurrentHp < 0){
        
        mCurrentHp = 0;
        
    }
    
}

bool ElementalCreature::isDead(){
    
    if(mCurrentHp <= 0){
        
        return true;
        
    }
    
    return false;
    
}

int ElementalCreature::regenHp(int percentage /* 100% by default */){
    
    int prevHp = mCurrentHp;
    int healAmount = (mStats->mHp * percentage) / 100;
    
    mCurrentHp += healAmount;
    
    if(mCurrentHp > mStats->mHp){
        
        mCurrentHp = mStats->mHp;
        
    }
    
    return mCurrentHp - prevHp;
    
}
