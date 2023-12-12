#pragma once
#ifndef FRACTIE_H
#define FRACTIE_H
#include <iostream>

class Fractie {
private:
    int numarator;
    int numitor;

public:
    Fractie();                                 // Constructor implicit
    Fractie(int _numarator);                   // Constructor cu un parametru (numarator)
    Fractie(int _numitor, int _numarator);    // Constructor cu doi parametri (numitor și numarator)
    Fractie(const Fractie& other);            // Constructor de copiere

    Fractie adunare(const Fractie& other) const;    // Metoda pentru adunare cu o alta fractie
    Fractie scadere(const Fractie& other) const;    // Metoda pentru scădere
    Fractie inmultire(const Fractie& other) const;  // Metoda pentru înmulțire a două fracții
    Fractie impartire(const Fractie& other) const;  // Metoda pentru împărțire
    Fractie reciproc() const;                       // Metoda pentru calculul reciprocului
    void simplifica();                              // Metoda pentru simplificarea fractiei
    void afisare() const;                           // Metoda pentru afișare
    bool egal(const Fractie& other) const;         // Metoda pentru compararea a două fracții

    // Funcții membre pentru suprascrierea operatorilor
    Fractie operator+(const Fractie& other) const;
    Fractie operator-(const Fractie& other) const;
    Fractie operator*(const Fractie& other) const;
    Fractie operator/(const Fractie& other) const;
    bool operator<(const Fractie& other) const;
    bool operator>(const Fractie& other) const;
    bool operator<=(const Fractie& other) const;
    bool operator>=(const Fractie& other) const;
    bool operator==(const Fractie& other) const;
    bool operator!=(const Fractie& other) const;

    static int cmmdc(int a, int b); // Metoda statică pentru CMMDC a două numere întregi

    /*
    // Funcții prietene pentru suprascrierea operatorilor
    friend Fractie operator+(const Fractie& frac1, const Fractie& frac2);
    friend Fractie operator-(const Fractie& frac1, const Fractie& frac2);
    friend Fractie operator*(const Fractie& frac1, const Fractie& frac2);
    friend Fractie operator/(const Fractie& frac1, const Fractie& frac2);
    friend bool operator<(const Fractie& frac1, const Fractie& frac2);
    friend bool operator>(const Fractie& frac1, const Fractie& frac2);
    friend bool operator<=(const Fractie& frac1, const Fractie& frac2);
    friend bool operator>=(const Fractie& frac1, const Fractie& frac2);
    friend bool operator==(const Fractie& frac1, const Fractie& frac2);
    friend bool operator!=(const Fractie& frac1, const Fractie& frac2);
    */


    // Functii membre pentru operatorii +=,-=,*=,/=,++,--
    Fractie & operator+=(const Fractie & other); 
    Fractie& operator-=(const Fractie& other);
    Fractie& operator*=(const Fractie& other);
    Fractie& operator/=(const Fractie& other);
    Fractie& operator++();    // Preincrementare
    Fractie operator++(int);  // Postincrementare
    Fractie& operator--();    // Predecrementare
    Fractie operator--(int);  // Postdecrementare

    Fractie& operator=(const Fractie& other);    // Operator de atribuire

        // Operator de citire
    friend std::istream& operator>>(std::istream& input, Fractie& fractie);

    // Operator de afisare
    friend std::ostream& operator<<(std::ostream& output, const Fractie& fractie);

};

#endif // FRACTIE_H
