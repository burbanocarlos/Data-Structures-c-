//*****************************************************************************************************
//
//              File:                   Cashier.h
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
//                  Customer.h
//                  customerList.txt
//
//*****************************************************************************************************

struct Cashiers
{
    int custId;
    int endTime;
    bool busy;

    Cashiers();
};

//*****************************************************************************************************

Cashiers::Cashiers()
{
    custId = 0;
    endTime = 0;
    busy = 0;
}

//*****************************************************************************************************

#endif //ASSIGMENT_11_CASHIER_H
