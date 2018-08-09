//
//  rec12.cpp
//  Lab 12
//
//  Created by Cindy Lee on 12/1/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Purpose: Implementing a doubly linked list and iterator

//  Doubly linked list
//  Test code

#include <cstdlib>
#include <iostream>
using namespace std;

class List {
    friend ostream& operator<< (ostream& os, const List& aList) {
        Node* place = aList. header -> next;
        while (place != aList.trailer) {
            os << place -> data << " ";
            place = place -> next;
        }
        return os;
    }
    struct Node {
        Node (int data = 0, Node* before = nullptr, Node* after = nullptr) :
        data (data), next (after), prior (before) {}
        int data ;
        Node* prior;
        Node* next;
    };
public:
        
    class Iterator {
    public:
        friend class List;
        
        Iterator (Node* place = nullptr) : field (place) {}
        
        Iterator& operator++ () {
            field = field -> next;
            return *this;
        }
        Iterator& operator-- () {
            field = field -> prior;
            return *this;
        }
        int operator* () const {
            return field -> data;
        }
        
    private:
        Node* field;
        friend bool operator== (const Iterator& lhs, const Iterator& rhs) {
            return lhs.field == rhs.field;
        }
    };

    List () {
        header = new Node (0);
        trailer = new Node (0, header);
        header -> next = trailer;
    }
    
    List (const List& other) {
        header = new Node (0);
        trailer = new Node (0, header);
        header -> next = trailer;
        Node* place = other.header -> next;
        while (place != other.trailer) {
            Node* newNode = new Node (place -> data, trailer -> prior, trailer);
            trailer -> prior -> next = newNode;
            trailer -> prior = newNode;
            place = place -> next;
        }
        theSize = other.theSize;
    }
    
    ~List () {
//        while (header) {
//            Node* place = header;
//            header = header -> next;
//            delete place;
//        }
        clear ();
        delete header;
        delete trailer;
    }
    
    void push_back (int data) {
        Node* newNode = new Node (data, trailer -> prior, trailer);
        trailer -> prior -> next = newNode;
        trailer -> prior = newNode;
        theSize++;
    }
    
    void pop_back () {
        if (theSize != 0) {
            Node* place = trailer -> prior;
            trailer -> prior = place -> prior;
            place -> prior-> next = trailer;
            delete place;
            theSize--;
        }
    }
    
    void push_front (int data) {
        Node* newNode = new Node (data, header, header -> next);
        header -> next -> prior = newNode;
        header -> next = newNode;
        theSize++;
    }
    
    void pop_front () {
        if (theSize != 0) {
            Node* place = header -> next;
            place -> next -> prior = header;
            header -> next = place -> next;
            delete place;
            theSize--;
        }
    }
    
    int front () const {
        if (theSize != 0 ) {
            return header -> next -> data;
        }
        return 0;
    }
    
    int back () const {
        if (theSize != 0 ) {
            return trailer -> prior -> data;
        }
        return 0;
    }
    
    int size () const {
        return theSize;
    }
    
    void clear () {
        Node* place = header -> next;
        while (place != trailer) {
            Node* afterPlace = place -> next;
            delete place;
            place = afterPlace;
        }
        header -> next = trailer;
        trailer -> prior = header;
        theSize = 0;
    }
    
    int operator[] (size_t index) const {
        size_t place = 0;
        Node* placer = header -> next;
        while (placer != trailer) {
            if (place == index) {
                return placer -> data;
            }
            place++;
            placer = placer -> next;
        }
        return 0;
    }
    
    int& operator[] (size_t index) {
        size_t place = 0;
        Node* placer = header -> next;
        while (placer != trailer) {
            if (place == index) {
                return placer -> data;
            }
            place++;
            placer = placer -> next;
        }
        return trailer -> data;
    }
    
    Iterator begin () const {
        return Iterator (header -> next);
    }
    
    Iterator end () const {
        return Iterator (trailer);
    }
    
    Iterator insert (Iterator place, int data) {
        Node* newNode = new Node (data, place.field -> prior, place.field);
        place.field -> prior = newNode;
        newNode -> prior -> next = newNode;
        theSize++;
        return Iterator (newNode);
    }
    
    Iterator erase (Iterator place) {
        place.field -> prior -> next = place.field -> next;
        place.field -> next -> prior = place.field -> prior;
        Iterator placer = Iterator (place.field -> next);
        delete place.field;
        theSize--;
        return placer;
    }
    
    List& operator= (const List& rhs){
        if (this != &rhs) {
            clear ();
            Node* place = rhs.header -> next;
            while (place != rhs.trailer) {
                Node* newNode = new Node (place -> data, trailer -> prior, trailer);
                trailer -> prior -> next = newNode;
                trailer -> prior = newNode;
                place = place -> next;
            }
            theSize = rhs.theSize;
        }
        return *this;
    }
    
private:
    Node* header = nullptr;
    Node* trailer = nullptr;
    int theSize = 0;
};

bool operator!= (const List::Iterator& lhs, const List::Iterator& rhs) {
    return ! (lhs == rhs) ;
}

void printListInfo(List& myList) {
    cout << "size: " << myList.size()
    << ", front: " << myList.front()
    << ", back(): " << myList.back()
    << ", list: " << myList << endl;
}

// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << endl;
    cout << "Leaving doNothing\n";
}

int main() {
    
    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";
    
    // Task2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    cout << "===================\n";

    // Task3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";

    // Task4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;

    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    for (List::Iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";

    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
    << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    cout << "===================\n";

    // Task 8
    cout << "\n------Task Eight------\n";
    cout << "Copy control\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Calling doNothing(myList)\n";
    doNothing(myList);
    cout << "Back from doNothing(myList)\n";
    printListInfo(myList);

    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    List listTwo;
    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    printListInfo(listTwo);
    cout << "listTwo = myList\n";
    listTwo = myList;
    cout << "myList: ";
    printListInfo(myList);
    cout << "listTwo: ";
    printListInfo(listTwo);
    cout << "===================\n";
}
