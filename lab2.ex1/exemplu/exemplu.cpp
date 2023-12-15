//lab2


#include "Fractie.h"
#include <iostream>

Fractie::Fractie() : numarator(0), numitor(1) {}

Fractie::Fractie(int _numarator) : numarator(_numarator), numitor(1) {}

Fractie::Fractie(int _numitor, int _numarator) : numitor(_numitor), numarator(_numarator) {}

Fractie::Fractie(const Fractie& other) : numarator(other.numarator), numitor(other.numitor) {}

Fractie Fractie::adunare(const Fractie& other) const {
    Fractie rezultat;
    rezultat.numitor = this->numitor * other.numitor;
    rezultat.numarator = (this->numarator * other.numitor) + (other.numarator * this->numitor);
    return rezultat;
}

Fractie Fractie::scadere(const Fractie& other) const {
    Fractie rezultat;
    rezultat.numitor = this->numitor * other.numitor;
    rezultat.numarator = (this->numarator * other.numitor) - (other.numarator * this->numitor);
    return rezultat;
}

Fractie Fractie::inmultire(const Fractie& other) const {
    Fractie rezultat;
    rezultat.numitor = this->numitor * other.numitor;
    rezultat.numarator = this->numarator * other.numarator;
    return rezultat;
}

Fractie Fractie::impartire(const Fractie& other) const {
    Fractie rezultat;
    rezultat.numitor = this->numitor * other.numarator;
    rezultat.numarator = this->numarator * other.numitor;
    return rezultat;
}

int Fractie::cmmdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fractie::simplifica() {
    int c = cmmdc(numarator, numitor);
    numarator /= c;
    numitor /= c;
}

Fractie Fractie::reciproc() const {
    Fractie rezultat;
    rezultat.numitor = this->numarator;
    rezultat.numarator = this->numitor;
    return rezultat;
}

bool Fractie::egal(const Fractie& other) const {
    return (this->numarator * other.numitor) == (other.numarator * this->numitor);
}

void Fractie::print() const {
    std::cout << numarator << "/" << numitor;
}


int main() {
    Fractie fractie1;               // Inițializare cu 0/1
    Fractie fractie2(2, 3);        
    Fractie fractie3(1, 2);         
    Fractie fractie4(8, 12);
    Fractie fractie5(5);

    // Adunare + afișare
    Fractie rezultatAdunare = fractie2.adunare(fractie3);
    std::cout << "Adunare: ";
    rezultatAdunare.print();
    std::cout << std::endl;

    // Scădere + afișare
    Fractie rezultatScadere = fractie2.scadere(fractie3);
    std::cout << "Scadere: ";
    rezultatScadere.print();
    std::cout << std::endl;

    // Înmulțire + afișare 
    Fractie rezultatInmultire = fractie2.inmultire(fractie3);
    std::cout << "Inmultire: ";
    rezultatInmultire.print();
    std::cout << std::endl;

    // Împărțire + afișare 
    Fractie rezultatImpartire = fractie2.impartire(fractie3);
    std::cout << "Impartire: ";
    rezultatImpartire.print();
    std::cout << std::endl;

    //constructor copiere
    Fractie copie = fractie3;
    std::cout << "copie fractie 3:";
    copie.print();
    std::cout << std::endl;

    //Metoda cmmdc
    int a = 24;
    int b = 36;
    int rezultatCMMDC = Fractie::cmmdc(a, b);
    std::cout << "CMMDC(" << a << ", " << b << ") = " << rezultatCMMDC << std::endl;

    //Metoda simplifica
    fractie4.simplifica();
    std::cout << "Fractie simplificata: ";
    fractie4.print();
    std::cout << std::endl;

    //Metoda reciproc
    Fractie reciproca = fractie5.reciproc();
    std::cout << "Reciprocul fractiei: ";
    reciproca.print();
    std::cout << std::endl;

    //Metoda egal
    if (fractie2.egal(fractie3)) {
        std::cout << "Cele doua fractii sunt egale." << std::endl;
    }
    else {
        std::cout << "Cele doua fractii nu sunt egale." << std::endl;
    }
    return 0;
}
