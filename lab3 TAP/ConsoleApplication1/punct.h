#pragma once
#ifndef PUNCT_H
#define PUNCT_H
#include "dreapta.h"

class Punct {
private:
    float x;  // Abscisa
    float y;  // Ordonata
    static Dreapta dreapta;  // Proprietate statică de tip Dreapta

    // Variabile statice pentru a contoriza punctele
    static int numarPuncteSemiplanPozitiv;
    static int numarPuncteSemiplanNegativ;
    static int numarPunctePeDreapta;

public:
    // Constructor cu doi parametri și valori implicite
    Punct(float abs = 0, float ord = 0);

    // Constructor de copiere
    Punct(const Punct& other);

    // Destructor
    ~Punct();

    // Funcție prietenă pentru calculul distanței între două puncte
    friend float distanta(const Punct& p1, const Punct& p2);

    // Metoda pentru a calcula centrul de greutate al tuturor punctelor
    static Punct CentruGreutate(const std::vector<Punct>& puncte);
};

#endif // PUNCT_H

