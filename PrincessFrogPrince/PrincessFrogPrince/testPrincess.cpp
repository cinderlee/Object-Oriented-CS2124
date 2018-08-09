//
//  testPrincess.cpp
//  PrincessFrogPrince
//
//  Created by Cindy Lee on 10/18/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//

#include <iostream>
#include <string>
#include "Princess.hpp"
#include "FrogPrince.hpp"
using namespace std;
using namespace Fantasy;

int main() {
    Princess snowy ( "Snow White" ) ;
    snowy.display ();
    FrogPrince froggy ( "Froggy");
    froggy.display ();
    snowy.marries (froggy);
    snowy.display ();
}
