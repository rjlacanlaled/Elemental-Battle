//
//  Range.cpp
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include "Range.h"

Range::Range(int low, int high){
    
    mLow = low;
    mHigh = high;
    
}

void Range::setLow(int low){
    
    mLow = low;
    
}

void Range::setHigh(int high){
    
    mHigh = high;
    
}

int  Range::getLow(){
    
    return mLow;
    
}

int  Range::getHigh(){
    
    return mHigh;
    
}
