//
//  rec10.cpp
//  Lab 10
//
//  Created by Cindy Lee on 11/10/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Purpose: Simulating Orchestra of Musicians

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Instrument{
public:
    virtual void makeSound () const = 0;
    virtual void normalPlay () const = 0;
};

void Instrument::makeSound () const {
    cout << "To make a sound...";
}

class Brass: public Instrument {
public:
    Brass (unsigned sizeB) : sizeB (sizeB) {}
    void makeSound () const {
        Instrument::makeSound ();
        cout << " blow on a mouthpiece of size " << sizeB << endl;
    }
private:
    unsigned sizeB;
};

class Trumpet: public Brass {
public:
    Trumpet (unsigned sizeB) : Brass (sizeB) {}
    void makeSound () const {
        Brass::makeSound ();
    }
    void normalPlay () const {
        cout << "Toot";
    }
};

class Trombone: public Brass {
public:
    Trombone (unsigned sizeB) : Brass (sizeB) {}
    void makeSound () const {
        Brass::makeSound ();
    }
    void normalPlay () const {
        cout << "Blat";
    }
};

class Flugelhorn: public Brass {
public:
    Flugelhorn (unsigned sizeB) : Brass (sizeB) {}
    void makeSound () const {
        Brass::makeSound ();
    }
};

class Bugle: public Brass {
public:
    Bugle (unsigned sizeB) : Brass (sizeB) {}
    void makeSound () const {
        Brass::makeSound ();
    }
};

class FrenchHorn: public Brass {
public:
    FrenchHorn (unsigned sizeB) : Brass (sizeB) {}
    void makeSound () const {
        Brass::makeSound ();
    }
};

class Euphonium: public Brass {
public:
    Euphonium (unsigned sizeB) : Brass (sizeB) {}
    void makeSound () const {
        Brass::makeSound ();
    }
};

class Tuba: public Brass {
public:
    Tuba (unsigned sizeB) : Brass (sizeB) {}
    void makeSound () const {
        Brass::makeSound ();
    }
};

class CorDeChasses: public Brass {
public:
    CorDeChasses (unsigned sizeB) : Brass (sizeB) {}
    void makeSound () const {
        Brass::makeSound ();
    }
};

class Sackbutt: public Brass {
public:
    Sackbutt (unsigned sizeB) : Brass (sizeB) {}
    void makeSound () const {
        Brass::makeSound ();
    }
};

class Zink: public Brass {
public:
    Zink (unsigned sizeB) : Brass (sizeB) {}
    void makeSound () const {
        Brass::makeSound ();
    }
};

class Sousaphone: public Brass {
public:
    Sousaphone (unsigned sizeB) : Brass (sizeB) {}
    void makeSound () const {
        Brass::makeSound ();
    }
};

class String: public Instrument {
public:
    String (unsigned pitch) : pitch (pitch) {}
    void makeSound () const {
        Instrument::makeSound ();
        cout << " bow a string with pitch " << pitch << endl;
    }
private:
    unsigned pitch;
};

class Violin: public String {
public:
    Violin (unsigned pitch) : String (pitch) {}
    void makeSound () const {
        String::makeSound ();
    }
    void normalPlay () const {
        cout << "Screech";
    }
};

class Cello: public String {
public:
    Cello (unsigned pitch) : String (pitch) {}
    void makeSound () const {
        String::makeSound ();
    }
    void normalPlay () const {
        cout << "Squawk";
    }
};

class Viola: public String {
public:
    Viola (unsigned pitch) : String (pitch) {}
    void makeSound () const {
        String::makeSound ();
    }
};

class ContraViolin: public String {
public:
    ContraViolin (unsigned pitch) : String (pitch) {}
    void makeSound () const {
        String::makeSound ();
    }
};

class Guitar: public String {
public:
    Guitar (unsigned pitch) : String (pitch) {}
    void makeSound () const {
        String::makeSound ();
    }
};

class Lute: public String {
public:
    Lute (unsigned pitch) : String (pitch) {}
    void makeSound () const {
        String::makeSound ();
    }
};


class Banjo: public String {
public:
    Banjo (unsigned pitch) : String (pitch) {}
    void makeSound () const {
        String::makeSound ();
    }
};

class Ukelele: public String {
public:
    Ukelele (unsigned pitch) : String (pitch) {}
    void makeSound () const {
        String::makeSound ();
    }
};

class Balalaika: public String {
public:
    Balalaika (unsigned pitch) : String (pitch) {}
    void makeSound () const {
        String::makeSound ();
    }
};

class Oud: public String {
public:
    Oud (unsigned pitch) : String (pitch) {}
    void makeSound () const {
        String::makeSound ();
    }
};

class Sitar: public String {
public:
    Sitar (unsigned pitch) : String (pitch) {}
    void makeSound () const {
        String::makeSound ();
    }
};

class Zither: public String {
public:
    Zither (unsigned pitch) : String (pitch) {}
    void makeSound () const {
        String::makeSound ();
    }
};

class Kora: public String {
public:
    Kora (unsigned pitch) : String (pitch) {}
    void makeSound () const {
        String::makeSound ();
    }
};

class Percussion: public Instrument {
public:
    void makeSound () const {
        Instrument::makeSound ();
        cout << " hit me!" << endl;
    }
};

class Drum: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
    void normalPlay () const {
        cout << "Boom";
    }
};

class Cymbal: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
    void normalPlay () const {
        cout << "Crash";
    }
};

class Tambour: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Tambourine: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class GrandeCasse: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Triangle: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Bongo: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Conga: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Timbale: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Castanets: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Macaras: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Guiro: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Xylophone: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class OrcBells: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Chimes: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Marimba: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Vibraphone: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Crotales: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Amgloken: public Percussion {
public:
    void makeSound () const {
        Percussion::makeSound ();
    }
};

class Wind: public Instrument {
public:
    void makeSound () const {
        Instrument::makeSound ();
        cout << " blow wind!" << endl;
    }
};

class Flute: public Wind {
public:
    void makeSound () const {
        Wind::makeSound();
    }
};

class Saxophone: public Wind {
public:
    void makeSound () const {
        Wind::makeSound();
    }
};

class Clarinet: public Wind {
public:
    void makeSound () const {
        Wind::makeSound();
    }
};

class Oboe: public Wind {
public:
    void makeSound () const {
        Wind::makeSound();
    }
};

class Bassoon: public Wind {
public:
    void makeSound () const {
        Wind::makeSound();
    }
};

class Shawm: public Wind {
public:
    void makeSound () const {
        Wind::makeSound();
    }
};

class CorAnglais: public Wind {
public:
    void makeSound () const {
        Wind::makeSound();
    }
};

class Krummhorn: public Wind {
public:
    void makeSound () const {
        Wind::makeSound();
    }
};

class Rackett: public Wind {
public:
    void makeSound () const {
        Wind::makeSound();
    }
};

class Musician {
public:
    Musician() : instr(nullptr) {}
    void acceptInstr(Instrument& i) { instr = &i; }
    Instrument* giveBackInstr() {
        Instrument* tmp(instr);
        instr = nullptr;
        return tmp;
    }
    void testPlay() const {
        if(instr)
            instr->makeSound();
        else
            cerr << "have no instr\n";
    }
    
    void normalPlay () const {
        if (instr) {
            instr -> normalPlay ();
        }
    }
private:
    Instrument* instr;
};

class MILL {
public:
    void dailyTestPlay () {
        for (size_t index = 0; index < inventory.size (); index++ ) {
            if (inventory [index] != nullptr) {
                inventory [index] -> makeSound();
            }
        }
    }
    void receiveInstr (Instrument& instr) {
        instr.makeSound ();
        for (size_t index = 0 ; index < inventory.size (); ++index) {
            if (inventory [index] == nullptr) {
                inventory[index] = &instr;
                return;
            }
        }
        inventory.push_back (&instr);
    }
    
    Instrument* loanOut () {
        for (size_t index = 0; index < inventory.size (); index++ ) {
            if (inventory [index] != nullptr) {
                Instrument* loan = (inventory[index]);
                inventory [index] = nullptr;
                return loan;
            }
        }
        return nullptr;
    }
    
private:
    vector <Instrument*> inventory;
};

class Orch {
public:
    void addPlayer (Musician& mus) {
        if (band.size () < 25) {
            band.push_back (&mus);
        }
    }
    
    void play (){
        for (size_t index = 0; index < band.size () ; ++index ) {
            band [index] -> normalPlay();
        }
        cout << "\n";
    }
    
private:
    vector <Musician*> band;
};

//// PART ONE
//int main() {
//
//     cout << "Define some instruments ----------------------------------------\n";
//     Drum drum;
//     Cello cello(673);
//     Cymbal cymbal;
//     Trombone tbone(4);
//     Trumpet trpt(12) ;
//     Violin violin(567) ;
//
//     // use the debugger to look at the mill
//     cout << "Define the MILL ------------------------------------------------\n";
//     MILL mill;
//
//     cout << "Put the instruments into the MILL ------------------------------\n";
//     mill.receiveInstr(trpt);
//     mill.receiveInstr(violin);
//     mill.receiveInstr(tbone);
//     mill.receiveInstr(drum);
//     mill.receiveInstr(cello);
//     mill.receiveInstr(cymbal);
//
//     cout << "Daily test -----------------------------------------------------\n";
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//
//     cout << "Define some Musicians-------------------------------------------\n";
//     Musician j;
//     Musician jj;
//     Musician q;
//
//     cout << "TESTING: q.acceptInstr(*mill.loanOut());-----------------------\n";
//     q.testPlay();
//     cout << endl;
//     q.acceptInstr(*mill.loanOut());
//     cout << endl;
//     q.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//
//     cout << endl << endl;
//
//     q.testPlay();
//     cout << endl;
//     mill.receiveInstr(*q.giveBackInstr());
//     j.acceptInstr(*mill.loanOut());
//     q.acceptInstr(*mill.loanOut());
//     cout << endl;
//     q.testPlay();
//     cout << endl;
//     j.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//
//     cout << "TESTING: mill.receiveInstr(*q.giveBackInstr()); -------------\n";
//
//     // fifth
//     mill.receiveInstr(*q.giveBackInstr());
//     cout << "TESTING: mill.receiveInstr(*j.giveBackInstr()); -------------\n";
//     mill.receiveInstr(*j.giveBackInstr());
//
//
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//
//     cout << endl;
//
//}


// PART TWO
int main() {
    // The initialization phase

    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);

    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);

    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;

    Orch orch;



    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(*mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(*mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(*mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(*mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(*mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    // bob gets an instrument from the MIL2
    bob.acceptInstr(*mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(*mill.loanOut());

    //ralph.testPlay();
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

} // main


