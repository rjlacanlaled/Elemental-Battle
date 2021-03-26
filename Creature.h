//
//  Creature.h
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#ifndef Creature_h
#define Creature_h

#include <string>
using namespace std;

class Stats;

class Creature{
    
public:
    virtual ~Creature(){}
    
    virtual string  getName()              = 0;
    virtual Stats*  getStats()             = 0;
    virtual void    setName(string name)   = 0;
    virtual void    setStats(Stats* stats) = 0;
    
protected:
    string mName;
    Stats* mStats;
};

#endif /* Creature_h */
