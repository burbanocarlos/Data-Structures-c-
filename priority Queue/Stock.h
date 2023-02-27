//*****************************************************************************************************
//
//              File:                   Stock.h
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
//                  Stock.cpp
//                  PriorityQueue.h
//                  main.cpp
//                  Stock.txt
//
//*****************************************************************************************************

#ifndef Stock_h
#define Stock_h
#include <string>


class Stock{
private:
    std::string name;
    std::string symbol;
    double price;

public:

    Stock(const std::string& name ="", const std::string& symbol="", double price = 0);
    Stock(const Stock&);
    void display() const;
    void setSymbol( std::string);
    void setPrice( double);
    void setName(std::string);
    std::string getName() const;
    std::string getSymbol() const;
    double getPrice() const;
    bool operator==(const Stock&) const;
    bool operator!=(const Stock&) const;
    bool operator>(const Stock&) const;
    bool operator<(const Stock&) const;
    friend std::ostream& operator<<(std::ostream&, const Stock&);
    friend std::istream& operator>>(std::istream&,  Stock&);
    int hash( int) const;


};

//*****************************************************************************************************

inline std::string Stock::getName() const {
    return name;
}

//*****************************************************************************************************

inline std::string Stock::getSymbol() const {
    return symbol;
}

//*****************************************************************************************************

inline double Stock::getPrice() const {
    return price;
}

//*****************************************************************************************************

inline void Stock::setSymbol(std::string symbol ) {
    this->symbol = symbol;
}

//*****************************************************************************************************

inline void Stock::setName(std::string name) {
    this->name = name;
}

//*****************************************************************************************************

inline void Stock::setPrice(double price) {
    this->price = price;
}

//*****************************************************************************************************
#endif /* Stock_h */
