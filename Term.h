#ifndef PC_JERONIMO_TERM_H
#define PC_JERONIMO_TERM_H

struct Term{

    float coeficiente = 0;
    char variable = 'x';
    int exponente = 0;

    Term* next= nullptr;
};

#endif //PC_JERONIMO_TERM_H
