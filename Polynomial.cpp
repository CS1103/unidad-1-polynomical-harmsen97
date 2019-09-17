#include <iostream>
#include "Polynomial.h"

Polynomial::Polynomial() {
    this->inicial = nullptr;
    this->final = nullptr;
}

void Polynomial::add_term(float coeficiente, int exponente) {

    Term* new_term = new Term();
    new_term->coeficiente = coeficiente;
    new_term->exponente = exponente;

    if(inicial == nullptr) {
        inicial = new_term;
        final = new_term;
    }
    else{
        if(new_term->exponente < inicial->exponente){
            new_term->next = inicial;
            inicial = new_term;
        }
        else if(new_term->exponente > final->exponente){
            final->next = new_term;
            final = new_term;
        }
        else{
            Term* tmp = inicial;
            if(tmp->exponente == new_term->exponente)
                tmp->coeficiente += new_term->coeficiente;
            else{
                while(tmp->next->exponente < new_term->exponente){
                    tmp = tmp->next;
                }
                if(tmp->next->exponente == new_term->exponente)
                    tmp->next->coeficiente += new_term->coeficiente;
                else{
                    new_term->next = tmp->next;
                    tmp->next = new_term;
                }
            }
        }
    }
}

int Polynomial::grade() {
    return final->exponente;
}

Polynomial Polynomial::copy() {
    Polynomial polynomial;
    Term* tmp = this->inicial;
    while(tmp!=this->final){
        polynomial.add_term(tmp->coeficiente, tmp->exponente);
        tmp = tmp->next;
    }
    polynomial.add_term(tmp->coeficiente, tmp->exponente);

    return polynomial;
}

Polynomial Polynomial::operator+(Polynomial& polynomial2) {
    Polynomial sum;

    Term* it1=this->inicial;
    while(it1 != nullptr){
        sum.add_term(it1->coeficiente,it1->exponente);
        it1 = it1->next;
    }
    delete it1;

    Term* it2=polynomial2.inicial;
    while(it2 != nullptr){
        sum.add_term(it2->coeficiente, it2->exponente);
        it2 = it2->next;
    }
    delete it2;

    return sum;
}

void Polynomial::operator+=(Polynomial &polynomial2) {
    Term* tmp = polynomial2.inicial;
    while(tmp != nullptr){
        this->add_term(tmp->coeficiente,tmp->exponente);
        tmp = tmp->next;
    }
    delete tmp;
}

Polynomial Polynomial::operator+(float constant) {
    Polynomial sum = this->copy();
    sum.add_term(constant,0);
    return sum;
}

void Polynomial::operator+=(float constant) {
    this->add_term(constant, 0);
}

Polynomial Polynomial::operator*(Polynomial& polynomial2) {
    Term* it1 = this->inicial;
    Term* it2 = nullptr;
    Polynomial prod;
    while(it1 != nullptr){
        it2 = polynomial2.inicial;
        while(it2 != nullptr){
            prod.add_term(it1->coeficiente*it2->coeficiente, it1->exponente+it2->exponente);
            it2 = it2->next;
        }
        it1 = it1->next;
    }
    return prod;
}

Polynomial Polynomial::operator*(float constant) {
    Polynomial prod = this->copy();
    Term* tmp = prod.inicial;
    while(tmp != nullptr){
        tmp->coeficiente*=constant;
        tmp = tmp->next;
    }
    delete tmp;
    return prod;
}

void Polynomial::operator*=(float constant) {
    Term* tmp = this->inicial;
    while(tmp != nullptr){
        tmp->coeficiente *= constant;
        tmp = tmp->next;
    }
    delete tmp;
}

void Polynomial::print() {
    Term* tmp = this->inicial;
    while(tmp != nullptr){
        std::cout<< tmp->coeficiente;

        if(tmp->exponente)
            std::cout<<tmp->variable<<'^'<<tmp->exponente;
        if(tmp!=final)
            std::cout<<" + ";

        tmp = tmp->next;
    }
}

Polynomial Polynomial::operator^(int n) {
    Polynomial pow = this->copy();
    for(int i=1;i<n;++i)
        pow = *this * pow;
    return pow;
}