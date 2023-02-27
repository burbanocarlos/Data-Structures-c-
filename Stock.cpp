//*****************************************************************************************************
//
//              File:                   Stock.cpp
//
//              Student:                Carlos Burbano
//
//              Assignment:             Assignment # 6
//
//              Course Name:            Data Structures II
//
//              Course Number:          COSC 3100 01
//
//              Due:                    March 16, 2022
//
//
//              Other files required:
//                  BinaryTree.cpp
//                  Stock.h
//                  BinaryTree.h
//                  main.cpp
//                  Stock.txt
//
//*****************************************************************************************************

#include <iostream>
#include "Stock.h"
using namespace std;

//*****************************************************************************************************

Stock::Stock(const std::string& name, const std::string& symbol, double price)
{
    this->name = name;
    this->symbol = symbol;
    this->price = price;
}

//*****************************************************************************************************

Stock::Stock(const Stock & s){
    this->name= s.name;
    this->symbol = s.symbol;
    this->price = s.price;
}

//*****************************************************************************************************

void Stock::display()const{
    cout<< name << " " << symbol << " " << price << endl;
}

//*****************************************************************************************************

bool Stock::operator==(const Stock & rhs)const{
    bool status = false;
    if ( this->symbol == rhs.symbol){
        status = true;
    }
    return status;
}

//*****************************************************************************************************

bool Stock::operator!=(const Stock & rhs)const{
    bool status = false;

    if ( this->symbol != rhs.symbol){
        status = true;
    }

    return status;
}

//*****************************************************************************************************

bool Stock::operator<(const Stock & rhs)const{
    bool status = false;

    if (this->symbol < rhs.symbol)
        status=true;

    return status;
}

//*****************************************************************************************************

bool Stock::operator>(const Stock & rhs)const{
    bool status = false;

    if (this->symbol > rhs.symbol)
        status=true;

    return status;
}

//*****************************************************************************************************

ostream& operator <<(ostream& COUT, const Stock& rhs){
    COUT << rhs.name << " " ;
    COUT<< rhs.symbol << " " ;
    COUT<< rhs.price <<" "<< endl;
    COUT<<"--------------------";
    return COUT;
}

//*****************************************************************************************************

istream& operator >> (istream& CIN, Stock& rhs){

//    CIN.ignore(256,'\n');
    getline(CIN, rhs.name);
    getline(CIN, rhs.symbol);
//    CIN>>rhs.name;
//    CIN>>rhs.symbol;
    CIN>> rhs.price;
//    CIN.get();
    CIN.ignore();
    return CIN;
}

//*****************************************************************************************************

int Stock::hash(int size)const{

    int lenght = symbol.length();
    int key = 0 ;

    for ( int i = 0 ; i < lenght ; i++){
        key += symbol[i];
    }

    return key % size;
}

//*****************************************************************************************************