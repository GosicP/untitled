#include <iostream>
using namespace std;
#ifndef UNTITLED_BUKET_H
#define UNTITLED_BUKET_H
#include "Cvet.h"

class Buket {
protected:
    struct node{
        Cvet* flower;
        node* next;
        node(Cvet* cv, node* s=nullptr):next(s), flower(cv){}
    };
    Cvet* c;
    node *prvi=nullptr;
    node *prvinovi=nullptr;
    string name_bouqet;
    int buy_price_bouqet=0, profit_bouqet=0;
    int sell_price_bouqet = 0;
public:
    Buket()=default;
    Buket(const Buket& b);
    Buket(Buket &&b);
    ~Buket();

    int getBuyPriceBouqet() const;

    int getSellPriceBouqet() const;

    int getProfitBouqet() const;

    const string &getNameBouqet() const;

    string find_name_bouqet(){
        int br=0;
        int br2=0;
        node* novi;
        for (node* tek=prvi; tek; tek=tek->next){
            if (br==0){
                novi=prvi;
                name_bouqet=tek->flower->getName();
                br++;
            }else{
                for(node* tek2=novi; tek2; tek2=tek2->next){
                    if(tek2->flower->getName()==tek->flower->getName()){
                        novi=tek;
                        br2++;
                    }
                    if(br2==0){
                        name_bouqet=name_bouqet+", "+tek->flower->getName();
                    }
                }
                br2=0;
            }
        }
        return name_bouqet;
    };

    void addflowers(Cvet *c);

    friend bool operator>(Buket &b1, Buket &b2);

    friend ostream& operator<<(ostream &os, Buket &b);

};


#endif
