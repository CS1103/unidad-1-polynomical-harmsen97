#include "Polynomial.h"
#include <iostream>

int main() {
    Polynomial p, p2,p3;

    p.add_term(3,0);
    p.add_term(1,1);
    p.add_term(3,3);
    //p.add_term(5,5);

    p2.add_term(1,0);
    p2.add_term(1,1);
    p2.add_term(6,6);

    Polynomial power = p^2;


p3 = p * p2;



    power.print();
    std::cout<<std::endl;
    p3.print();
    return 0;
}