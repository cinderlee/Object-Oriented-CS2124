//
//  rec13.cpp
//  Lab 13
//
//  Created by Cindy Lee on 12/8/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Purpose: Using the STL algorithms, templates, and auto,
//  and implementing our own functions
//  to find if certain conditions are met


#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <set>         // task 20
#include <map>         // task 22
using namespace std;

void displayList (const list<int>& listVec);
void displayListTwo (const list<int>& listVec);
void displayListAuto (const list<int>& listVec);
list <int>::const_iterator findInt (const list<int>& listVec, int x);
list <int>::const_iterator findIntAuto (const list<int>& listVec, int x);
bool ifEven (int x);


// task 19
//list <int>::const_iterator ourFind (list <int> :: const_iterator start,
//list <int> :: const_iterator end, int x) {
template <typename T, typename S>
T ourFind (T start, T end, S x) {
    cout << "ourFind at work" << endl;
    for (T iter = start; iter != end; iter++ ) {
        if ((*iter) == x) {
            return iter;
        }
    }
    return end;
}

// task 16a
class IsEven {
public:
    bool operator() (int n) {
        return n % 2 == 0;
    }
};


int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector < int > vec;
    vec.push_back ( 1 );
    vec.push_back ( 9 );
    vec.push_back ( 2 );
    vec.push_back ( 5 );
    vec.push_back ( 11 );
    vec.push_back ( 23 );
    vec.push_back ( 18 );
    vec.push_back ( -4 );
    for (int x: vec) {
        cout << x << " ";
    }
    cout << "\n=======\n";
    
    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list <int> vecList (vec.begin (), vec.end ());
    for (int y : vecList) {
        cout << y << " ";
    }
    cout << "\n=======\n";
    
    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort (vec.begin (), vec.end ());
    for (int sorted: vec) {
        cout << sorted << " ";
    }
    cout << endl;
    for (int y : vecList) {
        cout << y << " ";
    }
    cout << "\n=======\n";
    
    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    
    for (size_t index = 0; index < vec.size (); index += 2) {
        cout << vec [index] << " ";
    }
    
    cout << "\n=======\n";
    
    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    
//    for (size_t index = 0; index < vecList.size (); index += 2) {
//        cout << vecList [index] << " ";
//    }
    
    cout << "\n=======\n";
    
    //
    // Iterators
    //
    
    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";

    for ( vector<int>::iterator iter = vec.begin (); iter < vec.end (); iter +=2 ) {
        cout << *iter << " ";
    }

    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    
    cout << "Task 7:\n";
    for ( list <int>::iterator iter = vecList.begin ();
         iter != vecList.end (); iter++, iter++ ) {
        cout << *iter << " ";
        
    }


    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    
    vecList.sort ();
    for (int sortedList : vecList) {
        cout << sortedList << " ";
    }

    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    
    displayList ( vecList );

    cout << "\n=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    
    displayListTwo (vecList);
    cout << "\n=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    
    displayListAuto (vecList);
    
    cout << "\n=======\n";


    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    cout << "Finding 5: ";
    if (findInt (vecList, 5) != vecList.end ()) {
        cout << *(findInt (vecList, 22)) << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    cout << "Finding 22: ";
    if (findInt (vecList, 22) != vecList.end ()) {
        cout << *(findInt (vecList, 22)) << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    cout << "\n=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    cout << "Finding 5: ";
    if (findIntAuto (vecList, 5) != vecList.end ()) {
        cout << *(findIntAuto (vecList, 5)) << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    cout << "Finding 22: ";
    if (findIntAuto (vecList, 22) != vecList.end ()) {
        cout << *(findIntAuto (vecList, 22)) << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    //cout << "Finding 5: " << *(findIntAuto (vecList, 5))<< endl;
    //cout << "Finding 22: " << *(findIntAuto (vecList, 22)) << endl;

    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    cout << "Finding 5: ";
    if (find (vecList.begin (), vecList.end (), 5) != vecList.end ()) {
        cout << *(find (vecList.begin (), vecList.end (), 5)) << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    cout << "Finding 22: ";
    if (find (vecList.begin (), vecList.end (), 22) != vecList.end ()) {
        cout << *(find (vecList.begin (), vecList.end (), 22)) << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    if (find_if (vecList.begin (), vecList.end (), ifEven) != vecList.end()) {
        cout << "Even number: " <<
        *(find_if (vecList.begin (), vecList.end (), ifEven));
    }
    else {
        cout << "Cannot find an even number";
    }
    cout << "\n=======\n";

    // 16a. Functor
    cout << "Task 16a:\n";
    IsEven functory;
    if (find_if (vecList.begin (), vecList.end (), functory) != vecList.end ()) {
        cout << "Even number: " <<
        *(find_if (vecList.begin (), vecList.end (), functory));
    }
    else {
        cout << "Cannot find an even number";
    }
    //cout << *(find_if (vecList.begin (), vecList.end (), functory));
    cout << "\n=======\n";

    // 16b. Lambda
    cout << "Task 16b:\n";
    [] { cout << "Hello Lambda!"; }();
    cout << endl;
    [] (int a, int b) { cout << a + b << endl; } (4, 5);
    //int result = [] (int a, int b) { return a + b; } (4, 5);
    int result2 = [] (int a, int b) -> int { return a + b; } (4, 5);
    cout << "the result is: " << result2 << endl;
    cout << "\n=======\n";

    // 17. Generic algorithms: copy to an array
    cout << "Task 17:\n";
    int arr[8]; // if there are eight items in the vector
    copy (vecList.begin (), vecList.end (), arr);
    for (int stuff: arr) {
        cout << stuff << " ";
    }
    cout << endl;
    cout << "Finding 5: ";
    if (find (arr, arr + 8, 5) != arr + 8) {
        cout << * (find (arr, arr + 8, 5)) << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    cout << "Finding 22: ";
    if (find (arr, arr+8, 22) != arr +8) {
        cout << * ( find (arr, arr + 8, 22)) << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    cout << "Finding Even: ";
    if (find_if (arr, arr+8, functory) != arr + 8) {
        cout << * ( find_if (arr, arr + 8, functory));
    }
    else {
        cout << "Not Found" << endl;
    }
    cout << "\n=======\n";

    //
    // Templated Functions
    //

    // 18. Implement find as a function for lists
    cout << "Task 18:\n";
    cout << "Finding 5: ";
    if (ourFind (vecList.begin (), vecList.end (), 5) != vecList.end ()) {
        cout << *(ourFind (vecList.begin (), vecList.end (), 5)) << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    if (ourFind (vecList.begin(), vecList.end (), 22 ) != vecList.end ()) {
        cout << "Finding 22: " << *(ourFind (vecList.begin (),
                                             vecList.end (), 22)) << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    cout << "=======\n";

    // 19. Implement find as a templated function
    cout << "Task 19:\n";
    cout << "For List" << endl;
    cout << "Finding 5: ";
    if (ourFind (vecList.begin (), vecList.end (), 5) != vecList.end ()) {
        cout << *(ourFind (vecList.begin (), vecList.end (), 5)) << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    cout << "Finding 22: " ;
    if (ourFind (vecList.begin(), vecList.end (), 22 ) != vecList.end ()) {
        cout << "Finding 22: " << *(ourFind (vecList.begin (),
                                             vecList.end (), 22)) << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    
    cout << "For Vector" << endl;
    cout << "Finding 5: ";
    if (ourFind (vec.begin (), vec.end (), 5) != vec.end ()) {
        cout << *(ourFind (vec.begin (), vec.end (), 5)) << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    cout << "Finding 22: " ;
    if (ourFind (vec.begin(), vec.end (), 22 ) != vec.end ()) {
        cout << "Finding 22: " << *(ourFind (vec.begin (),
                                             vec.end (), 22)) << endl;
    }
    else {
        cout << "Not Found" << endl;
    }
    
    cout << "=======\n";

    //
    // Associative collections
    //

    // 20. Using a vector of strings, print a line showing
    cout << "Task 20:\n";
    ifstream in_file ("pooh-nopunc.txt");
    if (!in_file) {
        cerr << "File does not exist \n";
        exit (1);
    }
    string word = "";
    vector <string> words;
    while (in_file >> word) {
        if (find (words.begin (), words.end (), word) == words.end() )  {
            words.push_back (word);
        }
    }
    in_file.close ();
    cout << "Vector of Words: " << words.size () << endl;
    for (const string& word : words) {
        cout << word << " "; ;
    }
    cout << "\n=======\n";

    // 21. Repeating previous step, but using the set
    cout << "Task 21:\n";
    set <string> setOfWords;
    in_file = ifstream ("pooh-nopunc.txt");
    while (in_file >> word) {
        setOfWords.insert (word);
    }
    in_file.close ();
    cout << "Set of Words: " << words.size () << endl;
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << "\n=======\n";

    // 22. Word co-occurence using map
    cout << "Task 22:\n";
    map<string, vector<int>> wordMap;
    in_file = ifstream ("pooh-nopunc.txt");
    int count = 0;
    while (in_file >> word) {
        wordMap [word].push_back ( count );
        count++;
    }
    for (auto paired: wordMap) {
        cout << paired.first << ": ";
        for (int places : paired.second ) {
            cout << places << " ";
        }
        cout << endl;
    }
    in_file.close ();
    cout << "=======\n";
}

//task 9
void displayList (const list <int>& listVec) {
//    for (list <int> :: iterator iter = listVec.begin (); iter != listVec.end (); iter++) {
//        cout << *iter << " ";
//    }
    for (list <int> :: const_iterator iter = listVec.begin ();
         iter != listVec.end ();
         iter++ ) {
        cout << *iter << " ";
    }
}


//task 10
void displayListTwo (const list <int>& listVec) {
    for (int data : listVec) {
        cout << data << " ";
    }
}

// task 11
void displayListAuto (const list<int>& listVec) {
    for (auto iter = listVec.begin (); iter != listVec.end ();
         iter++, iter++ ) {
        cout << *iter << " ";
    }
}

// task 12
list <int>::const_iterator findInt (const list<int>& listVec, int x) {
   for (list <int> :: const_iterator iter = listVec.begin ();
        iter != listVec.end ();
         iter++ ) {
       if ( *iter == x) {
           return iter;
       }
   }
    return listVec.end ();
}


// task 13
// auto won't work as a return type
list <int>::const_iterator findIntAuto (const list<int>& listVec, int x) {
    for (auto iter = listVec.begin (); iter != listVec.end ();
        iter++ ) {
        if ( *iter == x) {
            return iter;
        }
    }
    return listVec.end ();
}

// task 15
bool ifEven (int x) {
    if (x % 2 == 0) {
        return true;
    }
    return false;
}


