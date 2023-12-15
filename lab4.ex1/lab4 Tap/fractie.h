#pragma once
#ifndef FRACTIE_H
#define FRACTIE_H
#include <iostream>

class Fractie {
private:
    int numarator;
    int numitor;

public:
    Fractie();                                 
    Fractie(int _numarator);                   
    Fractie(int _numitor, int _numarator);    
    Fractie(const Fractie& other);            

    Fractie adunare(const Fractie& other) const;    
    Fractie scadere(const Fractie& other) const;    
    Fractie inmultire(const Fractie& other) const; 
    Fractie impartire(const Fractie& other) const;  
    Fractie reciproc() const;                       
    void simplifica();                             
    void afisare() const;                           
    bool egal(const Fractie& other) const;         

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

    static int cmmdc(int a, int b); // Metoda statică CMMDC

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

#endif 
