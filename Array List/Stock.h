//
//  Stock.h
//  assigment1-question4
//
//  Created by Carlos  Burbano on 2/6/22.
//

#ifndef Stock_h
#define Stock_h
#include <string>
//#include "Stock.cpp"

class Stock{
private:
    std::string name;
    std::string symbol;
    double price;

public:

    Stock(const std::string& name ="", const std::string& symbol="", double price = 0);
    Stock(const Stock&);
    void display() const;
    std::string getName() const;
    std::string getSymbol() const;
    double getPrice() const;
//    Stock& operator=(const Stock&);
    bool operator==(const Stock&) const;
    bool operator!=(const Stock&) const;
    bool operator>(const Stock&) const;
    bool operator<(const Stock&) const;
    friend std::ostream& operator<<(std::ostream&, const Stock&);
    friend std::istream& operator>>(std::istream&,  Stock&);
    int hash( int) const;

};

inline std::string Stock::getName() const {
    return name;
}

inline std::string Stock::getSymbol() const {
    return symbol;
}

inline double Stock::getPrice() const {
    return price;
}
#endif /* Stock_h */
