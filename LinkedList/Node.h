//*****************************************************************************************************
//
//              File:                   Node.h
//
//              Student:                Carlos Burbano
//
//              Assignment:             Assignment # 4
//
//              Course Name:            Data Structures I
//
//              Course Number:          COSC 3050 01
//
//              Due:                    Sep 29, 2021
//
//
//              This Program utilizes concepts of single linked list
//
//
//              Other files required:
//                  LinkedList.h
//                  LLDriver.cpp
//
//*****************************************************************************************************

#ifndef Node_h
#define Node_h

//*****************************************************************************************************

template <typename T>
struct Node
{
    
    T data;
    Node <T> * next ;
    Node ();
    Node( const T & , Node <T>* n = nullptr);
    
};

//*****************************************************************************************************

template <typename T>
Node<T>::Node()
{
    data = 0 ;
    next = nullptr;
}

//*****************************************************************************************************

template <typename T>
Node<T>::Node(const T & data , Node <T> *n)
{
    this->data = data;
    next = n;
}

//*****************************************************************************************************

#endif /* Node_h */
