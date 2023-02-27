//*****************************************************************************************************
//
//              File:                   Simulation.cpp
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
//                  Queue.h
//                  Cashier.h
//                  Customer.h
//                  customerList.txt
//
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include "Queue.h"
#include "Cashier.h"
#include "Customer.h"

using namespace std;

//*****************************************************************************************************

void fillCustomerQueue (Customers *, Cashiers*, Queue<Customers> & , int, int & );
void processCustomer ( Customers *, Cashiers*, Queue<Customers> & , int);
bool isDone ( Cashiers * , int , Queue<Customers> &);

int main()
{
Customers array[50];
Queue<Customers> custList;
Cashiers cashiers [3];
int  time = 0,
        i = 0 ,
     indez = 0 ;

    ifstream list ;
    list.open("customerList.txt");

    if ( list.fail())
        cout << "[WARNING], file cannot be open" << endl;

    else
    {
        while (list >> array[i].id) {

            list >> array[i].arrivalTime;
            list >> array[i].serviceTime;
            i++;
        }

        do
        {
            cout << endl;
            cout << "t = " << time << endl;
            fillCustomerQueue(array, cashiers,custList,time,indez);
            processCustomer(array, cashiers, custList, time);
            time++;

        }while (isDone(cashiers, time, custList));

        list.close();
    }

    return 0;
}

//*****************************************************************************************************

void fillCustomerQueue (Customers* array ,Cashiers *data , Queue<Customers> & custLIst  , int time , int  & index )
{

            while(array[index].arrivalTime == time) {

                custLIst.enqueue(array[index]);
                cout << "Customer # " << array[index].id << " added to the queue" << endl;
                index++;

            }

    }

//*****************************************************************************************************

void processCustomer ( Customers *array, Cashiers*data, Queue<Customers> & custList , int time)
{
    Customers cust ;

    for ( int i = 0 ; i < 3 ; i++)
    {

        if ( data[i].busy == 0  || data[i].endTime == time )

        {

            if (custList.dequeue(cust)) {
                data[i].custId = cust.id;
                data[i].endTime = time + cust.serviceTime;
                data[i].busy = true;
                cout << "Cashier # " << i + 1 << " starts serving customer # " << cust.id << ", ";
                cout << "time lenght is " << data[i].endTime<< ", ";
                cout << " service ends at t =  " << data[i].endTime << endl;
            }

            else
            {
                cout << "Cashier #" << i + 1 << " is not busy " <<endl;
                data[i].busy = false;
            }


        }
        else
        {
            cout <<"Cashier # " << i + 1 << " is servig customer # " << data[i].custId << " until t = " << data[i].endTime << endl;
        }


    }


}

//*****************************************************************************************************

bool isDone ( Cashiers * serv , int time, Queue<Customers> & custList)
{
    bool check = false;

    for (int i = 0; !check && i < 3; i++)
    {
        check = custList.isEmpty() && serv[i].busy;
    }

    return check;
}

//*****************************************************************************************************
/*
 * OUTPUT
 * "/Users/carlosburbano/Documents/programing /Data Structures I /assigment 11/cmake-build-debug/assigment_11"

t = 0
Customer # 1 added to the queue
Customer # 2 added to the queue
Cashier # 1 starts serving customer # 1, time lenght is 15,  service ends at t =  15
Cashier # 2 starts serving customer # 2, time lenght is 3,  service ends at t =  3
Cashier #3 is not busy

t = 1
Customer # 3 added to the queue
Cashier # 1 is servig customer # 1 until t = 15
Cashier # 2 is servig customer # 2 until t = 3
Cashier # 3 starts serving customer # 3, time lenght is 3,  service ends at t =  3

t = 2
Cashier # 1 is servig customer # 1 until t = 15
Cashier # 2 is servig customer # 2 until t = 3
Cashier # 3 is servig customer # 3 until t = 3

t = 3
Customer # 4 added to the queue
Customer # 5 added to the queue
Cashier # 1 is servig customer # 1 until t = 15
Cashier # 2 starts serving customer # 4, time lenght is 4,  service ends at t =  4
Cashier # 3 starts serving customer # 5, time lenght is 7,  service ends at t =  7

t = 4
Cashier # 1 is servig customer # 1 until t = 15
Cashier #2 is not busy
Cashier # 3 is servig customer # 5 until t = 7

t = 5
Cashier # 1 is servig customer # 1 until t = 15
Cashier #2 is not busy
Cashier # 3 is servig customer # 5 until t = 7

t = 6
Cashier # 1 is servig customer # 1 until t = 15
Cashier #2 is not busy
Cashier # 3 is servig customer # 5 until t = 7

t = 7
Cashier # 1 is servig customer # 1 until t = 15
Cashier #2 is not busy
Cashier #3 is not busy

t = 8
Cashier # 1 is servig customer # 1 until t = 15
Cashier #2 is not busy
Cashier #3 is not busy

t = 9
Cashier # 1 is servig customer # 1 until t = 15
Cashier #2 is not busy
Cashier #3 is not busy

t = 10
Cashier # 1 is servig customer # 1 until t = 15
Cashier #2 is not busy
Cashier #3 is not busy

t = 11
Cashier # 1 is servig customer # 1 until t = 15
Cashier #2 is not busy
Cashier #3 is not busy

t = 12
Cashier # 1 is servig customer # 1 until t = 15
Cashier #2 is not busy
Cashier #3 is not busy

t = 13
Cashier # 1 is servig customer # 1 until t = 15
Cashier #2 is not busy
Cashier #3 is not busy

t = 14
Cashier # 1 is servig customer # 1 until t = 15
Cashier #2 is not busy
Cashier #3 is not busy

t = 15
Cashier #1 is not busy
Cashier #2 is not busy
Cashier #3 is not busy

Process finished with exit code 0

 */