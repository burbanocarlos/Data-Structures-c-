//*****************************************************************************************************
//
//              File:                   BinaryTree.h
//
//              Student:                Carlos Burbano
//
//              Assignment:             Assignment # 6
//
//              Course Name:            Data Structures II
//
//              Course Number:          COSC 3100 01
//
//              Due:                    March 16, 2022
//
//
//              Other files required:
//                  BinaryTree.cpp
//                  Stock.h
//                  Stock.cpp
//                  main.cpp
//                  Stock.txt
//
//*****************************************************************************************************

#ifndef TEST_CLION_BINARYTREE_H
#define TEST_CLION_BINARYTREE_H

#include <iostream>
#include <string>

//****************************************************************************************************

template <typename T>
struct Node
{
    T info;
    Node<T>*left;
    Node<T>*right;
};

//****************************************************************************************************


template <typename T>
class BinaryTree
{
private:
    Node<T>* root;
    void deleteTree(Node<T>*& );
    int max(int, int)const;
    void inOrder(Node<T>*, std::ostream& ) const;
    void preOrder(Node<T>*, std::ostream& ) const;
    void postOrder(Node<T>*, std::ostream& ) const;
    void insert(Node<T>*& , const T&);
    int height(Node<T>*)const;
    T* search(Node<T>*, const T&)const;

public:
    BinaryTree();
    ~BinaryTree();
    void inOrder(std::ostream & os = std::cout)const;
    void preOrder(std::ostream & os = std::cout)const;
    void postOrder(std::ostream & os = std::cout)const;
    void insert(const T&);
    int height()const;
    T* search(const T& ) const;
    void deleteTree();
};

//****************************************************************************************************

template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

//****************************************************************************************************

template <typename T>
void BinaryTree<T>::insert(const T & item) {
    insert(root,item);
}

//****************************************************************************************************

template <typename T>
void BinaryTree<T>::insert(Node<T> *& r, const T & item)
{
    using namespace std;
    if ( r == nullptr){
        r = new Node<T>;
        r->info = item;
        r->left = nullptr;
        r->right = nullptr;
    }
    else if (item < r->info){
        insert(r->left, item);
    }
    else if ( item > r->info){
        insert(r->right,item);
    }
    else{
        cout<<"Duplicate Node"<< endl;
    }
}

//****************************************************************************************************

template <typename T>
int BinaryTree<T>::height() const
{
    return height(root);
}

//****************************************************************************************************

template <typename T>
int BinaryTree<T>::height(Node<T> * r) const
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

//****************************************************************************************************

template <typename T>
BinaryTree<T>::~BinaryTree<T>()
{
    deleteTree(root);
}

//****************************************************************************************************

template <typename T>
void BinaryTree<T>::deleteTree()
{
    deleteTree(root);
}

//****************************************************************************************************

template <typename T>
void BinaryTree<T>::deleteTree(Node<T>*& r)
{
    if (r != nullptr){
        deleteTree(r->left);
        deleteTree(r->right);
        delete r;
        r = nullptr;
    }
}

//****************************************************************************************************

template <typename T>
int BinaryTree<T>::max(int a, int b ) const {
    return ( a > b ) ? a : b ;
}

//****************************************************************************************************

template <typename T>
T* BinaryTree<T>::search(const T & item) const
{
    T* result = nullptr;
  result = search(root,item);
    return result;
}

//****************************************************************************************************

template <typename T>
T* BinaryTree<T>::search(Node<T> * r, const T & item) const
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

//****************************************************************************************************

template <typename T>
void BinaryTree<T>::inOrder(std::ostream &os) const
{
    inOrder(root, os);
}

//****************************************************************************************************

template <typename T>
void BinaryTree<T>::inOrder(Node<T> * r, std::ostream & os) const {

    using namespace std;
    if ( r != nullptr){
        inOrder(r->left, os);
        os << r->info << endl;
        inOrder(r->right,os);
    }
}

//****************************************************************************************************

template <typename T>
void BinaryTree<T>::preOrder(std::ostream &os) const
{
    preOrder(root, os);
}

//****************************************************************************************************

template <typename T>
void BinaryTree<T>::preOrder(Node<T> * r , std::ostream & os ) const {
    using namespace std;
    if ( r != nullptr ){
        os << r->info << endl;
        preOrder(r->left, os);
        preOrder(r->right, os);
    }
}

//****************************************************************************************************

template <typename T>
void BinaryTree<T>::postOrder(std::ostream &os) const
{
    postOrder(root,os);
}

//****************************************************************************************************

template <typename T>
void BinaryTree<T>::postOrder(Node<T> * r, std::ostream & os ) const {
    using namespace std;
    if ( r != nullptr ){

        preOrder(r->left, os);
        preOrder(r->right, os);
        os << r->info << std::endl;
    }
}

#endif //TEST_CLION_BINARYTREE_H

//****************************************************************************************************
