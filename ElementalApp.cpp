//
//  ElementalApp.cpp
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include "ElementalApp.h"
#include "Random.h"
#include <cstdlib>
#include <ctime>
using namespace std;

// Global variables for values needed by a lot of methods
Range*  randomStatRange = new Range(5, 8);
int     elementStatBonus  = 2;
int     elementAttackBonusPercentage = 50;
int     runChancePercentage = 50;

// Initiates the needed objects to run the app
// ecf = elemental creature factory object
// es = elemental stats object (calculates stats depending on element type)
// inp = input validator object to handle inputs and printing
ElementalApp::ElementalApp(){
    
    ecf = new ElementalCreatureFactory();
    es = new ElementalStats();
    inp = new InputValidator();
    
}

// The start of the elemental app
void ElementalApp::start(){
    
    srand((unsigned int) time(0));
    
    // Create a character
    ElementalCreature* mage = createMage();
    displayStats(mage);
    
    bool done = false;
    
    while(!done){
        
        done = findEncounterUntilDeathOrWin(mage);
        
    }
}

// Will spawn random creature using he ElementalCreatureFactory class
ElementalCreature* ElementalApp::spawnRandomElementalCreature(){
    
    ElementalCreature* randElemCreature = ecf->createCreature(generateRandomCreatureType());
    
    // Generate random stats for the creature depending on the type;
    Stats* randomStats = es->generateRandomStats(
                            randElemCreature->getElementType()->getType(),
                            randomStatRange, elementStatBonus);
    
    // Set random stats to the elemental creature
    randElemCreature->setStats(randomStats);
    
    // Return the created elemental creature
    return randElemCreature;
}

// This will generate a random creature type to be used
// by spawnRandomElementalCreature()
ElementalCreatureType ElementalApp::generateRandomCreatureType(){
    
    // 10% chance to spawn Demigod
    if(es->hasChance(10)){
        
        return DEMIGOD;
        
    // Else each elemental creatures get 25% chance to spawn
    } else{
        
        switch (Random(1, 8)) {
            case 1:
            case 2:
                
                return SALAMANDER;
                break;
                
            case 3:
            case 4:
                
                return GOLEM;
                break;
                
            case 5:
            case 6:
                
                return HARPY;
                break;
            
            default:
                
                return SERPENT;
                break;
        }
        
    }
    
}

// Initiates character creation for players
ElementalCreature* ElementalApp::createMage(Stats* prevStats){
    
    // Create mage instance
    ElementalCreature* mage = ecf->createCreature(MAGE);
    
    // Get character name
    string name = inp->getStringInputWithNoSpecialChar
                        ("Enter your character name: ");
    
    // Get element type
    ElementType* elementType = selectElementType();
    
    // Generate random stats
    Stats* newStats = es->generateRandomStats
                        (elementType->getType(), randomStatRange, elementStatBonus);
    
    // Check which stats is higher if there is a previous stats passed
    if(prevStats != NULL){
        
        newStats = es->getHigherStats(prevStats, newStats);
        
    }
    
    // Set data for mage
    mage->setName(name);
    mage->setElementType(elementType);
    mage->setStats(newStats);
    
    return mage;
    
}

// Displays combat menu if attacker is a player
void ElementalApp::displayCombatMenu(){
    
    cout <<
    "[1] Attack \n"
    "[2] Run \n";
    
    
        
}

// Display elements to choose from
void ElementalApp::displayElements(){
    
    cout <<
    "[1] Earth \n"
    "[2] Fire \n"
    "[3] Water \n"
    "[4] Wind \n";
    
}

// Asks player to select element type
ElementType* ElementalApp::selectElementType(){
    
    inp->displayTitle("SELECT ELEMENT");
    displayElements();
    int selection = inp->getInputWithinRange
                        ("Enter your choice: ", 1, 4);
    switch (selection) {
        case 1:
            return new ElementType(EARTH, WIND, FIRE);
            break;
        case 2:
           return new ElementType(FIRE, EARTH, WATER);
            break;
        case 3:
            return new ElementType(WATER, FIRE, WIND);
            break;
        default:
            return new ElementType(WIND, WATER, EARTH);
            break;
    }
}


// Puts two creatures in a battle arena and attacks by turn
void ElementalApp::enterBattle(ElementalCreature* firstAttacker,
                               ElementalCreature* secondAttacker){
    
    bool isOver = false;

    while(!isOver){
        
        displayRunningHealth(firstAttacker, secondAttacker);
        
        if(!firstAttacker->isDead()){
            
            isOver = combatTurn(firstAttacker, secondAttacker);
            
            if(isOver){
                
                break;
            }
        }
            
        if(!secondAttacker->isDead()){
                
            isOver = combatTurn(secondAttacker, firstAttacker);
                
            if(isOver){
                    
                break;
                    
            }
            
        }
        
        if(firstAttacker->isDead()){
            
            inp->displayMessage(firstAttacker->getName() + " has died!" );
            
            isOver = true;
            
            break;
        }
        
        if(secondAttacker->isDead()){

            inp->displayMessage(secondAttacker->getName() + " has died!" );
            
            isOver = true;
            
            break;
        }
    }
}

// Calculates the damage of the attacker
int ElementalApp::getDamage(ElementalCreature* attacker, ElementalCreature* defender){
    
    return es->calculateDamage(attacker->getStats(),
                               defender->getStats(),
                               attacker->getElementType(),
                               defender->getElementType(),
                               elementAttackBonusPercentage);
    
}

// Calculates the hitrate of the attacker
int ElementalApp::getHitRate(ElementalCreature* attacker, ElementalCreature* defender){
  
    return es->calculateHitRate(attacker->getStats(), defender->getStats());
    
}


// Asks player for combat option
int ElementalApp::getPlayerCombatSelection(){
    
    displayCombatMenu();
    
    return inp->getInputWithinRange("Enter your choice: ", 1, 2);
}

// Calculates the hitrate and amount of damage to inflict and display appropriate message
void ElementalApp::attack(ElementalCreature* attacker, ElementalCreature* defender){
    
    int damageToInflict = getDamage(attacker, defender);
    int hitRate = getHitRate(attacker, defender);
    
    // Checks whether an attack will land and displays appropriate message
    // to follow whats happening in the battle
    tryToAttack(attacker, defender, damageToInflict, hitRate);
}

// Will check if user can run and display appropriate message
bool ElementalApp::run(){
    
    
    if(es->hasChance(runChancePercentage)){
        
        inp->displayMessage("You have successfully ran away from the enemy!");
        
        return true;
        
    }else{
        
        inp->displayMessage("You have failed to run away from the enemy!");
        
        return false;
        
    }
    
}

// If attacker is a player, the combat options will display
bool ElementalApp::combatTurn(ElementalCreature* attacker, ElementalCreature* defender){
    
    bool gonnaRun = false;;
    
    if(attacker->getCharacterType() == Player){
        
        int selection = getPlayerCombatSelection();
        
        switch (selection) {
            case 1:
                attack(attacker, defender);
                break;
                
            default:
                gonnaRun = run();
                break;
        }
        
    }else{
        
        attack(attacker, defender);
        
    }
    
    return gonnaRun;
    
}


// Display the current hitpoints of a creature
void ElementalApp::displayHitpoint(ElementalCreature* creature){
    
    printf("%-12s= %-d/%-d\n", creature->getName().c_str(),
                                  creature->getCurrentHp(),
                                  creature->getStats()->mHp);
    
    
}

// When victory, increase stats and display message
void ElementalApp::victory(ElementalCreature* mage, ElementalCreature* enemy){
    
    cout << "You have won against " << enemy->getName() << " !" << endl;
    
    // Calculate the stats to add and add it to the appropriate stats
    // depending on the enemy's element type
    int statAdded = es->
                    increaseElementStatsFromAnotherStats(
                             enemy->getElementType(),
                             mage->getStats(),
                             enemy->getStats(), 50);
    
    // Regen 30% of user hp
    int regenAmount = mage->regenHp(30);
    
    // Display the added stats
    displayAddedStats(enemy->getElementType()->getType(), regenAmount, statAdded);
    
    // Display the new stats
    displayNewStats(mage);
    
}

bool ElementalApp::findEncounterUntilDeathOrWin(ElementalCreature* mage){
    
    bool done = false;
    
    ElementalCreature* enemy = spawnRandomElementalCreature();
        
    enemyEncounter(mage, enemy);
        
    if(mage->isDead()){
            
        done = revive(mage);
        mage->regenHp();
            
    }else{
            
        if(enemy->isDead()){
            
            done = checkReward(mage, enemy);
                
        }
            
    }
    
    delete enemy;
    
    return done;
    
}


void ElementalApp::enemyEncounter(ElementalCreature* mage, ElementalCreature* enemy){
    
    inp->displayMessage("You have encountered a " + enemy->getName() + "!");
    displayStats(enemy);
    
    // Find first to attack and then enter battle arena
    findFirstToAttack(mage, enemy);
    
}

// Finds the first actor to attack
void ElementalApp::findFirstToAttack(ElementalCreature* mage, ElementalCreature* enemy){
    
    if(es->isStatHigher(AGI, mage->getStats(), enemy->getStats())){
        
        enterBattle(mage, enemy);
        
    }else{
        
        enterBattle(enemy, mage);
        
    }
    
}

// Display stats with name and element type
void ElementalApp::displayStats(ElementalCreature* creature){
    
    cout << creature->getName() << "'s stats: " << endl;
    es->displayElementalStats(creature->getStats(), creature->getElementType());
    
}

// Asks the user if wants to be revived and then asks to create a new character
bool ElementalApp::revive(ElementalCreature* mage){
    
    if(inp->confirm("Do you want to revive and create a new character?")){
            
            mage = createMage(mage->getStats());
            displayStats(mage);
        
    }else{
            
            inp->displayMessage("Game over!");
            return true;
    }
    
    return false;
    
}


// Checks reward and displays victory message
bool ElementalApp::checkReward(ElementalCreature* mage, ElementalCreature* enemy){
    
    if(enemy->getName() == "Demigod"){
            
        inp->displayMessage("Congratulations! You have successfully defeated the DEMIGOD! Your battle is now over. Bye!");
            
        return true;
            
    }else{
            
        victory(mage, enemy);
            
    }
    
    return false;
    
}

// Displays the new stats acquired by the mage
void ElementalApp::displayNewStats(ElementalCreature* mage){
    
    cout << endl;
    cout << "===== NEW STATS =====" << endl;
    cout << "Current HP: " << mage->getCurrentHp() << endl;
    es->displayElementalStats(mage->getStats(), mage->getElementType());
    
}

// Displays the added stats
void ElementalApp::displayAddedStats(Element element, int regenAmount, int statAdded){
    
    if(regenAmount > 0){
        
        cout << "Your current hp has regenerated by " << regenAmount << ". " << endl;
        
    }
    
    switch (element) {
        case EARTH:
            cout << "VIT + " << statAdded << endl;
            break;
        case FIRE:
            cout << "INT + " << statAdded << endl;
            break;
        case WIND:
            cout << "AGI + " << statAdded << endl;
            break;
        default:
            cout << "DEX + " << statAdded << endl;
            break;
    }
    
}

void ElementalApp::tryToAttack(ElementalCreature* attacker,
                                      ElementalCreature* defender,
                                      int damageToInflict,
                                      int hitRate){
    
    // Display attack animation
    inp->displayMessage(attacker->getName() + " is attacking " +
                               defender->getName() + "...");
    
    // Checks if attack will land or not
    if(es->hasChance(hitRate)){

        
        inflictDamage(attacker, defender, damageToInflict);
        
        
    }else{
        
        inp->displayMessage(attacker->getName() + "'s attack missed!");
        
    }
    
    cout << "---------------------------------------" << endl;
    
}

void ElementalApp::inflictDamage(ElementalCreature* attacker,
                                 ElementalCreature* defender,
                                 int damageToInflict){
    
    inp->displayMessage(attacker->getName()
                    + " dealt " +
                    to_string(damageToInflict) +
                    " damage!");
    
    attacker->attack(damageToInflict, defender);
}

// Displays the running health of both players during battle
void ElementalApp::displayRunningHealth(ElementalCreature* firstAttacker,
                                        ElementalCreature* secondAttacker){
    
    cout << endl << "Remaining health: " << endl;
    displayHitpoint(firstAttacker);
    displayHitpoint(secondAttacker);
    cout << endl;
    
}
