//
//  FrogPrince.cpp
//  PrincessFrogPrince
//
//  Created by Cindy Lee on 10/18/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//

// don't need to include string because stated in header file
#include "FrogPrince.hpp"
#include <iostream>
using namespace std;

namespace Fantasy {
    FrogPrince::FrogPrince (const string& name) : name (name) {}
    
    void FrogPrince::display () const {cout << "Frog: " << name << endl; }
    
    void FrogPrince::setSpouse ( Princess& betrothed) {
        spouse = &betrothed;
    }

}
