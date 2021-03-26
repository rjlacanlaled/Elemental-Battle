//
//  InputValidator.cpp
//  5.6 Exercise - Final
//
//  Created by RJ Lacanlale on 11/21/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include "InputValidator.h"
#include <iostream>
using namespace std;

bool InputValidator::isValidInput(istream& cin){
    
    if( !cin ){
        

        displayMessage("Please enter a valid input!");
        
        cin.clear();
        cin.ignore(1000,'\n');
        
        return false;
        
    }
    
    return true;
}

bool InputValidator::isWithinIntRange(int input, int min, int max){
    
    if(input >= min && input <= max){
        
        return true;
        
    }
    
    return false;
    
}

void InputValidator::displayNotWithinRangeError(int min, int max){
    
    displayMessage("Please enter an input greater than or equal to "
                          + to_string(min) +
                          "Please enter an input greater than or equal to "
                          + to_string(max) +
                          "!");
    
}

void InputValidator::displayNotWithinRangeError(double min, double max){
    
    cout << "Please enter an input greater than or equal to "  << min <<
    " and less than or equal to " << max <<"!" << endl;
    
}

int  InputValidator::getInputWithinRange(string message, int lowest, int highest){
    
    bool isWithin = false;
    int input = 0;
    
    do{
        
        cout << message;
        cin >> input;
        cin.ignore();
        isWithin = isWithinIntRange(input, lowest, highest);
        
        if(!isWithin){
            
            displayNotWithinRangeError(lowest, highest);
            
        }
        
        
    }while(!isValidInput(cin) || !isWithin);
    
    cout << endl;
    
    return input;
}

double InputValidator::getInputWithinRange(string message, double lowest, double highest){
    
        bool isWithin = false;
        int input = 0;
        
        do{
            
            cout << message;
            cin >> input;
            cin.ignore();
            isWithin = isWithinIntRange(input, lowest, highest);
            
            if(!isWithin){
                
                displayNotWithinRangeError(lowest, highest);
                
            }
            
            
        }while(!isValidInput(cin) || !isWithin);
        
        return input;
    
}

bool InputValidator::getYesNo(string message){
    
    
    cout << message;
    
    int input =
    getInputWithinRange("\n[0] No \n[1] Yes \nEnter choice: ", 0, 1);
    
    if(input == 0){
        
        return false;
        
    }else{
        
        return true;
    }
    
}


string InputValidator::toLower(string str){
    
    for(int i = 0; i < str.length(); i++){

        if(str[i] >= 65 && str[i] <= 90){
            
            str[i] += 32;
            
        }
        
    }
    
    return str;
}


string InputValidator::getStringInput(string message){
    
    string input;
    
    cout << message;
    getline(cin, input);
    
    return input;
}


bool InputValidator::confirm(string message){
    
    
    return getYesNo(message);
}

int InputValidator::findPosOfNthOccurrence(int occurence, string str, char to_search){
    
    int tempOccur = 0;

    for(int i = 0; i < str.length(); i++){
        
        if(str.at(i) == to_search){
            
            tempOccur++;
            
            if(tempOccur == occurence){
                
                return i;
                
            }
            
        }
        
    }

    return -1;
    
}



string InputValidator::findSubStrFromRange(int begin, int end, string str, char to_search){
    
    string substr;
    int temp;
    
    temp = findPosOfNthOccurrence(begin, str, '"') + 1;
    
    substr = str.substr(temp,
                              findPosOfNthOccurrence(end, str, '"') - temp);
    
    return substr;
    
}


void InputValidator::displayMessage(string message){
    
    cout << endl;
    
    cout << message << endl;
    
    cout << endl;
    
}

void InputValidator::displayTitle(string titleName){
    
    cout << endl;
    
    cout << "==== ";
    
    cout << titleName;
    
    cout << " ====";
    
    cout << endl;
    
}


string InputValidator::toUpper(string str){
    
    for(int i = 0; i < str.length(); i++){

        if(str[i] >= 97 && str[i] <= 122){
            
            str[i] -= 32;
            
        }
        
    }
    
    return str;
    
}

string InputValidator::getStringInputToUpper(string message){
    
    string string = getStringInput(message);
    
    return toUpper(string);
    
}

bool InputValidator::hasNoSpecialChars(string input){
    
    for(int i = 0; i < input.length(); i++){
        
        if(!isWithinIntRange(input.at(i), 97, 122) && !isWithinIntRange(input.at(i), 65, 90)){
            
            return false;
            
        }
        
    }
    
    
    if(isEmpty(input)){
        
        return false;
        
    }
    
    return true;
}

string InputValidator::getStringInputToUpperWithNoSpecialChar(string message){
    
    string input;
    bool isValid = false;
    
    do{
        input = getStringInputToUpper(message);
        
        isValid = hasNoSpecialChars(input);
        
        if(!isValid){
            
            displayMessage("Please enter alphabetical letters only!");
        }
        
        
    }while(!isValid);
    
    
    return input;
    
}

string InputValidator::getStringInputWithNoSpecialChar(string message){
    
    string input;
    bool isValid = false;
        
    do{
        input = getStringInput(message);
            
        isValid = hasNoSpecialChars(input);
            
        if(!isValid){
                
            displayMessage("Please enter alphabetical letters only!");
        }
            
            
    }while(!isValid);
        
        
    return input;
    
}


bool InputValidator::isEmpty(string input){
    
    if(input == ""){
        
        return true;
        
    }
    
    return false;
    
}
