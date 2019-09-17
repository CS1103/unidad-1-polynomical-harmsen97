#ifndef PC_JERONIMO_POLYNOMIAL_H
#define PC_JERONIMO_POLYNOMIAL_H


#include "Term.h"

class Polynomial {
public:
    Term* inicial;
    Term* final;

    Polynomial();
    void add_term(float, int);
    int grade();
    Polynomial copy();
    Polynomial operator+(Polynomial&);
    Polynomial operator+(float);
    void operator+=(Polynomial&);
    void operator+=(float);

    Polynomial operator*(Polynomial&);
    Polynomial operator*(float);
    void operator*=(float);

    Polynomial operator^(int);

    void print();
};

#endif //PC_JERONIMO_POLYNOMIAL_H
