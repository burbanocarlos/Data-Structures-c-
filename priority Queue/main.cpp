//*****************************************************************************************************
//
//              File:                   main.cpp
//
//              Student:                Carlos Burbano
//
//              Assignment:             Assignment # 7
//
//              Course Name:            Data Structures II
//
//              Course Number:          COSC 3100 01
//
//              Due:                    March 28, 2022
//
//
//              Other files required:
//
//                  Stock.h
//                  Stock.cpp
//                  PriorityQueue.h
//                  Stock.txt
//
//*****************************************************************************************************

#include "Stock.h"
#include "PriorityQueue.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

//*****************************************************************************************************

int main() {

    Stock stock1("T-Mobile", "TMUS", 124.33);
    Stock stock3("Netflix", "NFLX", 373.35);
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
    BinaryTree<Stock> Tree;
    BinaryTree<int> numTree;
    PriorityQueue<Stock> priorityQueue;

    priorityQueue.enqueue(stock2);
    priorityQueue.enqueue(stock1);
    priorityQueue.enqueue(stock3);
    priorityQueue.enqueue(stock4);
    priorityQueue.enqueue(stock10);
    priorityQueue.enqueue(stock9);
    priorityQueue.enqueue(stock6);
    stockFile.open("Stock.txt");

    if (stockFile.fail())
        cout<<"Error could not ope file"<< endl;
    else{
        while (stockFile>> stocks ) {

            priorityQueue.enqueue(stocks);
        }
        stockFile.close();
    }

    cout<<"Display All The Stocks" << endl;
    priorityQueue.display();

    cout<<"Now lets delete 5 stocks"<< endl;
    cout<< endl;

    for ( int i = 0 ; i < 5; i++){
        cout << string(20,'-')<< endl;

        if ( priorityQueue.dequeue(stocks)){
            cout<<"Priority Queue Stock Deleted: "<< endl;
            stocks.display();
            cout << string(20,'-')<< endl;
            cout<<"After Dequeue Display: "<< endl;

            priorityQueue.display();
        }
    }
    cout<< endl;


    return 0;
}

//*****************************************************************************************************

/*
"/Users/carlosburbano/Library/Mobile Documents/com~apple~CloudDocs/Studies /programing/untitled/cmake-build-debug/untitled"
Display All The Stocks
Tesla TSLA 564.33
--------------------
Nike NIKE 141.59
--------------------
Netflix NFLX 373.35
--------------------
Apple AAPL 121.73
--------------------
Oracle ORCL 74.57
--------------------
T-Mobile TMUS 124.33
--------------------
MINE MI 222
--------------------
Google GOOG 0.013
--------------------
Advanced Micro Devices AMD 84.51
--------------------
Ford Motor F 11.7
--------------------
General Electric GE 12.54
--------------------
HP Inc HPQ 36.2
--------------------
Intel INTC 60.78
--------------------
Manzana PLAA 10.33
--------------------
Motorola Inc. MOT 17.49
--------------------
Now lets delete 5 stocks

--------------------
Priority Queue Stock Deleted:
Tesla TSLA 564.33
--------------------
After Dequeue Display:
Netflix NFLX 373.35
--------------------
Nike NIKE 141.59
--------------------
MINE MI 222
--------------------
Apple AAPL 121.73
--------------------
Oracle ORCL 74.57
--------------------
T-Mobile TMUS 124.33
--------------------
Motorola Inc. MOT 17.49
--------------------
Google GOOG 0.013
--------------------
Advanced Micro Devices AMD 84.51
--------------------
Ford Motor F 11.7
--------------------
General Electric GE 12.54
--------------------
HP Inc HPQ 36.2
--------------------
Intel INTC 60.78
--------------------
Manzana PLAA 10.33
--------------------
--------------------
Priority Queue Stock Deleted:
Netflix NFLX 373.35
--------------------
After Dequeue Display:
MINE MI 222
--------------------
Nike NIKE 141.59
--------------------
T-Mobile TMUS 124.33
--------------------
Apple AAPL 121.73
--------------------
Oracle ORCL 74.57
--------------------
Intel INTC 60.78
--------------------
Motorola Inc. MOT 17.49
--------------------
Google GOOG 0.013
--------------------
Advanced Micro Devices AMD 84.51
--------------------
Ford Motor F 11.7
--------------------
General Electric GE 12.54
--------------------
HP Inc HPQ 36.2
--------------------
Manzana PLAA 10.33
--------------------
--------------------
Priority Queue Stock Deleted:
MINE MI 222
--------------------
After Dequeue Display:
Nike NIKE 141.59
--------------------
Apple AAPL 121.73
--------------------
T-Mobile TMUS 124.33
--------------------
Advanced Micro Devices AMD 84.51
--------------------
Oracle ORCL 74.57
--------------------
Intel INTC 60.78
--------------------
Motorola Inc. MOT 17.49
--------------------
Google GOOG 0.013
--------------------
Manzana PLAA 10.33
--------------------
Ford Motor F 11.7
--------------------
General Electric GE 12.54
--------------------
HP Inc HPQ 36.2
--------------------
--------------------
Priority Queue Stock Deleted:
Nike NIKE 141.59
--------------------
After Dequeue Display:
T-Mobile TMUS 124.33
--------------------
Apple AAPL 121.73
--------------------
Intel INTC 60.78
--------------------
Advanced Micro Devices AMD 84.51
--------------------
Oracle ORCL 74.57
--------------------
HP Inc HPQ 36.2
--------------------
Motorola Inc. MOT 17.49
--------------------
Google GOOG 0.013
--------------------
Manzana PLAA 10.33
--------------------
Ford Motor F 11.7
--------------------
General Electric GE 12.54
--------------------
--------------------
Priority Queue Stock Deleted:
T-Mobile TMUS 124.33
--------------------
After Dequeue Display:
Apple AAPL 121.73
--------------------
Advanced Micro Devices AMD 84.51
--------------------
Intel INTC 60.78
--------------------
General Electric GE 12.54
--------------------
Oracle ORCL 74.57
--------------------
HP Inc HPQ 36.2
--------------------
Motorola Inc. MOT 17.49
--------------------
Google GOOG 0.013
--------------------
Manzana PLAA 10.33
--------------------
Ford Motor F 11.7
--------------------


Process finished with exit code 0


 */
