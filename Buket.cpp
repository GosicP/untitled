
#include <iostream>
using namespace std;
#include "Buket.h"

Buket::Buket(const Buket &b) {
    buy_price_bouqet=b.buy_price_bouqet;
    sell_price_bouqet=b.sell_price_bouqet;
    node* tek=b.prvi;
    node *novi;
    node *posl;
    while(tek){
        novi=new node(tek->flower);
        if(!prvi) prvi=novi;
        else posl->next=novi;
        posl=novi;
        tek=tek->next;
    }
}

Buket::Buket(Buket &&b){
    buy_price_bouqet=b.buy_price_bouqet;
    sell_price_bouqet=b.sell_price_bouqet;
    prvi=b.prvi;
    b.prvi=nullptr;
}

Buket::~Buket() {
    node* tek=prvi, *stari;
    while (tek){
        stari=tek;
        tek=tek->next;
        delete stari;
    }
}

void Buket::addflowers(Cvet *c) {
    prvi=new node(c, prvi);
    //name_bouqet = c->getName() + " ";
    buy_price_bouqet=buy_price_bouqet+c->getBuyPrice();
    sell_price_bouqet=sell_price_bouqet+c->getSellPrice();
    profit_bouqet=profit_bouqet+c->zarada();
}

bool operator>(Buket &b1, Buket &b2) {
    return b1.sell_price_bouqet>b2.sell_price_bouqet;
}

ostream &operator<<(ostream &os, Buket &b) {
    return os<<"("<< b.find_name_bouqet()<<") "<<b.sell_price_bouqet<<endl;
}

int Buket::getBuyPriceBouqet() const {
    return buy_price_bouqet;
}

int Buket::getSellPriceBouqet() const {
    return sell_price_bouqet;
}

int Buket::getProfitBouqet() const {
    return profit_bouqet;
}

const string &Buket::getNameBouqet() const {
    return name_bouqet;
}

