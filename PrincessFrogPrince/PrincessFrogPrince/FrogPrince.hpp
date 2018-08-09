//
//  FrogPrince.hpp
//  PrincessFrogPrince
//
//  Created by Cindy Lee on 10/18/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//

#ifndef FROGPRINCE_HPP
#define FROGPRINCE_HPP

#include <stdio.h>

#include <string>

namespace Fantasy {

    class Princess;
    
    class FrogPrince {
    public:
        //FrogPrince (const string& name) : name (name) {}
        FrogPrince (const std::string& name);
        
        // void display () const {cout << “Frog: “ << name << endl; }
        void display () const;
        
        //void marries (FrogPrince& betrothed) {
        //spouse = &betrothed;
        //betrothed.spouse = this;
        //betrothed.marries (*this);
        
        
        // maybe leave as pass by reference once if betrothed - divorced
        // can’t do const unless const pointer
        //void setSpouse ( Princess& betrothed) { spouse = &betrothed; }
        void setSpouse ( Princess& betrothed) ;
        
    private:
        Princess* spouse;
        std::string name;
    };

}
    
#endif /* FROGPRINCE_HPP */
