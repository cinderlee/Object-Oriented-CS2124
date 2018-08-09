//
//  Princess.hpp
//  PrincessFrogPrince
//
//  Created by Cindy Lee on 10/18/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//

#ifndef PRINCESS_H
#define PRINCESS_H
#include <stdio.h>

// do not include using namespace std

#include <string>

namespace Fantasy {
    
    class FrogPrince;
    
    class Princess {
    public:
        // initialization list is an implementation, not a distinguisher, no impact
        //Princess (const string& name) : name (name) {}
        Princess (const std::string& name) ;
        
        // void display () const {cout << “Princess: “ << name << endl; }
        void display () const;
        
        // problem here is that we don’t know if FrogPrince has setSpouse
        // forward declaration doesn’t say
        // void marries (FrogPrince& betrothed) {
        //    spouse = &betrothed;
        //    //betrothed.spouse = this;
        //    betrothed.setSpouse (*this);
        void marries (FrogPrince& betrothed);
        
    private:
        //FrogPrince spouse
        FrogPrince* spouse;
        std::string name;
    };
    
}

#endif /* PRINCESS_H */
