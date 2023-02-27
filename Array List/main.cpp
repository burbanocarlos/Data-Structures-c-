
#include <iostream>
#include <fstream>
#include <string>
#include "Stock.h"
#include "ArrayList.h"
using namespace std;

int main() {

    Stock stock1("Apple", "AAPL", 170.33);
    Stock stock3("Tesla", "TSLA", 846.35);
    Stock stock2("Google","GOOG", 0.013);
    Stock stock4("Nike", "NIKE", 141.59);
    Stock stock5("Disney", "DIS", 150.85);
    Stock stock6("Manzana", "PLAA", 10.33);
    Stock stock7("Microsoft", "MSFT", 278.93);
    Stock stock8("Amazon", "AMZN", 3052.03);
    Stock stock9("HP Inc", "HPQ", 36.20);
    Stock stock10("Oracle", "ORCL", 74.57);

    ifstream stockFile;
    Stock stocks;
    ArrayList<Stock> Array;


    stockFile.open("Stock.txt");

    if (stockFile.fail())
        cout<<"Error could not ope file"<< endl;
    else{
        while (stockFile>> stocks ) {

            Array.insert(stocks);
        }
        stockFile.close();
    }

    Array.insert(stock10);
    Array.insert(stock5);
    Array.insert(stock4);
    Array.insert(stock2);
    Array.print();
    cout<<"The size of the list is ";
    cout<< Array.listSize()<< endl;
    if (!Array.isFull()){cout<<"The list is not full "<< endl;}
    else{cout<<"The list is full"<< endl;}
    cout<<"--------------------"<< endl;
    int loc = Array.binarySearch(stock2);
    if( loc == -1){cout<< stock2.getName()<< " was not found"<< endl; }
    else{cout<<stock2.getName()<<" was found on location "<< loc<< endl;}
    cout<<"--------------------"<< endl;

    return 0;
}
/*
Apple AAPL 121.73
--------------------
Advanced Micro Devices AMD 84.51
--------------------
Disney DIS 150.85
--------------------
Ford Motor F 11.7
--------------------
General Electric GE 12.54
--------------------
Google GOOG 0.013
--------------------
Intel INTC 60.78
--------------------
MINE MI 222
--------------------
Motorola Inc. MOT 17.49
--------------------
Nike NIKE 141.59
--------------------
Oracle ORCL 74.57
--------------------
Tesla TSLA 564.33
--------------------
The size of the list is 12
The list is not full
--------------------
Google was found on location 6
--------------------

Process finished with exit code 0

 */
