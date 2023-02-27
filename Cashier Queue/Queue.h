//*****************************************************************************************************
//
//              File:                   Queue.h
//
//              Student:                Carlos Burbano
//
//              Assignment:             Assignment # 11
//
//              Course Name:            Data Structures I
//
//              Course Number:          COSC 3050 01
//
//              Due:                    Dec 3, 2021
//
//
//              This Program simulates a queue using a metaphor with cashiers and users.
//
//              Other files required:
//                  Node.h
//                  Simulation.cpp
//                  Cashier.h
//                  Customer.h
//                  customerList.txt
//
//*****************************************************************************************************


#ifndef Queue_h
#define Queue_h
#include <new>
#include "Node.h"

using namespace std;

//*****************************************************************************************************


template<typename T >
class Queue
{
private:
    Node<T>*    front ;
    Node<T>*    rear;


public:
    Queue();
    ~Queue();
    bool enqueue ( const T & );
    bool dequeue ( T &);
    bool viewFront( T &)const;
    bool viewBack ( T & )const;
    int getSize()const;
    bool isFull()const;
    bool isEmpty()const;
};

template<typename T >
Queue<T>::Queue()
{

    front =         nullptr;
    rear =          nullptr;

}

//*****************************************************************************************************

template<typename T >
Queue<T>::~Queue()
{
    Node<T>* pTemp = front ;

    while ( front != nullptr)
    {

        front =    front->next;
        delete     pTemp ;
        pTemp =    front;
        front =    nullptr;
        rear =     nullptr;
    }
}

//*****************************************************************************************************

template<typename T >
bool Queue<T>::enqueue(const T & dataIn)
{
    bool success = false;

    Node<T>* pNew = new(nothrow) Node<T> (dataIn);
    if ( pNew != nullptr)
    {
        if ( rear != nullptr)
            rear->next = pNew;

        else
            front =pNew;
        rear = pNew;
        success = true;

    }
    return success;
}

//*****************************************************************************************************

template<typename T >
bool Queue<T>:: dequeue ( T & dataOut)
{
    bool success = false ;

    Node<T>* pDel = front;

    if ( front != nullptr)
    {
        if ( front == rear)
            rear = nullptr;

            front = front->next;
            dataOut = pDel->data;
            delete pDel;
            success = true;
    }

    return success;
}

//*****************************************************************************************************

template<typename T >
bool Queue<T>:: viewFront(T & dataOut)const
{
    bool success = false;

    Node<T>* pTemp = front ;

    if ( pTemp != nullptr)
    {
        dataOut = pTemp->data;
        success = true ;
    }

    return success;
}

//*****************************************************************************************************

template<typename T >
bool Queue<T>:: viewBack(T & dataOut)const
{
    bool success = true ;
    Node<T>* pTemp = rear ;

    if ( pTemp != nullptr)
    {
        dataOut = pTemp->data;
        success = true ;
    }

    return success ;
}

//*****************************************************************************************************

template<typename T >
int Queue<T>:: getSize()const
{
    int dataOut = 0 ;
    Node<T>* pTemp =front ;

    while ( pTemp != nullptr)
    {
        pTemp= pTemp->next;
        dataOut++;
    }

    return dataOut;
}

//*****************************************************************************************************

template <typename T>
bool Queue<T>:: isFull()const
{
    bool success = true;
    Node<T>* pNew = new(nothrow) Node<T>;

    if ( pNew != nullptr)
    {
        success = false;
        delete pNew;
    }

    return success;
}

//*****************************************************************************************************

template<typename T >
bool Queue<T>::isEmpty()const
{

    return front == nullptr;
}
#endif /* Queue_h */

//*****************************************************************************************************
