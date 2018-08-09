//
//  polynomial.cpp
//  Homework 8
//
//  Created by Cindy Lee on 11/25/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  Polynomial cpp file

#include "polynomial.h"
#include <vector>

using namespace std;

// constructor for Node struct
Node::Node (int num, Node* next) : num (num), next (next) {}

// default constructor
// default Polynomial is zero polynomial
Polynomial::Polynomial () {
    head = new Node (0);
    tail = head;
}

// constructor taking in a vector of coeffs
Polynomial::Polynomial (const vector <int>& coeffs) {
    head = new Node (coeffs [0]);
    tail = head;
    
    // shift nodes over to the right to create new head
    for (size_t index = 1; index < coeffs.size (); ++index) {
        head = new Node (coeffs [index], head);
        degree += 1;
    }
    
    // delete extra 0s
    deleteZero ();
}

// copy constructor
Polynomial::Polynomial (const Polynomial& other) {
    
    // copy head
    head = new Node ( other.head -> num );
    tail = head;
    Node* otherPlace = other.head -> next;;
    
    // use tail to append new values to end of list
    while (otherPlace) {
        tail -> next = new Node (otherPlace -> num);
        tail = tail -> next;
        otherPlace = otherPlace -> next;
    }
    
    // copy degree
    degree = other.degree;
}

// destructor
Polynomial::~Polynomial () {
    
    // delete head each time until end
    while (head) {
        Node* nextItem = head;
        head = head -> next;
        delete nextItem;
    }
}

// overloading output operator
ostream& operator<< (ostream& os, const Polynomial& poly) {
    // create a Node place
    Node* place = poly.head;
    
    // call on helper function
    outputHelper (os, place, 0);
    
    return os;
}

// overloading ==
bool operator== (const Polynomial& lhs, const Polynomial& rhs) {
    
    // if degrees are different
    if (lhs.degree != rhs.degree) {
        return false;
    }
    
    Node* place = lhs.head;
    Node* otherPlace = rhs.head;
    
    // check if each coeff is the same
    while (place && otherPlace) {
        
        // return false if diff coeffs
        if (place -> num != otherPlace -> num) {
            return false;
        }
        
        // else, continue through list
        place = place -> next;
        otherPlace = otherPlace -> next;
    }
    return true;
}

// assignment operator
Polynomial& Polynomial::operator= (const Polynomial& rhs) {
    
    // check for self-assignment
    if (this != &rhs) {
        
        // delete current Polynomial
        while (head) {
            Node* nextItem = head;
            head = head -> next;
            delete nextItem;
        }
        
        // copy rhs to Polynomial
        head = new Node ( rhs.head -> num);
        tail = head;
        Node* rhsPlace = rhs.head;
        
        // copy rhs' coefficients to end of tail
        // tail becomes the next node after
        while (rhsPlace -> next) {
            tail -> next = new Node (rhsPlace -> next -> num);
            tail = tail -> next;
            rhsPlace = rhsPlace -> next;
        }
        
        // adjust degree
        degree = rhs.degree;
    }
    return *this;
}

// overloading += operator
Polynomial& Polynomial::operator+= (const Polynomial& rhs){
    Node* place = head;
    Node* otherPlace = rhs.head;
    
    // add coeffs where they have same degree
    while (place && otherPlace) {
        if (place) {
            place -> num += otherPlace -> num;
        }
        place = place -> next;
        otherPlace = otherPlace -> next;
    }
    
    // if rhs has more degrees
    while (otherPlace) {
        
        // use tail to add the remaining coeffs of rhs
        tail -> next = new Node (otherPlace -> num);
        tail = tail -> next;
        otherPlace = otherPlace -> next;
    }
    
    // adjust degree if adding two polynomials of
    // different degrees
    if (rhs.degree > degree) {
        degree = rhs.degree;
    }
    
    // check for hanging 0s
    deleteZero();
    return *this;
}

// deletes extra 0s
void Polynomial::deleteZero () {
    
    // if tail = 0 but polynomial is not zero polynomial
    while (head != tail && tail -> num == 0) {
        Node* newTail = head;
        
        // use newTail to find node before tail
        while (newTail) {
            
            // make tail be newTail
            if (newTail -> next == tail) {
                Node* oldTail = tail;
                tail = newTail;
                
                // delete old tail
                delete oldTail;
                tail -> next = nullptr;
                
                // change degree
                degree--;
                break;
            }
            
            // move to next node if not before tail
            newTail = newTail -> next;
        }
    }
}

// evaluates a polynomial given x
int Polynomial::evaluate (int x) const {
    
    int total = 0;
    Node* place = head;
    int power = 1;
    
    // for each node
    while (place) {
        
        // add product of power and coeff
        total += place -> num * power;
        
        // multiply power by x
        power *= x;
        place = place -> next;
    }
    return total;
}

// output helper function
void outputHelper (ostream& os, Node* place, int degree) {
    // if current Node has a next
    if (place -> next) {
        
        // recursive call on next Node
        outputHelper (os, place -> next, degree+1);
        
        // if value of Node is negative
        if (place -> num < 0) {
            
            // use subtraction operator
            os << " - ";
            if (place -> num != -1) {
                os << (-1 * place -> num);
            }
            
            // if -1 is a constant
            else {
                if (degree == 0) {
                    os << "1";
                }
            }
        }
        
        // if value of Node is positive
        else if (place -> num > 0) {
            
            // use addition operator
            os << " + ";
            if (place -> num != 1) {
                os << place -> num;
            }
            
            // if 1 is a constant
            else {
                if (degree == 0) {
                    os << "1";
                }
            }
        }
        
        // if degree is 1
        if (place -> num != 0 && degree == 1) {
            os << "x";
        }
        
        // if degree is greater than 1
        else if (place -> num != 0 && degree > 1) {
            os << "x^" << degree;
        }
    }
    
    // if tail (largest degree)
    else {
        
        // if only a constant
        // includes case for zero polynomial
        if (degree == 0) {
            os << place -> num;
        }
        
        // else
        else {
            // if coefficient is 1
            if (place -> num == 1) {
                os << "x";
            }
            // if coefficient is -1
            else if (place -> num == -1) {
                os << "-x";
            }
            // if other coefficient value
            else {
                os << place -> num << "x";
            }
        
            // if degree is greater than 1
            if (degree > 1) {
                os << "^" << degree;
            }
        }
    }
}

// overloading + operator
Polynomial operator+ (const Polynomial& lhs, const Polynomial& rhs) {
    
    // create copy of lhs
    Polynomial copy (lhs);
    
    // add to copy using +=
    copy += rhs;
    return copy;
}

// overloading !=
bool operator!= (const Polynomial& lhs, const Polynomial& rhs) {
    return ! (lhs == rhs);
}
