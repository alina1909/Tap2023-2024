#include "dreapta.h"
#include "punct.h"
#include <cmath>
#include <vector>
#include <iostream>

// Implementarea constructorului cu doi parametri și valori implicite
Dreapta::Dreapta(float panta, float ordonata) : m(panta), n(ordonata) {}

// Implementarea constructorului de copiere
Dreapta::Dreapta(const Dreapta& other) : m(other.m), n(other.n) {
    std::cout << "Apel constructor de copiere\n";
}

// Implementarea destructorului
Dreapta::~Dreapta() {
    std::cout << "Apel destructor\n";
}

// Implementarea funcției pentru a calcula valoarea y pentru o anumită valoare x
float Dreapta::calculeazaValoareaY(float x) const {
    return m * x + n;
}

// Implementarea metodei pentru a afișa ecuația dreptei
void Dreapta::afisareD() const {
    std::cout << "y = " << m << "x + " << n << "\n";
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////

// Inițializare proprietate statică de tip Dreapta
Dreapta Punct::dreapta(1, 0);  // exemplu: y = x

// Inițializare variabile statice pentru contorizare
int Punct::numarPuncteSemiplanPozitiv = 0;
int Punct::numarPuncteSemiplanNegativ = 0;
int Punct::numarPunctePeDreapta = 0;

// Implementarea constructorului cu doi parametri și valori implicite
Punct::Punct(float abs, float ord) : x(abs), y(ord) {
    // Verifică în care semiplan se află punctul și actualizează variabilele statice
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

// Implementarea constructorului de copiere
Punct::Punct(const Punct& other) : x(other.x), y(other.y) {
    // Daca e nevoie, implementeaza cod suplimentar pentru constructorul de copiere
}

// Implementarea destructorului
Punct::~Punct() {
    // Verifică în care semiplan se află punctul și actualizează variabilele statice
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

// Funcție prietenă pentru calculul distanței între două puncte
float distanta(const Punct& p1, const Punct& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}


// Implementarea metodei pentru a calcula centrul de greutate al tuturor punctelor
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


////////////////////////////////////////////////////////////////////////////

int main()
{
    // Creare obiect de tip Dreapta folosind constructorul cu valori implicite
    Dreapta dreaptaImplicita;

    // Afisare ecuatia dreptei
    dreaptaImplicita.afisareD();

    // Creare obiect de tip Dreapta folosind constructorul cu valori specifice
    Dreapta dreaptaPersonalizata(2, 3);

    // Afisare ecuatia dreptei
    dreaptaPersonalizata.afisareD();

    // Creare obiect de tip Dreapta folosind constructorul de copiere
    Dreapta dreaptaCopiata(dreaptaPersonalizata);

    // Afisare ecuatia dreptei copiate
    dreaptaCopiata.afisareD();

    // Destructorul este apelat automat la sfârșitul programului sau atunci când obiectele își ies din domeniul de valabilitate


  
    ///////////////////////////////////////////////////////////////////////////
    int n;
    std::cout << "Introduceti numarul de puncte (n): ";
    std::cin >> n;

    // Creare vector de obiecte Punct
    std::vector<Punct> puncte;

    // Citire coordonate pentru fiecare punct și adăugare în vector
    for (int i = 0; i < n; ++i) {
        float x, y;
        std::cout << "Introduceti coordonatele pentru punctul " << i + 1 << " (x y): ";
        std::cin >> x >> y;
        puncte.emplace_back(x, y);
    }

    // Calculul distantei intre primul si ultimul punct din vector
    if (n >= 2) {
        float d = distanta(puncte[0], puncte[n - 1]);
        std::cout << "Distanța între primul și ultimul punct: " << d << "\n";
    }
    else {
        std::cout << "Nu sunt suficiente puncte pentru a calcula distanta.\n";
    }

    // Apelarea metodei CentruGreutate și afișarea rezultatului
    Punct centruGreutate = Punct::CentruGreutate(puncte);
    std::cout << "Centrul de greutate al punctelor este: (" << centruGreutate.getX() << ", " << centruGreutate.getY() << ")\n";


    
    return 0;
}

