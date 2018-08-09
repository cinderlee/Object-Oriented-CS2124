//
//  polynomial.h
//  Homework 8
//
//  Created by Cindy Lee on 11/25/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  Polynomial header file

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdio.h>
#include <vector>
#include <iostream>

// Node struct
struct Node {
    Node (int num = 0, Node* next = nullptr);
    int num;
    Node* next;
};

class Polynomial {
public:
    // default constructor
    Polynomial ();
    
    // constructor takes in a vector of coeff
    Polynomial (const std::vector <int>& coeffs);
    
    // copy constructor
    Polynomial (const Polynomial& other);
    
    // destructor
    ~Polynomial();
    
    // assignment operator
    Polynomial& operator= (const Polynomial& rhs);
    
    // overloading += operator
    Polynomial& operator+= (const Polynomial& rhs);
    
    // evaluates a polynomial given x
    int evaluate (int x) const;
    
private:
    // overloading output operator
    friend std::ostream& operator<< (std::ostream& os, const Polynomial& poly);
    
    // overloading == operator
    friend bool operator== (const Polynomial& lhs, const Polynomial& rhs);
    
    // deleting extra 0s
    void deleteZero ();
    
    Node* head = nullptr;
    Node* tail = nullptr;
    int degree = 0;
};

// output helper function
void outputHelper (std::ostream& os, Node* place, int degree);

// overloading + operator
Polynomial operator+ (const Polynomial& lhs, const Polynomial& rhs);

// overloading != operator
bool operator!= (const Polynomial& lhs, const Polynomial& rhs);

#endif /* POLYNOMIAL_H */
