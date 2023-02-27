//*****************************************************************************************************
//
//              File:                   Node.h
//
//              Student:                Carlos Burbano
//
//              Assignment:             Assignment # 10
//
//              Course Name:            Data Structures I
//
//              Course Number:          COSC 3050 01
//
//              Due:                    Nov 21, 2021
//
//
//              This Program builds a Queue with Linked List implementation
//
//              Other files required:
//                  Queue.h
//                  QueueDriver.cpp
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
    Node <T>* prev ;
    Node ();
    Node( const T & , Node <T>* n = nullptr, Node<T>* p = nullptr);
    
};

//*****************************************************************************************************

template <typename T>
Node<T>::Node()
{
    data = 0 ;
    next = nullptr;
    prev = nullptr ;
}

//*****************************************************************************************************

template <typename T>
Node<T>::Node(const T & data , Node <T> *n,  Node <T>*p )
{
    this->data = data;
    next = n;
    prev = p;
}

//*****************************************************************************************************

#endif /* Node_h */
