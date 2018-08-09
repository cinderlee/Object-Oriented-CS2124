//
//  Rational.h
//  Lab 8
//
//  Created by Cindy Lee on 10/27/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  Header file of Rational class 

#ifndef Rational_H
#define Rational_H

#include <stdio.h>
#include <string>
#include <iostream>

namespace CS2124 {
    class Rational {
        friend std::istream& operator>> (std::istream& is, Rational& rhs);
        friend std::ostream& operator<< (std::ostream& os, const Rational& rhs);
        friend bool operator== (const Rational& lhs, const Rational& rhs);
        friend bool operator< (const Rational& lhs, const Rational& rhs);
    private:
        int numerator;
        int denominator;
        void normalize ( );
    public:
        Rational ();
        Rational (int number, int denominator = 1);
        Rational& operator+= (const Rational& rhs);
        //bool operator== (const Rational& rhs) const;
        Rational& operator++  ();
        Rational operator++ (int);
        explicit operator bool () const ;
        //bool operator< (const Rational& rhs) const;
    };
    
    Rational operator+ (const Rational& lhs, const Rational& rhs);
    //bool operator== (const Rational& lhs, const Rational& rhs);
    bool operator!= (const Rational& lhs, const Rational& rhs);
    Rational& operator-- (Rational& lhs);
    Rational operator-- (Rational& lhs, int);
    
    bool operator<= (const Rational& lhs, const Rational& rhs);
    bool operator> (const Rational& lhs, const Rational& rhs);
    bool operator>= (const Rational& lhs, const Rational& rhs);
    
    int greatestCommonDivisor(int x, int y);
}



#endif /* Rational_H */
