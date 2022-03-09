#include "functions.hpp"

Elem* make(int data, Elem* p){
    Elem* q = new Elem;
    q->data = data;
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;
    return q;
}

void add(int data, Elem*& root){
    if (root == nullptr) {
        root = make(data, nullptr);
        return;
    }
    Elem* v = root;
    while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))
        if (data < v->data)
            v = v->left;
        else
            v = v->right;
    if (data == v->data)
        return;
    Elem* u = make(data, v);
    if (data < v->data)
        v->left = u;
    else
        v->right = u;
}

void pass(Elem* v){
    if (v == nullptr)
        return;

    pass(v->left);
    std::cout << v->data << std::endl;

    pass(v->right);
}

Elem* search(int data, Elem* v){
    if (v == nullptr)
        return v;
    if (v->data == data)
        return v;
    if (data < v->data)
        return search(data, v->left);
    else
        return search(data, v->right);
}


void deleteElem(int data, Elem*& root){
    Elem* u = search(data, root);
    if (u == nullptr)
        return;

    if (u->left == nullptr && u->right == nullptr && u == root){
        root = nullptr;
        return;
    }

    if (u->left != nullptr && u->right != nullptr){
        Elem* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }

    Elem* t;
    if (u->left == nullptr)
        t = u->right;
    else
        t = u->left;
    if (u->parent->left == u)
        u->parent->left = t;
    else
        u->parent->right = t;
    if (t != nullptr)
        t->parent = u->parent;
}

void numberDepth(int data, Elem* v, int a){
    if (v == nullptr) {
        std::cout << "n";
        return;
    }
    if (v->data == data) {
        std::cout << a;
        return;
    }
    
    if (data < v->data) numberDepth(data, v->left, a + 1);
    else numberDepth(data, v->right, a+1);
}

