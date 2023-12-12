#pragma once
#ifndef FRACTIE_H
#define FRACTIE_H

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

    static int cmmdc(int a, int b);           //Metoda statica cmmdc
    void simplifica();                  
    Fractie reciproc() const;
    bool egal(const Fractie& other) const;

    void print() const;      // Metoda pentru afișare
};

#endif // FRACTIE_H

