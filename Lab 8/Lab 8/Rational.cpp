//
//  Rational.cpp
//  Lab 8
//
//  Created by Cindy Lee on 10/27/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  cpp file of Rational class  

#include "Rational.h"
#include <string>
#include <iostream>

using namespace std;
namespace CS2124 {
    istream& operator>> (istream& is, Rational& rhs) {
        int num;
        int denum;
        char slash;
        is >> num >> slash >> denum;
        rhs.numerator = num;
        rhs.denominator = denum;
        rhs.normalize ();
        return is;
    }
    
    ostream& operator<< (ostream& os, const Rational& rhs) {
        os << rhs.numerator << "/" << rhs.denominator;
        return os;
    }
    
    Rational::Rational () : numerator (0), denominator (0) {}
    
    Rational::Rational (int num, int denum):
    numerator (num), denominator (denum) {
        normalize ();
    }
    
    void Rational::normalize () {
        int num = greatestCommonDivisor(numerator, denominator);
        numerator /= num;
        denominator /= num;
        
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }
    
    Rational& Rational::operator+= (const Rational& rhs) {
        numerator = numerator * rhs.denominator + rhs.numerator * denominator;
        denominator = denominator * rhs.denominator;
        //int gcd = greatestCommonDivisor(numerator, denominator);
        normalize ();
        return *this;
    }
        
//    bool Rational::operator== (const Rational& rhs) const {
//        if (numerator == rhs.numerator && denominator == rhs.denominator) {
//            return true;
//        }
//        return false;
//    }
    
    Rational& Rational::operator++  () {
        Rational addOne = Rational (1);
        *this += addOne;
        return *this;
    }
    
    Rational Rational::operator++  (int) {
        Rational copy (*this);
        Rational addOne = Rational (1);
        *this += addOne;
        return copy;
    }
    
    Rational::operator bool () const {
        return !(numerator == 0 );
    }
    
    bool operator< (const Rational& lhs, const Rational& rhs) {
        int eval = lhs.numerator * rhs.denominator;
        int evalOfOther = rhs.numerator * lhs.denominator;
        return (eval < evalOfOther);
    }
    
    Rational operator+ (const Rational& lhs, const Rational& rhs) {
        Rational copy (lhs);
        copy += rhs;
        return copy;
    }
    
    bool operator== (const Rational& lhs, const Rational& rhs) {
        return (lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator); 
//        Rational constant = Rational (number);
//        if ( constant == rhs ) {
//            return true;
//        }
//        return false;
    }
    
    bool operator!= (const Rational& lhs, const Rational& rhs) {
        if ( lhs == rhs ) {
            return false;
        }
        return true;
    }
    
    Rational& operator-- (Rational& lhs) {
        Rational subtract = Rational (-1);
        lhs += subtract;
        return lhs;
    }
    
    Rational operator-- (Rational& lhs, int) {
        Rational copy (lhs);
        Rational subtract = Rational (-1);
        lhs += subtract;
        return copy;
    }
    
    bool operator<= (const Rational& lhs, const Rational& rhs) {
        return (lhs < rhs || lhs == rhs);
    }
    
    bool operator> (const Rational& lhs, const Rational& rhs) {
        return !(lhs <= rhs);
    }
    
    bool operator>= (const Rational& lhs, const Rational& rhs) {
        return  !(lhs < rhs);
    }
    
    int greatestCommonDivisor(int x, int y) {
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
    
}
