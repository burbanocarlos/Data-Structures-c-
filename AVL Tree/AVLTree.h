//*****************************************************************************************************
//
//              File:                   AVLTree.h
//
//              Student:                Carlos Burbano
//
//              Assignment:             Assignment # 8
//
//              Course Name:            Data Structures II
//
//              Course Number:          COSC 3100 01
//
//              Due:                    April 5, 2022
//
//
//              Other files required:
//
//                  Stock.h
//                  Stock.cpp
//                  main.cpp
//                  Stock.txt
//
//*****************************************************************************************************

#ifndef UNTITLED_AVLTREE_H
#define UNTITLED_AVLTREE_H

#include <iostream>
#include <string>

//*****************************************************************************************************

template <typename T>
struct Node{
    T info;
    int bFactor;
    Node<T>* left;
    Node<T>* right;
};

//*****************************************************************************************************

template <typename T>
class AVLTree{
private:
    Node<T>* root;
    void deleteTree(Node<T>*& );
    int max(int, int)const;
    void inOrder(Node<T>*, std::ostream& ) const;
    void preOrder(Node<T>*, std::ostream& ) const;
    void postOrder(Node<T>*, std::ostream& ) const;
    void write(Node<T>*, std::ofstream& ) const;
    void insert(Node<T>*& , const T&);
    int height(Node<T>*)const;
    T* search(Node<T>*, const T&)const;
    int getBalance( Node<T>*) const;
    void rotateLeft(Node<T>*& );
    void rotateRight(Node<T>*& );
    void updateFactors(Node<T>* );

public:
    AVLTree();
    ~AVLTree();
    void inOrder(std::ostream & os = std::cout)const;
    void preOrder(std::ostream & os = std::cout)const;
    void postOrder(std::ostream & os = std::cout)const;
    void write(std::ofstream &  )const;
    void insert(const T&);
    int height()const;
    T* search(const T& ) const;
    void deleteTree();

};

//*****************************************************************************************************

template <typename T>
AVLTree<T>::AVLTree() {
    root = nullptr;
}

//*****************************************************************************************************

template <typename T>
AVLTree<T>::~AVLTree<T>() {
    deleteTree(root);
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::deleteTree() {
    deleteTree(root);
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::deleteTree(Node<T> *& r )
{

    if (r != nullptr){
        deleteTree(r->left);
        deleteTree(r->right);
        delete r;
        r = nullptr;
    }
}

//*****************************************************************************************************

template <typename T>
int AVLTree<T>::getBalance(Node<T> *r) const
{
    int balance;
    if (r == nullptr) {
        balance = 0;
    }
    else {
        balance = height(r->left) - height(r->right);
    }
    return balance;
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::rotateLeft(Node<T> *& k1)
{
    Node<T>* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1 = k2;
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::rotateRight(Node<T> *& k1)
{
    Node<T>* k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1 = k2;
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::updateFactors(Node<T> *r)
{
    if (r != nullptr) {
        r->bFactor = getBalance(r);
        updateFactors(r->left);
        updateFactors(r->right);
    }
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::insert(const T & item )
{
    insert(root, item);
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::insert(Node<T> *& r, const T & item)
{
    using namespace std;
    if ( r == nullptr){
        r = new Node<T>;
        r->info = item;
        r->left = nullptr;
        r->right = nullptr;
    }
    else {
        if (item < r->info) {
            insert(r->left, item);
        }
        else {
                insert(r->right, item);
             }
    }
   r->bFactor = getBalance(r);

    if (r->bFactor > 1){
        if ( r->left->bFactor > 0){
            rotateRight(r);
        }
        else{
            rotateLeft(r->left);
            rotateRight(r);
        }
        updateFactors(r);
    }
    else if ( r->bFactor < -1){
        if ( r->right->bFactor < 0){
            rotateLeft(r);
        }else{
            rotateRight(r->right);
            rotateLeft(r);
        }
        updateFactors(r);
    }
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::inOrder(std::ostream &os) const
{
    inOrder(root, os);
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::inOrder(Node<T> * r, std::ostream & os) const
{
    using namespace std;
    if ( r != nullptr){
        inOrder(r->left, os);
        os << r->info << endl;
        inOrder(r->right,os);
    }
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::postOrder(std::ostream &os) const
{
    postOrder(root, os);
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::postOrder(Node<T> * r , std::ostream & os ) const
{
    using namespace std;
    if ( r != nullptr ){

        preOrder(r->left, os);
        preOrder(r->right, os);
        os << r->info << std::endl;
    }
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::preOrder(std::ostream &os) const
{
    preOrder(root, os);
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::preOrder(Node<T> * r , std::ostream & os) const
{
    using namespace std;
    if ( r != nullptr ){
        os << r->info << endl;
        preOrder(r->left, os);
        preOrder(r->right, os);
    }
}

//*****************************************************************************************************

template <typename T>
T *AVLTree<T>::search(const T & item) const
{
    T* result = nullptr;
    result = search(root,item);
    return result;
}

//*****************************************************************************************************

template <typename T>
T *AVLTree<T>::search(Node<T> * r, const T & item) const
{
    T* result;

    if ( r == nullptr){
        result = nullptr;
    }
    else if(item < r->info){
        result = search(r->left,item);
    }
    else if(item > r->info){
        result = search(r->right,item);
    }
    else{
        result = new T(r->info);
    }
    return result;
}

//*****************************************************************************************************

template <typename T>
int AVLTree<T>::max(int a, int b) const
{
    return ( a > b ) ? a : b ;
}

//*****************************************************************************************************

template <typename T>
int AVLTree<T>::height() const
{
    return height(root);
}

//*****************************************************************************************************

template <typename T>
int AVLTree<T>::height(Node<T> * r) const
{
    int result;
    if ( r == 0){
        result = 0 ;
    }
    else{
        result = 1 + max(height(r->left), height(r->right));
    }
    return result;
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::write(std::ofstream & fout)const
{
    write(root, fout);
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::write(Node<T> * r, std::ofstream & fout ) const
{
    if ( r != nullptr){
        write(r->left,fout);
        fout << r->info;
        write(r->right, fout);
    }

}

//*****************************************************************************************************

#endif //UNTITLED_AVLTREE_H
