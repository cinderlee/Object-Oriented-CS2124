//
//  main.cpp
//  Review
//


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//structs
// inside the struct is all public
struct Noble {
    string name;
    int strength;
};

//Big Three

//inside a class, everything is private by default
class Flying {
public:
    //constructor
    Flying (const string& namer, int flypower): name (namer), flyingpower (flypower) {}
    
    //copy constructor
    Flying (const Flying& pigeon): name (pigeon.name), flyingpower (pigeon.flyingpower) {
    }
    
    //destructor
    ~Flying () {
        // delete the variables that are allocated to memory
        for (size_t index =0 ; index < army.size(); index++) {
            delete army [index];
        }
        
        army.clear ();
    }
    
    // assignment operator
    Flying& operator= (const Flying& flyster) {
        // check yourself
        // delete your own data
        // assign to your own deleted data
        // break
        if (this != &flyster) {
            name = flyster.name;
            flyingpower = flyster.flyingpower;
            
            // delete whatever is in your vector
            for (size_t index =0 ; index < army.size(); index++) {
                delete army [index];
            }
            
            army.clear ();
            
            // copy over the vector data
            for (size_t index =0 ; index < flyster.army.size(); index++ ) {
                army.push_back (new int (* (flyster.army [index])));
            }
        }
        //this is a pointer to yourself
        return *this;
        // chaining x = y = z;
        // y = z <- return back so that you can x = (y = z)
        // Flying = (Flying = Flying)
        
        //Flying one;
        //Flying two = one
        // this isn't assignment operator -> copying over one's items to two
        // this is actually copy constructor
        
    }
private:
    string name;
    int flyingpower = 0;
    vector <int*> army;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // range for
    vector <int> vec;
    
    for (int x: vec) {
        cout << x << endl;
    }
    
    // replace values inside vector
    
    for (int& x:vec) {
        x++;
    }
    
    // dynamic memory
    
    vector <int*> memoryVec;
    for (int i = 0; i < 27; i++) {
        memoryVec.push_back(new int (15));
    }
    
    // deleting
    for (int i = 0; i < 27; i++) {
        delete (memoryVec [i]);
        //dangling pointers removed
        //dangling pointers are existing pointeres not referencing to a memory address
        memoryVec[i] = nullptr;
    }
    
    // reuse vector
    memoryVec.clear () ;
    
    
    
    
    //pointers
    int number = 1;
    int number2 = 16;
    
    //Case 1
    //const is closer to * than int
    // constant memory address
    int* const pointer = & (number);
    //pointer = & (number2) - can't change memory address
    *pointer = 5;
    // You can use the pointer to change the value inside number
    
    //Case 2
    // const is closer to int than pointer
    // integer is constant
    // value at memory address inside variable cannot be changed
    const int* pointer2 = & (number) ;
    // *pointer2 = 5;
    // cannot use pointer to change the number
    number = 5;
    
    //Case 3
    //cannot change address and value stored
    const int* const pointer3 = & (number);
    // constant memory address
    // constant value inside memory address
    // Noble Warriors, using this third case
    
    
    //file I/O
    ifstream ifs ("data.txt");
    // Name Number Number
    // Amy 5 4
    string name;
    int num1;
    int num2;
    
    // while - goes from beginning to end
    while (ifs >> name >> num1 >> num2) {
        // name = Amy
        // num1 = 5
        // num2 = 4
        cout << name << num1 << num2;
    }
    
    // Amy 5 4
    // Tom 3 6
    ifs >> name >> num1 >> num2;
    // name = Amy
    // num1 = 5
    // num2 = 4
    
    ifs >> name >> num1 >> num2;
    // name = Tom
    // num1 = 3
    // num2 = 6
    
    //function -> ifstream& ifs
    // ask specifications regarding closing file
    
    ifstream ifs2("newFile.txt");
    // Hi my name is 5
    int fileInt;
    // putting 5 inside fileInt
    ifs2 >> fileInt;
    // fileInt = 5
    
    ifs.close ();
    ifs2.close ();
    
    // structs
    Noble nob;
    nob.name = "Hi";
    nob.strength = 164;
    
    Noble nob2;
    //if (nob == nob2) {
        // can't compare because only comparing memory addresses
    //}
    // need to directly compare the variables inside

    //dynamic arrays
    int* arr = new int [10];
    // arr [0] ~ arr
    // pointer arithmetic
    // second element pointer -> arr + 1
    // second element -> *(arr + 1)
    // can reassign array to a new array
    // fixed sizes
    
    // individual deletion
    delete (arr + 5);
    // (arr + 5) = nullptr;
    // gets rid of dangling pointers
    
    // deletion of the entire array
    // dangling pointers will be gone
    delete [] arr;
    arr = new int [20];
    
    //Big Three
    
    // First Exam Extra Credit - Stroustrup
    std::cout << "Hello, World!\n";
    return 0;
}
