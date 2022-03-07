#include <iostream>


struct Elem{
    int data;
    Elem* left;
    Elem* right;
    Elem* parent;
};
Elem* make(int data, Elem* p);
void add(int data, Elem*& root);
void pass(Elem* v);
Elem* search(int data, Elem* v);
void deleteElem(int data, Elem*& root);
void numberDepth(int data, Elem* v, int a);