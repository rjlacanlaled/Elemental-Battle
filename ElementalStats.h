//
//  ElementalStats.h
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#ifndef ElementalStats_h
#define ElementalStats_h

#include "Element.h"
#include "Stats.h"
#include "Range.h"
#include "InputValidator.h"
#include "ElementType.h"
#include "StatsManipulator.h"

class ElementalStats{
    
public:
    ElementalStats();
    ~ElementalStats(){
        delete sm;
        delete inp;
    }
    

    bool   hasChance(int chancePercentage);
    bool   isStatHigher(Stat stat, Stats* stat1, Stats* stat2);
   
    int    calculateDamage(Stats* attackerStats, Stats* defenderStats,
                                    ElementType* attackerElemType,
                                    ElementType* defenderElemType,
                                    int dmgBonusPercentage);
    int    getHigherStat(Stat stat, Stats* oldStat, Stats* newStat);
    int    calculateHitRate(Stats* attackerStats, Stats* defenderStats);
    int    increaseElementStatsFromAnotherStats
                        (ElementType* elementType, Stats* stats,
                         Stats* anotherStats, int percentage);
    
    void   displayElementalStats(Stats* stats, ElementType* elementType);
    
    Stats* generateRandomStats(Range* range);
    Stats* generateRandomStats(Element element, Range* range, int elementalBonus);
    Stats* getHigherStats(Stats* oldStat, Stats* newStat);
    
private:
    StatsManipulator* sm;
    InputValidator* inp;
};

#endif /* ElementalStats_h */
