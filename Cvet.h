

#ifndef UNTITLED_CVET_H
#define UNTITLED_CVET_H
#include <iostream>
using namespace std;

class Cvet {
private:
    string name;
    int buy_price, sell_price, profit;
public:
    int getBuyPrice() const;

    void setBuyPrice(int buyPrice);

    const string &getName() const;

    void setName(const string &name);

    int getSellPrice() const;

    void setSellPrice(int sellPrice);

    Cvet(string ime, int kup, int prod);

    int zarada();

    /*int getZarada() const;*/

    friend bool operator==(const Cvet &c1, const Cvet &c2);

    friend ostream& operator<<(ostream &os, const Cvet &c);
};


#endif
