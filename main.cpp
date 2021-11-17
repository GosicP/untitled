#include <iostream>
#include "Cvet.h"
#include "Buket.h"
#include "Cvecara.h"
using namespace std;
int main() {
    Cvecara cvec;
    Buket b1, b2,b3;
    Cvet c1("maslacak", 200, 700), c2("nzmmajkemi", 300, 600), c3("karanfil", 400, 500)
    , c4("ruza", 100, 900);
    /*cout<<(c1==c2)<<endl;
    cout<<c1<<endl;*/
    b2.addflowers(&c1);
    b2.addflowers(&c2);
    b2.addflowers(&c3);
    //b2.addflowers(&c3);
    b3.addflowers(&c2);
    b3.addflowers(&c3);
    b1.addflowers(&c1);
    b1.addflowers(&c4);
    /*cout<<b2.getProfitBouqet()<<endl;
    cout<<(b1<b2)<<endl;*/
    cout<<b1;
    cout<<b2;
    cout<<b3;
    cvec.add_bouqets(&b2);
    cvec.add_bouqets(&b3);
    cvec.add_bouqets(&b1);
    //cvec.sell_bouqets(2);
    //cvec.add_bouqets(&b1);
    cout<<cvec;
}
