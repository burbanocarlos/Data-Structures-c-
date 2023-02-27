//*****************************************************************************************************
//
//              File:                   BinaryTree.h
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
//                  Stock.cpp
//                  main.cpp
//                  Stock.txt
//
//*****************************************************************************************************

#include "Stock.h"
#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//*****************************************************************************************************

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
    BinaryTree<Stock> Tree;
    BinaryTree<int> numTree;

    stockFile.open("Stock.txt");

    for ( int i = 0 ; i < 10 ; i++){
        int v1 = (rand() %5000) + 1 ;
        numTree.insert(v1);
    }

    numTree.inOrder();
    cout<<endl;
    cout<<"pre order"<< endl;
    cout<<endl;
    numTree.preOrder();
    cout<<endl;
    cout<<"post order"<< endl;
    cout<<endl;
    numTree.postOrder();
    cout<< endl;
    cout<<"The height of tree is: " ;
    cout << numTree.height() << endl;
    cout<<endl;
    numTree.deleteTree();
    cout<<"Tree Deleted"<<endl;

    if (stockFile.fail())
        cout<<"Error could not ope file"<< endl;
    else{
        while (stockFile>> stocks ) {

            Tree.insert(stocks);
        }
        stockFile.close();
    }

   string  stockSymbol;
   string stockName;
   double stockPrice;
   Stock * stockPointer;
    Stock tempStock;
    char choice;

    do {
        cout<< endl;
        cout << "Pick from the following options: " << endl;
        cout << "a) Display a stock’s name given its symbol \n"
                "b) Display a stock’s price given its symbol \n"
                "c) Insert a new stock \n"
                "d) Display all stocks \n"
                "e) Quit" << endl;

        cin >> choice;
        if (choice == 'a') {
            cout << "Please enter Stock Symbol:";
            cin >> stockSymbol;
            tempStock.setSymbol(stockSymbol);
            stockPointer = Tree.search(tempStock);
            if (stockPointer != nullptr) {
                cout << "The Stock was found \n"
                        "the stock's name is: ";
                cout << stockPointer->getName() << endl;
            } else
                cout << "the stock was not found" << endl;
        }
        else if (choice == 'b') {
            cout << "Please enter Stock Symbol:";
            cin >> stockSymbol;
            tempStock.setSymbol(stockSymbol);
            stockPointer = Tree.search(tempStock);
            if (stockPointer != nullptr) {
                cout << "The Stock was found \n"
                        "the stock price is: ";
                cout << stockPointer->getPrice() << endl;
            } else
                cout << "the stock was not found" << endl;
        }
        else if (choice == 'c') {

            cout << "insert a new stock" << endl;
            cout << "Enter Stock name -";
            cin >> stockName;
            cout << "Enter stock Symbol -";
            cin >> stockSymbol;
            cout << "Enter Stock price -";
            cin >> stockPrice;
            tempStock.setName(stockName);
            tempStock.setSymbol(stockSymbol);
            tempStock.setPrice(stockPrice);
            Tree.insert(tempStock);
            cout << "Stock inserted" << endl;
        }
        else if (choice == 'd') {

        cout << "displaying Stocks :" << endl;
        Tree.inOrder();
         }


    } while (choice != 'e');


    cout<< endl;

    return 0;
}

//*****************************************************************************************************

/*
"/Users/carlosburbano/Library/Mobile Documents/com~apple~CloudDocs/Studies /programing/untitled/cmake-build-debug/untitled"
74
250
879
1273
1808
2545
2710
2924
3659
3931

pre order

1808
250
74
1273
879
3659
2545
2924
2710
3931

post order

250
74
1273
879
3659
2545
2924
2710
3931
1808

The height of tree is: 5

Tree Deleted

Pick from the following options:
a) Display a stock’s name given its symbol
b) Display a stock’s price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
a
Please enter Stock Symbol:MOT
The Stock was found
the stock's name is: Motorola Inc.

Pick from the following options:
a) Display a stock’s name given its symbol
b) Display a stock’s price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
b
Please enter Stock Symbol:MOT
The Stock was found
the stock price is: 17.49

Pick from the following options:
a) Display a stock’s name given its symbol
b) Display a stock’s price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
d
displaying Stocks :
Apple AAPL 121.73
--------------------
Advanced Micro Devices AMD 84.51
--------------------
Ford Motor F 11.7
--------------------
General Electric GE 12.54
--------------------
Intel INTC 60.78
--------------------
MINE MI 222
--------------------
Motorola Inc. MOT 17.49
--------------------
Tesla TSLA 564.33
--------------------

Pick from the following options:
a) Display a stock’s name given its symbol
b) Display a stock’s price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
c
insert a new stock
Enter Stock name -Oracle
Enter stock Symbol -ORCL
Enter Stock price -75.57
Stock inserted

Pick from the following options:
a) Display a stock’s name given its symbol
b) Display a stock’s price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
d
displaying Stocks :
Apple AAPL 121.73
--------------------
Advanced Micro Devices AMD 84.51
--------------------
Ford Motor F 11.7
--------------------
General Electric GE 12.54
--------------------
Intel INTC 60.78
--------------------
MINE MI 222
--------------------
Motorola Inc. MOT 17.49
--------------------
Oracle ORCL 75.57
--------------------
Tesla TSLA 564.33
--------------------

Pick from the following options:
a) Display a stock’s name given its symbol
b) Display a stock’s price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
e


Process finished with exit code 0


 */
