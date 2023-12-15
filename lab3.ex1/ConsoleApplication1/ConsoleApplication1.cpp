#include "dreapta.h"
#include "punct.h"
#include <cmath>
#include <vector>
#include <iostream>


Dreapta::Dreapta(float panta, float ordonata) : m(panta), n(ordonata) {}


Dreapta::Dreapta(const Dreapta& other) : m(other.m), n(other.n) {}


Dreapta::~Dreapta() {}

float Dreapta::calculeazaValoareaY(float x) const {
    return m * x + n;
}

void Dreapta::afisareD() const {
    std::cout << "y = " << m << "x + " << n << "\n";
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////

// Inițializare proprietate statică de tip Dreapta
Dreapta Punct::dreapta(1, 0);  

int Punct::numarPuncteSemiplanPozitiv = 0;
int Punct::numarPuncteSemiplanNegativ = 0;
int Punct::numarPunctePeDreapta = 0;


Punct::Punct(float abs, float ord) : x(abs), y(ord) {
    float rezultat = Punct::dreapta.calculeazaValoareaY(x);
    if (rezultat == y) {
        numarPunctePeDreapta++;
    }
    else if (rezultat - y > 0) {
        numarPuncteSemiplanPozitiv++;
    }
    else {
        numarPuncteSemiplanNegativ++;
    }
}


Punct::Punct(const Punct& other) : x(other.x), y(other.y) {}


Punct::~Punct() {
    float rezultat = Punct::dreapta.calculeazaValoareaY(x);
    if (rezultat == y) {
        numarPunctePeDreapta--;
    }
    else if (rezultat - y > 0) {
        numarPuncteSemiplanPozitiv--;
    }
    else {
        numarPuncteSemiplanNegativ--;
    }
}


float distanta(const Punct& p1, const Punct& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}


/*
Punct Punct::CentruGreutate(const std::vector<Punct>& puncte) {
    float sumaX = 0;
    float sumaY = 0;

    for (const auto& p : puncte) {
        sumaX += p.x;
        sumaY += p.y;
    }

    if (!puncte.empty()) {
        float mediaX = sumaX / puncte.size();
        float mediaY = sumaY / puncte.size();
        return Punct(mediaX, mediaY);
    }
    else {
        // În cazul în care vectorul de puncte este gol, returnăm un punct cu coordonatele (0, 0).
        return Punct();
    }
}
*/

////////////////////////////////////////////////////////////////////////////

int main()
{
    Dreapta dreapta1;
    dreapta1.afisareD();

    Dreapta dreapta2(2, 3);
    dreapta2.afisareD();

    Dreapta dreaptaCopy(dreapta2);
    dreaptaCopy.afisareD();

  
    ///////////////////////////////////////////////////////////////////////////
    int n;
    std::cout << "Introduceti numarul de puncte (n): ";
    std::cin >> n;

    std::vector<Punct> puncte;

    for (int i = 0; i < n; ++i) {
        float x, y;
        std::cout << "Introduceti coordonatele pentru punctul " << i + 1 << " (x y): ";
        std::cin >> x >> y;
        puncte.emplace_back(x, y);
    }


    if (n >= 2) {
        float d = distanta(puncte[0], puncte[n - 1]);
        std::cout << "Distanța între primul și ultimul punct: " << d << "\n";
    }
    else {
        std::cout << "Nu sunt suficiente puncte pentru a calcula distanta.\n";
    }


    
    return 0;
}

