//
//  Range.h
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#ifndef Range_h
#define Range_h

class Range{
    
public:
    Range(){}
    Range(int low, int high);
    ~Range(){}
    
    void    setLow(int low);
    void    setHigh(int high);
    int     getLow();
    int     getHigh();
    
private:
    int mLow;
    int mHigh;
};

#endif /* Range_h */
