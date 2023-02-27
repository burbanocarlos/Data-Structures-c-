//*****************************************************************************************************
//
//              File:                   QueueDriver.cpp
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
//                  Node.h
//                  Queue.h
//
//*****************************************************************************************************
#include <iostream>
#include <iomanip>
#include "Queue.h"

using namespace std;

//*****************************************************************************************************


void addValue (Queue<int> & , int [] , const int );
void displayQueue ( Queue<int> &);
double getAvg (Queue<int> &);
void clearQueue( Queue<int> &);

//*****************************************************************************************************

int main() {
    
    int array[] ={3,7,9,12,33,51,67,89,1,42,11};
    
    int size = 11;
    
    Queue<int> queue;
    
    
    int size2  ;
    
    cout << string(12,'*') << "Add The Values : " << string(12,'*') << endl;
    cout << endl;
    
    addValue(queue, array, size);
    displayQueue(queue);
    cout << endl;
    
    cout << "Now Queue is : ";
    if (!queue.isEmpty())
        cout << "Not Empty" << endl;
    else
        cout << "Empty " << endl;
    
    cout << "Average is : ";
    cout <<  getAvg(queue)<< endl;
    
    cout <<"Front Value Is : ";
    if (!queue.viewFront(size2))
        cout <<"[WARNING], cannot display front" << endl;
    else
        cout << size2 << endl;
    
    cout <<"Rear Value is : ";
    if (!queue.viewBack(size2))
        cout <<"[WARNING], cannot display rear" << endl;
    else
        cout << size2 << endl;
    
    cout <<"Size is : ";
    cout << queue.getSize() << endl;
    cout << endl;
    
    cout << string(12,'*') << "Clear The Queue : " << string(12,'*') << endl;
    cout << endl;
    
    clearQueue(queue);
    cout <<"Now Queue is : ";
    if (!queue.isEmpty())
        cout << "Not Empty" << endl;
    else
        cout << "Empty. " << endl;
    cout << endl;
    
   
    return 0;
}

//*****************************************************************************************************

void addValue ( Queue<int> & queue , int  array[] , const int size)
{
    bool checker = true;
    
    for ( int i = 0 ; checker && i < size ; i++)
    {
        if (!queue.enqueue(array[i]))
            checker = false;
        
    }
    
    if ( !checker)
        cout << "[WARNING, could not add to queue]" << endl;
    
}

//*****************************************************************************************************

void displayQueue( Queue<int> & queue)
{
    Queue<int>  temp;
    
    int     data = { },
            size = queue.getSize();
    
    bool    checker = true;
    
    for ( int i = 0 ; checker &&  i < size; i++)
    {
        
        if (!queue.dequeue(data) )
            checker =false;
        
        if(!temp.enqueue(data))
           checker = false;
        
    }
    for ( int i = 0 ; checker && i < size ; i++)
    {
        if(!temp.dequeue(data))
            checker = false;
        
        cout << data << " " ;
        
        if (!queue.enqueue(data))
            checker = false;
    }
}

//*****************************************************************************************************

double getAvg ( Queue<int> & queue)
{
    int     size = queue.getSize(),
            data = { };
    
    double  average,
    sum= 0 ;
    
    Queue<int> temp;
    
    bool checker = true;
    
    for ( int i = 0 ; checker && i < size ; i++ )
    {
        if (!queue.dequeue(data))
            checker = false;
        sum +=data;
        
        if(!temp.enqueue(data))
            checker = false;
    }
    
    for ( int i = 0 ; checker && i < size ; i++)
    {
        
        if(!temp.dequeue(data))
            checker = false;
        
        if (!queue.enqueue(data))
            checker = false;
    }
    cout << fixed << showpoint << setprecision(4);
    average = sum/size;
    
    return average;
}

//*****************************************************************************************************

void clearQueue ( Queue<int> & queue)
{
    int     size = queue.getSize(),
            data = { };
    
    bool checker = true;
    
    for ( int i = 0 ; checker && i < size ; i++ )
    {
        
        if (!queue.dequeue(data))
            checker = false;
    }
}

//*****************************************************************************************************

/*
 OUTPUT
 
 ************Add The Values : ************

 3 7 9 12 33 51 67 89 1 42 11
 Now Queue is : Empty :
 Average is : 29.5455
 Front Value Is : 3
 Rear Value is : 11
 Size is : 11

 ************Clear The Queue : ************

 Now Queue is : Not Empty

 Program ended with exit code: 0
 */
