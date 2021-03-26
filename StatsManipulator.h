//
//  StatsManipulator.h
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#ifndef StatsManipulator_h
#define StatsManipulator_h

#include "Stats.h"
#include "Stat.h"
#include "Range.h"

class StatsManipulator{
    
public:
    StatsManipulator(){}
    ~StatsManipulator(){}
    
    // FIXED VALUES
    void multiplyStat(Stat stat, Stats* stats, int val);
    void addStat(Stat stat, Stats* stats, int val);
    void multiplyAllStats(Stats* stats, int val);
    void addAllStats(Stats* stats, int val);
    
    // RANGE VALUES
    void multiplyAllStats(Stats* stats, Range* range);
    void addAllStats(Stats* stats, Range* range);
    
    // PERCENTAGE VALUES
    void increaseByPercentage(Stat stat, Stats* stats, int percentage);
    void increaseAllStatsByPercentage(Stats* stats, int percentage);
    
    // PRINT VALUES
    void displayStats(Stats* stats);
    
    // With return value
    int getStatAmountByPercentage(Stat stat, Stats* stats, int percentage);

};

#endif /* StatsManipulator_h */
