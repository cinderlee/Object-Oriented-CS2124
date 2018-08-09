//
//  rec04.cpp
//  Lab 4
//
//  Created by Cindy Lee on 9/29/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Purpose: Introduction to pointers Lab

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    //task 2
    int x;
    //at breakpoint x has garbage 0
    x = 10;
    
    // task 4 - step over
    //x now is 10
    
    //task 6
    //&x =0x7fff5fbff010;
    cout << "x = " << x << endl;
    
    
    //task 8
    int* p;
    p = &x;
    
    
    
    
    //task 9
    //p = 0x7fff5fbff010;
    //error from incompatible type
    
    
    //task 10
    cout << "p = " << p << endl;
    //expansion -> *p = (int) 10
    
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p contains " << *p << endl;
    
    
    
    //task 11
    *p = -2763;
    // p now points to -2763
    // x now equal to -2763
    cout << "p points to where " << *p << " is      stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "x now contains " << x << endl;
    
    
    
    //task 12
    int y(13);
    cout << "y contains " << y << endl;
    p = &y;
    cout << "p now points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    *p = 980;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "y now contains " << y << endl;
    //y = *p = 980
    
    
    
    //task 13
    int* q;
    q = p;
    cout << "q points to where " << *q << " is stored\n";
    cout << "*q contains " << *q << endl;
    // points to where 980 is stored
    
    
    
    //task 14
    double d(33.44);
    double* pD(&d);
    *pD = *p;
    *pD = 73.2343;
    *p  = *pD;
    *q  = *p;
    //last two lines result in error
    //pD  = p;
    //p   = pD;
    
    //task 15
    int joe( 24 );
    const int sal( 19 );
    int*  pI;
//      pI = &joe;
//     *pI = 234;
//    //assigning a const int to int*
//      pI = &sal;
//     *pI = 7623;
//
//    const int* pcI;
//      pcI = &joe;
//    //can't change const int* because read-only variable
//     *pcI = 234;
//      pcI = &sal;
//     *pcI = 7623;
//
//    //const type int*
//    int* const cpI;
//    //redefined
//    int* const cpI(&joe);
//    int* const cpI(&sal);
//      cpI = &joe;
//     *cpI = 234;
//      cpI = &sal;
//     *cpI = 7623;
//
//    //const type of a const int
//    const int* const cpcI;
//    //redefined
//    const int* const cpcI(&joe);
//    const int* const cpcI(&sal);
//      cpcI = &joe;  // *cpcI = 234;
//      cpcI = &sal;
//     *cpcI = 7623;
    
    //task 16
    struct Complex {
        double real;
        double img;
    };
    
    Complex c = {11.23,45.67};
    Complex* pC(&c);
    
    //checking real and img
    cout << c.real << endl;
    cout << c.img << endl;
    
    //cout << "real: " << *pC.real << "\nimaginary: " << *pC.img << endl;
    cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img << endl;
    
    cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;
    
    //task 17
    class PlainOldClass {
    public:
        PlainOldClass() : x(-72) {}
        int getX() const { return x; }
        //void setX( int val )  { x = val; }
        //void setX( int x )  { x = x; } // HMMMM??? -> sets x to -72 instead
        //sets parameter to itself
        void setX( int x )  { this->x = x; }
    private:
        int x;
    };
    
    PlainOldClass poc;
    PlainOldClass* ppoc( &poc );
    cout << ppoc->getX() << endl;
    ppoc->setX( 2837 );
    cout << ppoc->getX() << endl;
    
    //task 19
    int* pDyn = new int(3); // p points to an int initialized to 3 on the heap
    *pDyn = 17;
    
    cout << "The " << *pDyn
    << " is stored at address " << pDyn
    << " which is in the heap\n";
    
    //task 20
    cout << pDyn << endl;
    delete pDyn;
    cout << pDyn << endl;
    
    cout << "The 17 might STILL be stored at address " << pDyn<< " even though we deleted pDyn\n";
    cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";
    //still is 17 for *pDyn
    
    //task 21
    pDyn = nullptr;
    double* pDouble( nullptr );
    
    //task 22
    //cout << "Can we dereference nullptr?  " << *pDyn << endl;
    //cout << "Can we dereference nullptr?  " << *pDouble << endl;
    
    //task 24
    double* pTest = new double( 12 );
    delete pTest;
    pTest = nullptr;
    delete pTest; // safe

    //task 25
    short* pShrt = new short( 5 );
    delete pShrt;
    //delete pShrt;
    // error for object 0x100528bf0: pointer being freed was not allocated
    
    
    //task 26
    //long jumper( 12238743 );
    //delete jumper; < - Error: can't delete long
    //long* ptrTolong( &jumper );
    //delete ptrTolong;
    //Complex cmplx;
    //delete cmplx;
    //can't delete cmplx
    
    
    
    //task 27
    vector<Complex*> complV; // can hold pointers to Complex objects
    Complex* tmpPCmplx;      // space for a Complex pointer
    for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
        tmpPCmplx = new Complex; // create a new Complex object on the heap
        tmpPCmplx->real = ndx;   // set real and img to be the
        tmpPCmplx->img  = ndx;   // value of the current ndx
        complV.push_back( tmpPCmplx ); // store the ADDRESS of the object in a vector or pointer to Complex
    }
    // display the objects using the pointers stored in the vector
    for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
        cout << complV[ ndx ]->real << endl;
        cout << complV[ ndx ]->img  << endl;
    }
    // release the heap space pointed at by the pointers in the vector
    for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
        delete complV[ ndx ];
    }
    // clear the vector
    complV.clear();
    
    
    
    
    //task 28
    class Colour {
    public:
        Colour( const string& name, unsigned r, unsigned g, unsigned b )
        : name(name), r(r), g(g), b(b) {}
        void display() const {
            cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
        }
    private:
        string   name;    // what we call this colour
        unsigned r, g, b; // red/green/blue values for displaying
    };
    
    vector< Colour* > colours;
    string inputName;
    unsigned inputR, inputG, inputB;
    
    // fill vector with Colours from the file
    // this could be from an actual file but here we are using the keyboard instead of a file (so we don't have to create an actual file)
     // do you remember the keystroke combination to indicate "end of file" at the keyboard?
     // somehow the while's test has to fail - from keyboard input
     while ( cin >> inputName >> inputR >> inputG >> inputB ) {
         colours.push_back( new Colour(inputName, inputR, inputG, inputB) );
     }
     
     // display all the Colours in the vector:
     for ( size_t ndx = 0; ndx < colours.size(); ++ndx ) {
         colours[ndx]->display();
         cout << endl;
     }
    
//    outputs
//    Black (RBG: 255,255,255)
//    White (RBG: 0,0,0)
//    Azure (RBG: 10,110,237)
//    DeepPurple (RBG: 240,72,261)
    
    
    
    
    //task 29
    class SpeakerSystem {
    public:
        void vibrateSpeakerCones( unsigned signal ) const {
            
            cout << "Playing: " << signal << "Hz sound..." << endl;
            cout << "Buzz, buzzy, buzzer, bzap!!!\n";
        }
    };
    
    class Amplifier {
    public:
        void attachSpeakers( const SpeakerSystem& spkrs )
        {
            if( attachedSpeakers )
                cout << "already have speakers attached!\n";
            else
                attachedSpeakers = &spkrs;
        }
        void detachSpeakers()
        { attachedSpeakers = nullptr; }
        // should there be an "error" message if not attached?
        void playMusic( ) const {
            if( attachedSpeakers )
                attachedSpeakers -> vibrateSpeakerCones( 440 );
            else
                cout << "No speakers attached\n";
        }
    private:
        const SpeakerSystem* attachedSpeakers = nullptr;
        //changes this to const because you want the amp to be connected
        //to only one type of speaker and once connected, to not change the connection
        //const also use to not tamper with the type of speaker amp is connected to
    };
    
    SpeakerSystem speak;
    SpeakerSystem speak1;
    SpeakerSystem speak2;

    Amplifier amp;
    Amplifier amp1;
    Amplifier amp2;
    speak.vibrateSpeakerCones(90);
    amp1.playMusic();
    amp1.attachSpeakers(speak1);
    amp1.attachSpeakers(speak2);
    //already has speakers attached
    //this    const Amplifier *    0x7fff5fbfef78    0x00007fff5fbfef78
    amp1.playMusic();
    
    
    
    
    //task 30
    class Person {
    public:
        Person( const string& name ) : name(name) {}
        bool movesInWith( Person& newRoomate ) {
            //add checking
            if (&newRoomate == this){
                return false;
            }
            if (this -> roomie == nullptr && newRoomate.roomie == nullptr){
                roomie = &newRoomate;        // now I have a new roomie
                newRoomate.roomie = this;    // and now they do too
                return true;
            }
            else {
                return false;
            }
        }
        
        //added movesOut function
        bool movesOut () {
            if (roomie == nullptr) {
                return false;
            }
            (*roomie).roomie = nullptr;
            this -> roomie = nullptr;
            return true;
        }
        
        string getName() const { return name; }
        // Don't need to use getName() below, just there for you to use in debugging.
        string getRoomiesName() const { //return roomie->getName(); }
            //altered a bit to check
            if (roomie != nullptr) {
                return roomie -> getName ();
            }
            return "No roommate";
        }
    private:
        Person* roomie;
        string name;
    };
    
    // write code to model two people in this world
    Person joeBob("Joe Bob"), billyJane("Billy Jane");
    // now model these two becoming roommates
    joeBob.movesInWith( billyJane );
    // did this work out?
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
    
    joeBob.movesOut ();
    cout << billyJane.getRoomiesName() << endl;
    cout << joeBob.getRoomiesName () << endl;
    joeBob.movesOut ();
    
}
