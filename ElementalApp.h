//
//  ElementalApp.h
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#ifndef ElementalApp_h
#define ElementalApp_h

#include "ElementalCreatureFactory.h"
#include "ElementalCreature.h"
#include "ElementalStats.h"
#include "InputValidator.h"

class ElementalApp{
    
public:
    ElementalApp();
    ~ElementalApp(){
        delete ecf;
        delete es;
        delete inp;
    }
    
    bool combatTurn(ElementalCreature* attacker, ElementalCreature* defender);
    bool run();
    bool findEncounterUntilDeathOrWin(ElementalCreature* mage);

    int getDamage(ElementalCreature* attacker, ElementalCreature* defender);
    int getHitRate(ElementalCreature* attacker, ElementalCreature* defender);
    int getPlayerCombatSelection();
    
    void start();
    void displayCombatMenu();
    void displayElements();
    void enterBattle(ElementalCreature* mage, ElementalCreature* enemy);
    void attack(ElementalCreature* attacker, ElementalCreature* defender);
    void displayHitpoint(ElementalCreature* creature);
    void victory(ElementalCreature* mage, ElementalCreature* enemy);
    void enemyEncounter(ElementalCreature* mage, ElementalCreature* enemy);
    void findFirstToAttack(ElementalCreature* mage, ElementalCreature* enemy);
    void displayStats(ElementalCreature* creature);
    void displayNewStats(ElementalCreature* mage);
    void displayAddedStats(Element element, int regenAmount, int statAdded);
    void tryToAttack(ElementalCreature* attacker, ElementalCreature* defender,
                            int damageToInflict, int hitRate);
    void inflictDamage(ElementalCreature* attacker, ElementalCreature* defender,
                       int damageToInflict);
    void displayRunningHealth(ElementalCreature* firstAttacker,
                              ElementalCreature* secondAttacker);
    
    bool checkReward(ElementalCreature* mage, ElementalCreature* enemy);
    bool revive(ElementalCreature* mage);
    
    ElementType* selectElementType();
    ElementalCreature* spawnRandomElementalCreature();
    ElementalCreature* createMage(Stats* prevStats = NULL);
    ElementalCreatureType generateRandomCreatureType();

private:
    ElementalCreatureFactory* ecf;
    ElementalStats* es;
    InputValidator* inp;
};

#endif /* ElementalApp_h */
