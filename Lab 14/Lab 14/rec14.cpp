//
//  rec14.cpp
//  Lab 14
//
//  Created by Cindy Lee on 12/15/17.
//  Copyright © 2017 Cindy Lee. All rights reserved.
//
//  Purpose: using recursion to solve problems, such as number of Hanoi moves

#include <iostream>
#include <climits>
using namespace std;

struct Node {
    Node (int data = 0, Node* next = nullptr) : data (data), next (next) {}
    Node* next;
    int data;
};

struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};

bool hasEvenOnes (int number);
Node* sumList (Node* placer, Node* otherPlacer);
void displayList ( Node* head );
int max(TNode* root);
bool palindrome (char* characters , int sizeArray);
int movesHanoi (int n, char start, char target, char extra);
void func(int n);

int main() {
    cout << "0b101: " << boolalpha << hasEvenOnes (0b101) << endl;
    cout << "0b1100001: " << boolalpha << hasEvenOnes (0b1100001) << endl;
    cout << "0b1101001: " << boolalpha << hasEvenOnes (0b1101001) << endl;
    cout << "0b0011: " << boolalpha << hasEvenOnes (0b0011) << endl;
    
    Node* first = new Node ( 5, new Node (7, new Node (9)));
    Node* second = new Node ( 6, new Node (8, new Node (12) ) );
    Node* total = sumList (first, second);
    cout << "First List: ";
    displayList (first);
    cout << endl << "Second List: ";
    displayList (second);
    cout << endl << "First + Second: " ;
    displayList (total);
    cout << endl;
    
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    cout << max(&f) << endl;
    
    TNode a_2(4), b_2(2), c_2(8), d_2(68, &a_2, &b_2), e_2(64, &c_2),
    f_2(32, &d_2, &e_2);
    cout << max(&f_2) << endl;
    
    char s[] = "racecar";
    if (palindrome(s, 7)) { cout << "racecar: Yes!\n"; }
    
    char s2[] = "jegiowrh";
    if (palindrome(s2, 8)) { cout << "jegiowrh: Yes!\n"; }
    
    char s3[] = "noon";
    if (palindrome(s3, 4)) { cout << "noon: Yes!\n"; }
    
    cout << " HANOI : 5 : " << movesHanoi (5, 'a', 'b', 'c') << endl;
    
    cout << " HANOI : 4 : " << movesHanoi (4, 'a', 'b', 'c') << endl;
    
    func ( 4);
    //a a c b c c b a c b c c c
    cout << endl;
    func ( 1);
    // c
    cout << endl;
    func ( 3);
    // a c b c c
    cout << endl;
}



bool hasEvenOnes (int number) {
//    int count = 0;
//    if (number < 2) {
//        count += number;
//    }
//    else {
//        count = number % 2 + hasEvenOnes (number / 2);
//    }
//    return count % 2 == 0;
    
    if (number < 2 ) { return !number ; }
    return (! (number % 2) == hasEvenOnes (number / 2));
}

Node* sumList (Node* placer, Node* otherPlacer) {
    if (placer == nullptr ) {
        return nullptr;
    }
    
    Node* place = new Node (placer -> data + otherPlacer -> data);
    if (placer -> next) {
        place -> next = sumList (placer -> next, otherPlacer -> next);
    }
    return place;

}

void displayList ( Node* head ) {
    while (head) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

int max(TNode* root) {
    if (! root ) {
        return INT_MIN;
    }
    if (! root -> left && ! root -> right) {
        return root -> data;
    }
    return max ( root -> data, max ( max (root -> left, root -> right)));
//    int number = INT_MIN;
//    if (root) { number = root -> data; }
//    number = max ( max ( root -> left) , max ( root -> right));
//    if (root -> left) {
//        if (number < max ( root -> left )) {
//            number = max (root -> left);
//        }
//    }
//    if (root -> right ) {
//        if (number < max ( root -> right )) {
//            number = max (root -> right);
//        }
//    }
//    return number;
}

bool palindrome (char* characters , int sizeArray) {
    if (sizeArray < 2) {
        return true;
    }
    return (*characters == *(characters + sizeArray - 1))  &&
    palindrome (characters + 1, sizeArray - 2) ;
}

int movesHanoi (int n, char start, char target, char extra) {
    if (n == 0) return 0 ;
    return 1 + movesHanoi (n-1, start, extra, target) +
    movesHanoi (n-1, extra, target, start) ;
}

void func(int n) {
    if (n > 1) {
        cout << 'a';
        func(n/2);
        cout << 'b';
        func(n/2);
    }
    cout << 'c';
}


