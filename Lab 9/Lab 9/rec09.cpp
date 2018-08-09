//
//  rec09.cpp
//  Lab 9
//
//  Created by Cindy Lee on 11/3/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Cindy Lee, ID: cl3616
//  Purpose: Introduction to inheritance

#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial (unsigned numPages) : numberOfPages (numPages) {}
    virtual void displayNumPages() const = 0;
    //{ cout << "Number of Pages: " << numberOfPages << endl;}
protected:
    //protected method to obtain number of Pages
    unsigned getPages() const {
        return numberOfPages;
    }
private:
    friend ostream& operator<< (ostream& os, const PrintedMaterial& material) {
        os << "Number of Pages: " << material.numberOfPages;
        return os;
    }
    unsigned numberOfPages;
};

//void PrintedMaterial::displayNumPages() const {
//    cout << "Number of Pages: " << numberOfPages <<endl;
//}

class Magazine : public PrintedMaterial {
public:
    Magazine (unsigned numPages): PrintedMaterial ( numPages ) {}
    void displayNumPages() const {
        cout << "Magazine" << endl;
        cout << "Number of Pages: " << getPages () << endl;
    }
protected:
private:
    //unsigned numberOfPages;
};

class Book : public PrintedMaterial {
public:
    Book (unsigned numPages) : PrintedMaterial (numPages) {}
protected:
private:
    //unsigned numberOfPages;
};

class TextBook : public Book {
public:
    //Textbook ( unsigned numPages ) : PrintedMaterial (numPages) {}
    TextBook (unsigned numPages, unsigned index) :
    Book (numPages), numberOfIndexPages (index) {}
    void displayNumPages() const {
        //cout << numberOfPages << " " << numberOfIndexPages; }
        //PrintedMaterial::displayNumPages();
        cout << "Textbook" << endl;
        cout << "Number of Pages: " << getPages () << endl;
        cout << "Number of Index Pages: " << numberOfIndexPages << endl;
    }
protected:
private:
    //unsigned numberOfPages;
    unsigned numberOfIndexPages;
};

class Novel : public Book {
public:
    //Novel ( unsigned numPages ) : PrintedMaterial (numPages) {}
    Novel (unsigned numPages) : Book (numPages) {}
    void displayNumPages() const {
        cout << "Novel" << endl;
        cout << "Number of Pages: " << getPages () << endl;
    }
protected:
private:
    //unsigned numberOfPages;
};

//standalone function
void displayNumberOfPages (const PrintedMaterial& material) {
    material.displayNumPages();
}

// tester/modeler code
int main()
{
    TextBook t (5430, 234);
    Novel n (213);
    Magazine m (6);
    
    //cout << t << endl;
    //cout << n << endl;
    t.displayNumPages();
    cout << "\n";
    n.displayNumPages();
    cout << "\n";
    m.displayNumPages();
    cout << "\n";
    
    // vector <PrintedMaterial> collection;
    vector <PrintedMaterial*> collection;
    
    //PrintedMaterial pm = t;
    // like putting a t into a vector of PrintedMaterials
    //pm.displayNumPages();
    
    PrintedMaterial* pmPtr;
    pmPtr = &t;
    // instead of putting an actual PrintedMaterial
    // object into the vector, we put a pointer to
    // a PrintedMaterial object (t) into a vector
    // of pointers-to-PrintedMaterial
    // (that is, pointers to the Base class)
    // we'll be "managing" our objects by using
    // pointers to PrintedMaterial values.
    
    pmPtr->displayNumPages();
    
    cout << "\n";
    
    collection.push_back (&t);
    collection.push_back (&n);
    collection.push_back (&m);
    
    for (size_t index = 0; index < collection.size(); ++index) {
        collection [index] -> displayNumPages();
        cout << "\n";
    }
}

