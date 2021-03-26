//
//  main.cpp
//  Phase 1  - Practical - ElementalApp
//
//  Created by RJ Lacanlale on 11/28/20.
//  Copyright © 2020 RJ Lacanlale. All rights reserved.
//

#include "ElementalApp.h"

int main() {

    ElementalApp* app = new ElementalApp;
    
    app->start();
    
    delete app;
}
