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

    Punct(float abs = 0, float ord = 0);
    Punct(const Punct& other);
    ~Punct();

    friend float distanta(const Punct& p1, const Punct& p2);
    static Punct CentruGreutate(const std::vector<Punct>& puncte);
};

#endif 

