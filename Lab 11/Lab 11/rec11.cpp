//
//  rec11.cpp
//  Lab 11
//
//  Created by Cindy Lee on 11/17/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Purpose: Implementing Linked Lists and checking for sublists
//  and splicing linked lists

#include <iostream>
using namespace std;

struct Node {
    Node (int data = 0, Node* next = nullptr) :
    data (data), next (next){}
    int data;
    Node* next;
};

void splice_into (Node* prior, Node* other) {
    if (prior != nullptr) {
        Node* otherPointer = other;
        while (otherPointer -> next) {
            otherPointer = otherPointer -> next;
        }
        otherPointer -> next = prior -> next;
        prior -> next = other;
    }
}

void displayList (const Node* head) {
    const Node* place = head;
    while (place) {
        cout << place -> data << " " ;
        place = place -> next;
    }
    //cout << endl;
}

// checks if at placer if it contains sublist
bool isSubHelper (const Node* placer, const Node* sublist) {
    const Node* place = placer;
    const Node* subPlace= sublist;
    while (subPlace) {
        if (place == nullptr || place -> data != subPlace -> data ) {
            return false;
        }
        subPlace = subPlace -> next;
        place = place -> next;
    }
    return true;
}

const Node* isSubList (const Node* head, const Node* sublist) {
    if (head && sublist) {
        const Node* place = head;
        const Node* subPlace= sublist;
        while (place) {
            //check if place is equal
            if (place -> data == subPlace -> data) {
                const Node* newPlace = place -> next;
                // if sublist exists
                if (isSubHelper (place, subPlace)){
                    
                    // check for existence of other locations of sublist
                    const Node* list = isSubList (newPlace, subPlace);
                    if (list != nullptr) {
                        displayList (list);
                        cout << endl;
                    }
                    
                    //return place
                    return place;
                }
            }
            place = place -> next;
                // if only place equal to first of sublist
                // but not sublist
//                else {
//                    place = place -> next;
//                }
//            }
//
//            // if place is not equal to first of sublist
//            else {
//                place = place -> next;
//            }
        }
    }
    return nullptr;
}

void displayResult (const Node* head) {
    if (head) {
        displayList (head);
    }
    else {
        cout << "Failed to Match";
    }
}

int main() {
    Node* myList = new Node (5, new Node (7, new Node (9, new Node (1))));
    Node* secondList = new Node (6, new Node (3, new Node (2)));
    cout << "Part One" << endl;
    cout << "L1: " ;
    displayList (myList);
    cout << endl;
    
    cout << "L2: " ;
    displayList (secondList);
    cout << endl;
    cout << "Target: ";
    displayList (myList -> next);
    cout << endl;
    cout << "Splicing L2 at target in L1" << endl;
    splice_into (myList -> next, secondList);
    cout << "L1: " ;
    displayList (myList);
    cout << endl;
    cout << "L2: " ;
    displayList (secondList);
    cout << endl;
    cout << endl;
    
    cout << "======" << endl << endl;
    cout << "Part Two" << endl;
    cout << "Target: ";
    Node* third = nullptr;
    third = new Node (1, new Node (2, new Node (3, new Node
    (2, new Node (3, new Node (2, new Node (4, new Node (5, new Node (6))))))))) ;
    displayList(third);
    cout << endl << endl;
    Node* sublist = new Node (1);
    cout << "Attempt Match: ";
    displayList (sublist);
    cout << endl;
    //const Node* result = isSubList (third, sublist);
    displayResult(isSubList (third, sublist));
    cout << endl;
    cout << endl;
    
    Node* sublistTwo = new Node (3, new Node (9));
    cout << "Attempt Match: ";
    displayList (sublistTwo);
    cout << endl;
    displayResult (isSubList (third, sublistTwo));
    cout << endl;
    cout << endl;
    
    Node* subTwoCopy = new Node (2, new Node (3));
    cout << "Attempt Match: ";
    displayList (subTwoCopy);
    cout << endl;
    displayResult (isSubList (third, subTwoCopy));
    cout << endl;
    cout << endl;
    
    Node* subThree = new Node (2, new Node (4, new Node (5, new Node (6))));
    cout << "Attempt Match: ";
    displayList (subThree);
    cout << endl;
    displayResult (isSubList (third, subThree));
    cout << endl;
    cout << endl;
    
    Node* subFour = new Node (2, new Node (3, new Node (2, new Node (4))));
    cout << "Attempt Match: ";
    displayList (subFour);
    cout << endl;
    displayResult (isSubList (third, subFour));
    cout << endl;
    cout << endl;
    
    Node* subFive = new Node (5, new Node (6, new Node (7)));
    cout << "Attempt Match: ";
    displayList (subFive);
    cout << endl;
    displayResult (isSubList (third, subFive));
    cout << endl;
}
