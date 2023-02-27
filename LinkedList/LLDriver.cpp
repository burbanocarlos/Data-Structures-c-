//*****************************************************************************************************
//
//              File:                   LLDriver.cpp
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
//                  Linkedlist.h
//                  Node.h
//
//*****************************************************************************************************

#include <iostream>
#include "Node.h"
#include "LinkedList.h"

//*****************************************************************************************************

int main()
{
    int del = 4 ,
    find = 6 ,
    front ,
    back,
    size,
    count;
    
    LinkedList<int> obj;
    
    if (!obj.insert(1))
        cout <<"Cannot insert" << endl;
//    if ( !obj.deleteBack(del))
//            cout <<"Cannot delete"<< endl;
//    cout <<"After inserting, display all values : " << endl;
//        if (!obj.display())
//           cout <<"Cannot display"<< endl;
    
    if (!obj.insert(4))
        cout <<"Cannot insert" << endl;
    if (!obj.insert(2))
        cout <<"Cannot insert" << endl;
    if (!obj.insert(1))
        cout <<"Cannot insert" << endl;
    if (!obj.insert(5))
        cout <<"Cannot insert" << endl;
    if (!obj.insert(6))
        cout <<"Cannot insert" << endl;
    if (!obj.insert(1))
        cout <<"Cannot insert" << endl;
    if (!obj.insert(7))
        cout <<"Cannot insert" << endl;
    if (!obj.insert(3))
        cout <<"Cannot insert" << endl;

    cout <<"After inserting, display all values : " << endl;
    if (!obj.display())
        cout <<"Cannot display"<< endl;

    cout <<"After deleting 4, display all values : " << endl;
    if(!obj.del(del))
        cout <<"Cannot delete" << endl;
    if (!obj.display())
        cout <<"Cannot display"<< endl;

    cout << endl;

    if(obj.find(find))
        cout <<"Able to find " << find << endl;
    else
        cout <<"Not able to find " << find << endl;

    find = 13;
    if(obj.find(find))
        cout <<"Able to find " << find << endl;
    else
        cout <<"Not able to find " << find << endl;

    if ( !obj.viewFront(front))
        cout <<"nothing to display"<< endl;
    cout <<"The front value is : " << front << endl;

    if ( !obj.viewBack( back))
        cout <<"nothing to display"<< endl;
    cout <<"The back value is : " << back << endl;

    cout << endl;

    if (!obj.deleteFront(del))
        cout <<"Cannot delete" << endl;
    cout <<"After deleting the front value " << del << " is removed" << endl;
    if (!obj.display())
        cout <<"Cannot display"<< endl;

    if ( !obj.deleteBack(del))
        cout <<"Cannot delete"<< endl;
    cout <<"After deleting the back value " << del << " is removed" << endl;
    if(!obj.display())
        cout << "Cannot display" << endl;

    cout << endl;

    if ( obj.isEmpty())
        cout<<"It is empty" << endl;
    else
        cout << "It is not empty" << endl;

    if ( obj.isFull())
        cout <<"It is full" << endl;
    else
        cout <<"It is not full" << endl;

    if(!obj.getSize(size))
        cout <<"No size" << endl;
    cout << "The list has "<< size << " Nodes " << endl;

    if(obj.counting(2, count))
        cout<< "The number 2 was found : " << count << " times" << endl;
    else
        cout <<"Node not found" << endl;

    cout << endl;

    if(!obj.deleteAllBut(1))
        cout <<"Cannot delete" << endl;
    cout <<"Deliting all but 1 : " << endl;
    if(!obj.display())
        cout << "Cannot display" << endl;

    cout << endl;

    cout <<"Calling clear list" << endl;
    if(!obj.clearList())
        cout <<"error"<< endl;

    if ( obj.isEmpty())
        cout<<"It is empty" << endl;
    else
        cout << "It is not empty" << endl;

    if ( obj.isFull())
        cout <<"It is full" << endl;
    else
        cout <<"It is not full" << endl;
    
    return 0;
}

//*****************************************************************************************************
/*
 OUTPUT
 After inserting, display all values :
 1 1 1 2 3 4 5 6 7
 After deleting 4, display all values :
 1 1 1 2 3 5 6 7

 Able to find 6
 Not able to find 13
 The front value is : 1
 The back value is : 7

 After deleting the front value 1 is removed
 1 1 2 3 5 6 7
 After deleting the back value 7 is removed
 1 1 2 3 5 6

 It is not empty
 It is not full
 The list has 6 Nodes
 The number 2 was found : 1 times

 Deliting all but 1 :
 1 1

 Calling clear list
 It is empty
 It is not full
 Program ended with exit code: 0
 */
