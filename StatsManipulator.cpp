//
//  StatsManipulator.cpp
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include "StatsManipulator.h"
#include "Random.h"
#include <string>
using namespace std;

// Multiplies a fixed value to a specific stat
void StatsManipulator::multiplyStat(Stat stat, Stats* stats, int val){
    
    switch (stat) {
        case HP:
            stats->mHp *= val;
            break;
        case AGI:
            stats->mAgi *= val;
            break;
        case DEX:
            stats->mDex *= val;
            break;
        case INT:
            stats->mInt *= val;
            break;
        case VIT:
            stats->mVit *= val;
            break;
        default:
            throw new invalid_argument("Stat not found!");
            break;
    }
}

// Adds a fixed value to a specific stat
void StatsManipulator::addStat(Stat stat, Stats* stats, int val){
    
    switch (stat) {
        case HP:
            stats->mHp += val;
            break;
        case AGI:
            stats->mAgi += val;
            break;
        case DEX:
            stats->mDex += val;
            break;
        case INT:
            stats->mInt += val;
            break;
        case VIT:
            stats->mVit += val;
            break;
        default:
            throw new invalid_argument("Stat not found!");
            break;
    }
    
}

// Multiplies a fixed value into all stats
void StatsManipulator::multiplyAllStats(Stats* stats, int val){
    
    multiplyStat(HP, stats, val);
    multiplyStat(AGI, stats, val);
    multiplyStat(DEX, stats, val);
    multiplyStat(INT, stats, val);
    multiplyStat(VIT, stats, val);
    
}

// Adds a fixed value to all stats
void StatsManipulator::addAllStats(Stats* stats, int val){
    addStat(HP, stats, val);
    addStat(AGI, stats, val);
    addStat(DEX, stats, val);
    addStat(INT, stats, val);
    addStat(VIT, stats, val);
    
}

// Multiplies stats by a range
void StatsManipulator::multiplyAllStats(Stats* stats, Range* range){
    
    multiplyStat(HP, stats, Random(*range));
    multiplyStat(AGI, stats, Random(*range));
    multiplyStat(DEX, stats, Random(*range));
    multiplyStat(INT, stats, Random(*range));
    multiplyStat(VIT, stats, Random(*range));
    
}

// Adds a range value into all stats
void StatsManipulator::addAllStats(Stats* stats, Range* range){

    addStat(HP, stats, Random(*range));
    addStat(AGI, stats, Random(*range));
    addStat(DEX, stats, Random(*range));
    addStat(INT, stats, Random(*range));
    addStat(VIT, stats, Random(*range));
    
}

// Increases a specific stat by percentage
void StatsManipulator::increaseByPercentage(Stat stat, Stats* stats, int percentage){
    
    switch (stat) {
        case HP:
            stats->mHp += (stats->mHp * percentage / 100);
            break;
        case AGI:
            stats->mAgi += (stats->mAgi * percentage / 100);
            break;
        case DEX:
            stats->mDex += (stats->mDex * percentage / 100);
            break;
        case INT:
            stats->mInt += (stats->mInt * percentage / 100);
            break;
        case VIT:
            stats->mVit += (stats->mVit * percentage / 100);
            break;
        default:
            throw new invalid_argument("Stat not found!");
            break;
    }
    
    
}

// Increases all stats by percentage
void StatsManipulator::increaseAllStatsByPercentage(Stats* stats, int percentage){
    
    increaseByPercentage(HP,  stats, percentage);
    increaseByPercentage(AGI, stats, percentage);
    increaseByPercentage(INT, stats, percentage);
    increaseByPercentage(DEX, stats, percentage);
    increaseByPercentage(VIT, stats, percentage);
    
}

// Calculates an amount from stats by percentage
int StatsManipulator::getStatAmountByPercentage(Stat stat, Stats* stats, int percentage){
    
    int amount = 0;
    
    switch (stat) {
        case HP:
            amount = (stats->mHp * percentage)/100;
            break;
        case AGI:
            amount = (stats->mAgi * percentage)/100;
            break;
        case DEX:
            amount = (stats->mDex * percentage)/100;
            break;
        case INT:
            amount = (stats->mInt * percentage)/100;
            break;
        case VIT:
            amount = (stats->mVit * percentage)/100;
            break;
        default:
            throw new invalid_argument("Stat not found!");
            break;
    }
    
    return amount;
    
}

// Displays the stats
void StatsManipulator::displayStats(Stats* stats){
    
    printf("%-4s%-4s%-4s%-4s%-4s\n", "HP", "AGI", "DEX", "INT", "VIT");
    printf("%-4d%-4d%-4d%-4d%-4d\n", stats->mHp,
                                   stats->mAgi,
                                   stats->mDex,
                                   stats->mInt,
                                   stats->mVit);
    
}
