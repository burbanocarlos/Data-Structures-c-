//*****************************************************************************************************
//
//              File:                   LinkedList.h
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
//                  LLDriver.cpp
//                  Node.h
//
//*****************************************************************************************************

#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"
#include <iostream>
#include <new>

using namespace std ;

//*****************************************************************************************************

template <typename T>
class LinkedList
{
    
private:
    Node<T>* front ;
    
public:
    LinkedList();
    ~LinkedList();
    bool insert ( const T& );
    bool del(T&);
    bool deleteFront(T&);
    bool deleteBack(T&);
    bool display()const;
    bool viewFront( T & )const;
    bool viewBack(T&)const;
    bool find(T&)const;
    bool isFull()const;
    bool isEmpty()const;
    bool getSize(T&)const;
    bool counting( const T& , int &)const;
    bool deleteAllBut(const T&);
    bool clearList();
};

//*****************************************************************************************************

template <typename T>
LinkedList<T>::LinkedList()
{
    front =  nullptr;
}

//*****************************************************************************************************

template <typename T>
LinkedList<T>::~LinkedList()
{
   Node<T>* pTemp = front ;


while ( front != nullptr)
    {
        
        front = front->next;
        delete pTemp ;
        pTemp = front;
        front = nullptr;
    }
}

//*****************************************************************************************************

template <typename T>
bool LinkedList<T>::insert(const T & dataIn)
{
    
    bool success = false;
    Node<T>* pPrev = nullptr;
    Node<T>* pAfter = front;
    
    while ( pAfter != nullptr && pAfter->data < dataIn)
    {
        pPrev = pAfter;
        pAfter =  pAfter->next;
    }
    
        Node<T>* pNew = new(nothrow) Node<T>(dataIn, pAfter);
        
        if ( pNew != nullptr)
        {
            if ( pPrev != nullptr)
                pPrev->next = pNew;
            else
                front = pNew;
            
            success = true;
        }
    
    return success;
    
}

//*****************************************************************************************************

template <typename T>
bool LinkedList<T>:: del(T & dataOut)
{
    
    bool success = false ;
    
    Node<T>* pPrev = nullptr,
            *pTemp = front ;
    
    while ( pTemp != nullptr && pTemp->data < dataOut)
    {
        pPrev = pTemp;
        pTemp = pTemp->next;
    }
    if ( pTemp != nullptr && pTemp->data == dataOut)
    {
        if ( pPrev != nullptr)
            pPrev->next = pTemp->next;
        else
            front = pTemp->next;
        dataOut = pTemp->data;
        delete pTemp;
        success = true;
    }
    
    return success;
    
}

//*****************************************************************************************************

template <typename T >
bool LinkedList<T>::deleteFront(T & dataOut)
{
    
    bool success = false ;
    Node<T>*  pTemp = front;
    
    if ( pTemp != nullptr )
    {
        front = front->next;
        dataOut = pTemp->data;
        delete pTemp;
        success = true;
    }
    
    return success;
    
}

//*****************************************************************************************************

template <typename T>
bool LinkedList<T>:: display()const
{
    
    bool success = false;
    
    Node<T>* pTemp = nullptr;
    pTemp = front;
    
    if ( pTemp != nullptr)
    {
        while ( pTemp != nullptr)
        {
            cout << pTemp->data << " " ;
            pTemp = pTemp->next;
        }
        cout << endl;
        success = true;
    }
    
    return success;
    
}

//*****************************************************************************************************

template <typename T>
bool LinkedList<T>::deleteBack(T & dataOut)
{
    
    bool success = false ;
    
    Node<T>* temp =front;
    Node<T>* tail = front;
    
    if ( temp != nullptr && temp->next == nullptr)
    {
        dataOut = front->data;
        delete front;
        front = nullptr;
        success = true;
    }

    if ( temp != nullptr )
    {
        while ( temp->next != nullptr)
        {
            tail = temp;
            temp = temp->next;
        }
        tail->next = nullptr;
        dataOut = temp->data;
        temp = nullptr;
        delete temp;

        success = true;
    }
    
    return  success;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList<T>::viewFront( T & dataOut)const
{
    bool success = false ;
    
    Node<T>* pTemp = front ;
    if ( pTemp != nullptr)
    {
        dataOut = pTemp->data;
        success = true ; 
    }
    
    return success;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList<T>::viewBack(T & dataOut)const
{
    bool success = true ;
    Node<T>* pTemp = front;
    if ( pTemp != nullptr)
    {
        while ( pTemp->next != nullptr)
        {
            pTemp = pTemp-> next;
        }
        dataOut = pTemp->data;
        success = true ; 
    }
    
    return success ;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList<T>::find(T & dataOut)const
{
    bool success = false ;
    
    Node<T>* pTemp = front;
    while ( pTemp != nullptr && pTemp->data < dataOut)
    {
        pTemp = pTemp->next;
    }
    if ( pTemp != nullptr && pTemp->data == dataOut)
    {
        dataOut = pTemp->data;
        success =true;
    }
    return success;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList<T>::isFull()const
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

template <typename T>
bool LinkedList<T>:: isEmpty()const
{
    bool success = true;
    
    if ( front != nullptr)
        success = false;
    
    return success;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList<T>:: getSize(T & dataOut)const
{
    bool success =  false ;
    dataOut = 0 ;
    Node<T>* pTemp =front ;
    
     while ( pTemp != nullptr)
        {
            pTemp= pTemp->next;
            dataOut++;
            success = true;
        }
    
    return success;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList<T>::counting(const T & dataIn, int & count)const
{
    bool success = false ;
    Node<T>* pTemp = front ;
    count = 0;
    
    while ( pTemp != nullptr && pTemp->data <= dataIn)
    {
        if ( pTemp->data == dataIn)
        {
            count++;
            
            success = true ;
        }
        pTemp = pTemp->next;
    }
    
    return success;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList<T>::deleteAllBut(const T & dataIn)
{
    bool success = false ;
    Node<T>* pTemp = front,
            *pPrev =nullptr;
    while ( pTemp != nullptr && pTemp->data !=dataIn)
    {
        pPrev = pTemp ;
        pTemp = pTemp-> next;
        front = pTemp ;
        delete pPrev;
    }
    while (pTemp != nullptr && pTemp->data == dataIn)
    {
        pPrev = pTemp;
        pTemp = pTemp->next;
    }
    while ( pTemp!= nullptr)
    {
        pPrev->next = pTemp->next ;
        delete pTemp;
        pTemp = pTemp->next;
        success= true;
    }
    
    
    return success;
}

//*****************************************************************************************************

template <typename T>
bool LinkedList<T>::clearList()
{
    bool success = true;
    Node<T>* pTemp = front ;
            
    
    if ( pTemp == nullptr)
        success =false;
    
    while ( front != nullptr)
    {
        front = front->next;
        delete pTemp ;
        pTemp = front;
        front = nullptr;
    }
    
   return success;
}
#endif /* LinkedList_h */
