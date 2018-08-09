//
//  Princess.cpp
//  PrincessFrogPrince
//
//  Created by Cindy Lee on 10/18/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//

#include "Princess.hpp"
#include "FrogPrince.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace Fantasy {

    void Princess::marries (FrogPrince& betrothed) {
        spouse = &betrothed;
        betrothed.setSpouse (*this);
    }
    
    void Princess::display () const {cout << "Princess: " << name << endl; }

    Princess::Princess (const string& name) : name (name) {}
    
}
