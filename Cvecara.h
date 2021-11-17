#include <iostream>
#include "Cvet.h"
#include "Buket.h"
using namespace std;
#ifndef UNTITLED_CVECARA_H
#define UNTITLED_CVECARA_H


class Cvecara {
private:
    struct node{
        Buket* bouqet;
        node* next;
        node(Buket* b, node* s=nullptr):next(s), bouqet(b){}
    };
    Buket* bb;
    node* prvi;
    int zarada_cvecara=1000;
public:
    Cvecara(){
        prvi=nullptr;
        zarada_cvecara=1000;
    };
    Cvecara(const Cvecara &cv);
    Cvecara(Cvecara &&cv) ;
    ~Cvecara();

    void add_bouqets(Buket *b);

    void sell_bouqets(int n);


    friend ostream& operator<<(ostream &os, const Cvecara &cvec){
        os <<"ZARADA="<<cvec.zarada_cvecara<<"RSD"<<endl;
        for(Cvecara::node* tek=cvec.prvi;tek;tek=tek->next){
            os << tek->bouqet->find_name_bouqet() << endl;
        }
        return os;
    };

};


#endif //UNTITLED_CVECARA_H
