
#include "Cvet.h"

Cvet::Cvet(string ime, int kup, int prod) {
    name=ime;
    buy_price=kup;
    sell_price=prod;
}

int Cvet::zarada() {
    profit=getSellPrice()-getBuyPrice();
    return profit;
}

bool operator==(const Cvet &c1, const Cvet &c2) {
    return c1.name==c2.name;
}

int Cvet::getBuyPrice() const {
    return buy_price;
}

void Cvet::setBuyPrice(int buyPrice) {
    buy_price = buyPrice;
}

const string &Cvet::getName() const {
    return name;
}

void Cvet::setName(const string &name) {
    Cvet::name = name;
}

int Cvet::getSellPrice() const {
    return sell_price;
}

void Cvet::setSellPrice(int sellPrice) {
    sell_price = sellPrice;
}

ostream &operator<<(ostream &os, const Cvet &c) {
    return os <<c.name;
}

/*int Cvet::getZarada() const {
    return profit;
}*/

