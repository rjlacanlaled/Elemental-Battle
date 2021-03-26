//
//  InputValidator.h
//  5.6 Exercise - Final
//
//  Created by RJ Lacanlale on 11/21/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#ifndef InputValidator_h
#define InputValidator_h

#include <iostream>
#include <string>
using namespace std;

struct InputValidator{
    
    bool isValidInput(std::istream& cin);
    bool isWithinIntRange(int input, int min, int max);
    bool confirm(string message);
    bool getYesNo(string message);
    bool hasNoSpecialChars(string input);
    bool isEmpty(string input);
    
    double getInputWithinRange(string message, double lowest, double highest);
    
    int  getInputWithinRange(string message, int lowest, int highest);
    int findPosOfNthOccurrence(int occurence, string str, char to_search);
    
    void displayNotWithinRangeError(int min, int max);
    void displayNotWithinRangeError(double min, double max);
    void displayMessage(string message);
    void displayTitle(string titleName);
    
    string toLower(string input);
    string toUpper(string input);
    string getStringInputToUpper(string message);
    string getStringInputToUpperWithNoSpecialChar(string message);
    string getStringInputWithNoSpecialChar(string message);
    string getStringInput(string message);
    string findSubStrFromRange(int begin, int end, string str, char to_search);
    
};

#endif /* InputValidator_h */
