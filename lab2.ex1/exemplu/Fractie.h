#pragma once
#ifndef FRACTIE_H
#define FRACTIE_H

class Fractie {
private:
    int numarator;
    int numitor;

public:
    Fractie();                                 // Constructor implicit
    Fractie(int _numarator);                   // Constructor cu un parametru 
    Fractie(int _numitor, int _numarator);    // Constructor cu doi parametri 
    Fractie(const Fractie& other);            // Constructor de copiere

    Fractie adunare(const Fractie& other) const;    
    Fractie scadere(const Fractie& other) const;    
    Fractie inmultire(const Fractie& other) const;  
    Fractie impartire(const Fractie& other) const;  

    static int cmmdc(int a, int b);           //Metoda statica cmmdc

    void simplifica();                  
    Fractie reciproc() const;
    bool egal(const Fractie& other) const;

    void print() const;      // Metoda pentru afișare
};

#endif // FRACTIE_H

