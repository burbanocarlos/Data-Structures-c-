//
//  AStack.hpp
//  assigment#8
//
//  Created by Carlos  Burbano on 11/4/21.
//

#ifndef AStack_hpp
#define AStack_hpp

#include <stdio.h>
//*****************************************************************************************************
//
//              File:                   AStack.h
//
//              Student:                Carlos Burbano
//
//              Assignment:             Assignment # 7
//
//              Course Name:            Data Structures I
//
//              Course Number:          COSC 3050 01
//
//              Due:                    Nov 1, 2021
//
//
//              This program build a stack with an array List
//
//
//              Other files required:
//                  AStackDriver.cpp
//
//*****************************************************************************************************

#ifndef AStack_h
#define AStack_h

//*****************************************************************************************************

template <typename T >
class Stack
{
private:
    T* stack;
    int top ;
    int capacity;
    
public:
    Stack( int c = 100);
    ~Stack();
    bool push( const T & );
    bool pop (T &);
    bool peek (T &)const;
    bool isEmpty() const;
    bool clearStack();
    bool isFull()const;
    int getSize()const;

};

//*****************************************************************************************************

template <typename T >
Stack<T>:: Stack( int c )
{
    capacity = c ;
    top = - 1 ;
    stack = new T [capacity];
}

//*****************************************************************************************************

template <typename T >
Stack<T>:: ~Stack()
{
    capacity = 0;
    top = -1 ;
    delete [] stack;
    stack =nullptr;
}

//*****************************************************************************************************

template <typename T >
bool Stack<T>:: push(const T& dataIn)
{
    bool success = false ;
    
    if ( capacity > top +1)
        {
        
            stack[++top] = dataIn;
            success = true ;
        
        }
    return success;
}

//*****************************************************************************************************

template <typename T >
bool Stack<T>:: pop(T & dataOut)
{
    bool success = false ;
    
    if ( top > -1)
    {
        dataOut = stack[top--];
        //top--;
        success = true ;
    }
    return success;
}

//*****************************************************************************************************

template <typename T >
bool Stack<T>:: peek(T &dataOut) const
{
    bool success = true ;
    
    if ( top > -1)
    {
        dataOut = stack[top];
        success = true ;
    }
    
    return success;
}

//*****************************************************************************************************

template <typename T >
bool Stack<T>:: isEmpty()const
{
    
    return top == -1;
}

//*****************************************************************************************************

template <typename T >
bool Stack<T>:: clearStack()
{
    bool success = false;
    
    if ( top > -1)
    {
        top = -1 ;
        success = true;
    }
    
    return success;
}

//*****************************************************************************************************

template <typename T >
int Stack<T>::getSize()const
{
    return top + 1;
}

//*****************************************************************************************************

template <typename T >
bool Stack<T>:: isFull()const
{
    bool success = false;
    
    if ( top == capacity -1)
        success = true;
    
    return success;
}

//*****************************************************************************************************

#endif /* AStack_h */

#endif /* AStack_hpp */
