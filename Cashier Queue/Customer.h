//*****************************************************************************************************
//
//              File:                   Customer.h
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
//                  Simulation.cpp
//                  Cashier.h
//                  customerList.txt
//
//*****************************************************************************************************

struct Customers
{
    int id ;
    int arrivalTime;
    int serviceTime ;
    Customers();
};

//*****************************************************************************************************

Customers::Customers()
{
    id = 0 ;
    arrivalTime = 0 ;
    serviceTime = 0 ;
}

//*****************************************************************************************************

#endif //ASSIGMENT_11_CUSTOMER_H
