//*****************************************************************************************************
//
//              File:                   main.cpp
//
//              Student:                Carlos Burbano
//
//              Assignment:             Assignment # 8
//
//              Course Name:            Data Structures II
//
//              Course Number:          COSC 3100 01
//
//              Due:                    April 5, 2022
//
//
//              Other files required:
//
//                  Stock.h
//                  Stock.cpp
//                  AVLTree.h
//                  Stock.txt
//
//*****************************************************************************************************

#include "Stock.h"
#include "AVLTree.h"
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


    AVLTree <Stock> avlTree;
    AVLTree<int> numTree;
    fstream stockFile;
    Stock stocks;
    Stock * stockPointer;
    string  stockSymbol;
    string stockName;
    double stockPrice;
    char choice;

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

    stockFile.open("Stock.txt");
    if (stockFile.fail())
        cout<<"Error could not ope file"<< endl;
    else{
        while ( stockFile >> stocks) {

            avlTree.insert(stocks);

        }
        stockFile.close();
    }

    avlTree.insert(stock1);

    cout<<"Display All The Stocks" << endl;
    avlTree.preOrder();
    cout << avlTree.height();

    do{
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
            stocks.setSymbol(stockSymbol);
            stockPointer = avlTree.search(stocks);

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
            stocks.setSymbol(stockSymbol);
            stockPointer = avlTree.search(stocks);
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
            stocks.setName(stockName);
            stocks.setSymbol(stockSymbol);
            stocks.setPrice(stockPrice);
            avlTree.insert(stocks);
            cout << "Stock inserted" << endl;
        }
        else if ( choice == 'd'){
            cout << "displaying Stocks :" << endl;
            avlTree.inOrder();
        }

    } while ( choice != 'e');

    if ( choice == 'e'){
        ofstream writeFile;
        writeFile.open("writeStock.txt");
        if ( writeFile.fail()){
            cout<<"could not write into file"<< endl;
        }
        else{
            cout<<"Finishing the Program...Writing into File"<< endl;
            avlTree.write(writeFile);
            writeFile.close();
        }

    }


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
2710
2545
2924
3931

post order

250
74
1273
879
3659
2710
2545
2924
3931
1808

The height of tree is: 4

Tree Deleted
Display All The Stocks
General Electric GE 12.54
--------------------
Advanced Micro Devices AMD 84.51
--------------------
Apple AAPL 121.73
--------------------
Ford Motor F 11.7
--------------------
MINE MI 222
--------------------
Intel INTC 60.78
--------------------
Motorola Inc. MOT 17.49
--------------------
T-Mobile TMUS 124.33
--------------------
4
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
Please enter Stock Symbol:INTC
The Stock was found
the stock price is: 60.78

Pick from the following options:
a) Display a stock’s name given its symbol
b) Display a stock’s price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
a
Please enter Stock Symbol:ff
the stock was not found

Pick from the following options:
a) Display a stock’s name given its symbol
b) Display a stock’s price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
c
insert a new stock
Enter Stock name -Disney
Enter stock Symbol -DIS
Enter Stock price -150.85
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
Disney DIS 150.85
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
T-Mobile TMUS 124.33
--------------------

Pick from the following options:
a) Display a stock’s name given its symbol
b) Display a stock’s price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
e
Finishing the Program...Writing into File

Process finished with exit code 0


 */
