//
//  ElementalStats.cpp
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include "ElementalStats.h"
#include "Random.h"
#include <string>
using namespace std;

// Global variables needed by some methods
int hpLimit = 999;
int otherStatLimit = 300;

//sm = StatsManipulator instance
//inp = InputValidator instance
ElementalStats::ElementalStats(){
    
    sm = new StatsManipulator();
    inp = new InputValidator();
    
}



// Generates random stats depending on the range given
Stats* ElementalStats::generateRandomStats(Range* range){
    
    Stats* randomStats = new Stats();
    
    sm->addAllStats(randomStats, range);
    randomStats->mHp = randomStats->mHp * 5;
    
    return randomStats;
}

// Generates random stats depending on the element type
Stats* ElementalStats::generateRandomStats(Element element, Range* range, int elementalBonus){
    Stats* randomStats = generateRandomStats(range);
    
    switch (element) {
            
        case EARTH:
            
            sm->multiplyStat(VIT, randomStats, elementalBonus);
            break;
            
        case FIRE:
            
            sm->multiplyStat(INT, randomStats, elementalBonus);
            break;
            
        case WATER:
            
            sm->multiplyStat(DEX, randomStats, elementalBonus);
            break;
            
        case WIND:
            
            sm->multiplyStat(AGI, randomStats, elementalBonus);
            break;
            
        case ALL:
        case NONE:
            
            sm->multiplyAllStats(randomStats, elementalBonus * 14);
            break;
            
        default:
            
            throw invalid_argument("Element type not found!");
            break;
    }
    
    return randomStats;
}

// Calculates the damage of the attacking player against the defending player
// and takes into consideration the element type and adds bonus damage accordingly
int ElementalStats::calculateDamage(Stats* attackerStats, Stats* defenderStats,
                    ElementType* attackerElemType, ElementType* defenderElemType,
                    int dmgBonusPercentage){
    
    Range dmgRange;
    
    dmgRange.setLow(attackerStats->mInt - (defenderStats->mVit / 2)) ;
    dmgRange.setHigh(attackerStats->mInt - (defenderStats->mVit / 4));
    
    if(dmgRange.getLow() < 1){
        
        dmgRange.setLow(1);
        
    }
    
    if(dmgRange.getHigh() < 3){
        
        dmgRange.setHigh(3);
        
    }
    
    
    if(attackerElemType->getStrength() == defenderElemType->getType()
       || attackerElemType->getType() == ALL){
        
        dmgRange.setLow((dmgRange.getLow() * (dmgBonusPercentage + 100)) / 100);
        dmgRange.setHigh((dmgRange.getHigh() * (dmgBonusPercentage + 100))/ 100);
        
    }

    return Random(dmgRange);
}

// Calculates the hitrate of the attacking player/monster
int ElementalStats::calculateHitRate(Stats* attackerStats, Stats* defenderStats){
    
    int hitRate = (attackerStats->mDex /
                   defenderStats->mAgi) * 100;
    
    if(hitRate > 80){
        
        hitRate = 80;
        
    }else if(hitRate < 20){
        
        hitRate = 20;
        
    }
    
    
    return hitRate;
    
}

// Rolls from 1 to 100 and compares it from the chancePercentage value given
bool ElementalStats::hasChance(int chancePercentage){

    if(Random(1, 100) < chancePercentage){
        
        return true;
        
    }else{
        
        return false;
        
    }
    
}

// Increases a stat depending on the other stat and element type
int ElementalStats::increaseElementStatsFromAnotherStats(ElementType* elementType,
                                          Stats* stats, Stats* anotherStats,
                                          int percentage){
    
    int amountToAdd = 0;
    
    amountToAdd = sm->getStatAmountByPercentage(HP, anotherStats, 35);
    if(stats->mHp + amountToAdd > hpLimit){
        stats->mHp = hpLimit;
    }else{
        sm->addStat(HP, stats, amountToAdd);
    }
    
    
    switch (elementType->getType()) {
            
        case EARTH:
            amountToAdd = sm->getStatAmountByPercentage(VIT, anotherStats, percentage);
            if(stats->mVit + amountToAdd > otherStatLimit){
                stats->mVit = otherStatLimit;
            }else{
                sm->addStat(VIT, stats, amountToAdd);
            }
            
            break;
            
        case FIRE:
            amountToAdd = sm->getStatAmountByPercentage(INT, anotherStats, percentage);
            if(stats->mInt + amountToAdd > otherStatLimit){
                stats->mInt = otherStatLimit;
            }else{
                sm->addStat(INT, stats, amountToAdd);
            }
            break;
            
        case WATER:
            amountToAdd = sm->getStatAmountByPercentage(DEX, anotherStats, percentage);
            if(stats->mDex + amountToAdd > otherStatLimit){
                stats->mDex = otherStatLimit;
            }else{
                sm->addStat(DEX, stats, amountToAdd);
            }
            break;
            
        case WIND:
            amountToAdd = sm->getStatAmountByPercentage(AGI, anotherStats, percentage);
            if(stats->mAgi + amountToAdd > otherStatLimit){
                stats->mAgi = otherStatLimit;
            }else{
                sm->addStat(AGI, stats, amountToAdd);
            }
            break;
        
        default:
            
            throw invalid_argument("Element type not found!");
            break;
    }
    
    return amountToAdd;
    
}

// Checks whether a stat is higher than the other
bool ElementalStats::isStatHigher(Stat stat, Stats* stat1, Stats* stat2){
    
    bool isHigher = false;
    
    switch (stat) {
        case HP:
            
            if(stat1->mHp >= stat2->mHp){
                
                isHigher = true;
                
            }
            
            break;
        case AGI:
            
            if(stat1->mAgi >= stat2->mAgi){
                
                isHigher = true;
                
            }
            
            break;
        case DEX:
            
            if(stat1->mDex >= stat2->mDex){
                
                isHigher = true;
                
            }
            
            break;
        case INT:
            
            if(stat1->mInt >= stat2->mInt){
                
                isHigher = true;
                
            }
            
            break;
        case VIT:
            
            if(stat1->mVit >= stat2->mVit){
                
                isHigher = true;
                
            }
            
            break;
            
        default:
            
            throw new invalid_argument("Stat not found!");
            break;
    }
    
    return isHigher;
    
}

// Gets the actual value of higher stat from comparing 2 stats
int ElementalStats::getHigherStat(Stat stat, Stats* oldStat, Stats* newStat){
    
    int higher = 0;
    
    switch (stat) {
        case HP:
                
            if(isStatHigher(HP, oldStat, newStat)){
                
                higher =  oldStat->mHp;
                
            }else{
                
                higher = newStat->mHp;
                
            }
                
            break;
        case AGI:
                
            if(isStatHigher(AGI, oldStat, newStat)){
                
                higher =  oldStat->mAgi;
                
            }else{
                
                higher = newStat->mAgi;
                
            }

            break;
        case DEX:
                
            if(isStatHigher(DEX, oldStat, newStat)){
                
                higher =  oldStat->mDex;
                
            }else{
                
                higher = newStat->mDex;
                
            }
                
            break;
        case INT:
                
            if(isStatHigher(INT, oldStat, newStat)){
                
                higher =  oldStat->mInt;
                
            }else{
                
                higher = newStat->mInt;
                
            }
                
            break;
        case VIT:
                
            if(isStatHigher(VIT, oldStat, newStat)){
                
                higher =  oldStat->mVit;
                
            }else{
                
                higher = newStat->mVit;
                
            }

                
            break;
                
        default:
                
            throw new invalid_argument("Stat not found!");
            break;
    }
        
    return higher;
    
}

// Gets the higher stat from 2 differnt stats and returns it
Stats* ElementalStats::getHigherStats(Stats* oldStat, Stats* newStat){
    
    newStat->mHp = getHigherStat(HP, oldStat, newStat);
    newStat->mAgi = getHigherStat(AGI, oldStat, newStat);
    newStat->mDex = getHigherStat(DEX, oldStat, newStat);
    newStat->mInt = getHigherStat(INT, oldStat, newStat);
    newStat->mVit = getHigherStat(VIT, oldStat, newStat);
    
    return newStat;
}


// Display stats with the element type
void ElementalStats::displayElementalStats(Stats* stats, ElementType* elementType){
    printf("%-12s%-12s\n", "ELEMENT TYPE: ",
           elementType->toString(elementType->getType()).c_str());
    printf("%-8s%-6s%-3s%-6s%-8s\n", "STRENGTH >> ",
           elementType->toString(elementType->getStrength()).c_str(),
           " | ",
           elementType->toString(elementType->getWeakness()).c_str(),
           " << WEAKNESS");
    sm->displayStats(stats);
}



