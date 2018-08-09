//
//  rec08.cpp
//  Lab 8
//
//  Created by Cindy Lee on 10/27/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  Purpose: Implementing the Rational class and overloading operators
//  to use with Rational objects 

/*
 testRational.cpp
 CS1124
 Implement the class Rational, so that the following program works.
 */

#include "Rational.h"
#include <iostream>
#include <string>
using namespace std;
using namespace CS2124;


int main() {
    Rational a, b;
    cout << "Input two rational numbers.\n";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    Rational one = 1;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;    // Implement as member
    cout << "a = " << a << endl;
    // Implement as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;
    // How does this work?
    cout << "1 == one: " << boolalpha << (1 == one) << endl;
    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;

    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;

    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;

    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;

    // Even though the above example, (a++ ++), compiled, the
    // following shouldn't.
    // cout << "a-- -- = " << (a-- --) << endl;
    // cout << "a = " << a << endl;


    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    }
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    }
    
    Rational c (2, 5);
    Rational d (12, 8);
    cout << c << " < " << d << " : " << (c < d) << endl;
    cout << c << " <= 1" <<  " : " << (c <= 1) << endl;
    cout << d << " < " << c << " : " << (d < c) << endl;
    cout << d << " > 1" <<  " : " << (d > 1) << endl;
    cout << d << " >= " << Rational (24, 16)
    << " : " << (d >= Rational (24, 16)) << endl ;
}

