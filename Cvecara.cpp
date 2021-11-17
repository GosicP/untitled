
#include "Cvecara.h"

Cvecara::Cvecara(const Cvecara &cv) {
    prvi=nullptr;
    zarada_cvecara=cv.zarada_cvecara;
    node* tek=cv.prvi;
    node *novi;
    node *posl;
    while(tek){
        novi=new node(tek->bouqet);
        if(!prvi) prvi=novi;
        else posl->next=novi;
        posl=novi;
        tek=tek->next;
    }
}

Cvecara::~Cvecara() {
    node* tek=prvi, *stari;
    while (tek){
        stari=tek;
        tek=tek->next;
        delete stari;
    }
}

Cvecara::Cvecara(Cvecara &&cv)  {
    zarada_cvecara=cv.zarada_cvecara;
    prvi=cv.prvi;
    cv.prvi=nullptr;
}

void Cvecara::add_bouqets(Buket *b) {
    if ((b->getSellPriceBouqet()-b->getBuyPriceBouqet())>(0.2*b->getBuyPriceBouqet())) { //formula je malo upitna
        zarada_cvecara=zarada_cvecara-b->getBuyPriceBouqet();
        prvi = new node(b, prvi);
        for(node* tek=prvi;tek;tek=tek->next){
            for(node* tek2=tek;tek2;tek2=tek2->next){
                if(*tek->bouqet>*tek2->bouqet){
                    Buket* temp=tek->bouqet;
                    tek->bouqet=tek2->bouqet;
                    tek2->bouqet=temp;
                }
            }
        }
    }
}

void Cvecara::sell_bouqets(int n) {
    node *q;
    int k = 0;
    for(node* tek=prvi; tek; tek=tek->next, k++){
        if (k==n-1){
            zarada_cvecara = zarada_cvecara + tek->next->bouqet->getSellPriceBouqet();
            tek->next=tek->next->next;
            q=tek->next;
            delete(q);
        }
    }
}

/*ostream &operator<<(ostream &os, const Cvecara &cvec) {
    for(Cvecara::node* tek=cvec.prvi;tek;tek=tek->next){
        return os << tek->bouqet->getNameBouqet() << endl;
    }
}*/

