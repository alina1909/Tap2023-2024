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

Fractie Fractie::reciproc() const {
    Fractie rezultat;
    rezultat.numitor = this->numarator;
    rezultat.numarator = this->numitor;
    return rezultat;
}

void Fractie::simplifica() {
    int c = cmmdc(numarator, numitor);
    numarator /= c;
    numitor /= c;
}

void Fractie::afisare() const {
    std::cout << numarator << "/" << numitor;
}

bool Fractie::egal(const Fractie& other) const {
    return (this->numarator * other.numitor) == (other.numarator * this->numitor);
}

int Fractie::cmmdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


//////////////////////////////////////////////////////////////////////////
// Suprascrierea operatorilor folosind functii membre
Fractie Fractie::operator+(const Fractie& other) const {
    Fractie rezultat;
    rezultat.numitor = this->numitor * other.numitor;
    rezultat.numarator = (this->numarator * other.numitor) + (other.numarator * this->numitor);
    return rezultat;
}

Fractie Fractie::operator-(const Fractie& other) const {
    Fractie rezultat;
    rezultat.numitor = this->numitor * other.numitor;
    rezultat.numarator = (this->numarator * other.numitor) - (other.numarator * this->numitor);
    return rezultat;
}

Fractie Fractie::operator*(const Fractie& other) const {
    Fractie rezultat;
    rezultat.numitor = this->numitor * other.numitor;
    rezultat.numarator = this->numarator * other.numarator;
    return rezultat;
}

Fractie Fractie::operator/(const Fractie& other) const {
    Fractie rezultat;
    rezultat.numitor = this->numitor * other.numarator;
    rezultat.numarator = this->numarator * other.numitor;
    return rezultat;
}

bool Fractie::operator<(const Fractie& other) const {
    return (this->numarator * other.numitor) < (other.numarator * this->numitor);
}

bool Fractie::operator>(const Fractie& other) const {
    return (this->numarator * other.numitor) > (other.numarator * this->numitor);
}

bool Fractie::operator<=(const Fractie& other) const {
    return (this->numarator * other.numitor) <= (other.numarator * this->numitor);
}

bool Fractie::operator>=(const Fractie& other) const {
    return (this->numarator * other.numitor) >= (other.numarator * this->numitor);
}

bool Fractie::operator==(const Fractie& other) const {
    return (this->numarator * other.numitor) == (other.numarator * this->numitor);
}

bool Fractie::operator!=(const Fractie& other) const {
    return (this->numarator * other.numitor) != (other.numarator * this->numitor);
}



//////////////////////////////////////////////
// Suprascrierea operatorilor folosind funcții prietene
/*
Fractie operator+(const Fractie& frac1, const Fractie& frac2) {
    Fractie rezultat;
    rezultat.numitor = frac1.numitor * frac2.numitor;
    rezultat.numarator = (frac1.numarator * frac2.numitor) + (frac2.numarator * frac1.numitor);
    return rezultat;
}

Fractie operator-(const Fractie& frac1, const Fractie& frac2) {
    Fractie rezultat;
    rezultat.numitor = frac1.numitor * frac2.numitor;
    rezultat.numarator = (frac1.numarator * frac2.numitor) - (frac2.numarator * frac1.numitor);
    return rezultat;
}

Fractie operator*(const Fractie& frac1, const Fractie& frac2) {
    Fractie rezultat;
    rezultat.numitor = frac1.numitor * frac2.numitor;
    rezultat.numarator = frac1.numarator * frac2.numarator;
    return rezultat;
}

Fractie operator/(const Fractie& frac1, const Fractie& frac2) {
    Fractie rezultat;
    rezultat.numitor = frac1.numitor * frac2.numarator;
    rezultat.numarator = frac1.numarator * frac2.numitor;
    return rezultat;
}

bool operator<(const Fractie& frac1, const Fractie& frac2) {
    return (frac1.numarator * frac2.numitor) < (frac2.numarator * frac1.numitor);
}

bool operator>(const Fractie& frac1, const Fractie& frac2) {
    return (frac1.numarator * frac2.numitor) > (frac2.numarator * frac1.numitor);
}

bool operator<=(const Fractie& frac1, const Fractie& frac2) {
    return (frac1.numarator * frac2.numitor) <= (frac2.numarator * frac1.numitor);
}

bool operator>=(const Fractie& frac1, const Fractie& frac2) {
    return (frac1.numarator * frac2.numitor) >= (frac2.numarator * frac1.numitor);
}

bool operator==(const Fractie& frac1, const Fractie& frac2) {
    return (frac1.numarator * frac2.numitor) == (frac2.numarator * frac1.numitor);
}

bool operator!=(const Fractie& frac1, const Fractie& frac2) {
    return (frac1.numarator * frac2.numitor) != (frac2.numarator * frac1.numitor);
}
*/



// Suprascrierea operatorilor +=,-=,*=,/=,++,--, folosind functii membre
Fractie& Fractie::operator+=(const Fractie& other) {
    this->numarator = (this->numarator * other.numitor) + (other.numarator * this->numitor);
    this->numitor *= other.numitor;
    return *this;
}

Fractie& Fractie::operator-=(const Fractie& other) {
    this->numarator = (this->numarator * other.numitor) - (other.numarator * this->numitor);
    this->numitor *= other.numitor;
    return *this;
}

Fractie& Fractie::operator*=(const Fractie& other) {
    this->numarator *= other.numarator;
    this->numitor *= other.numitor;
    return *this;
}

Fractie& Fractie::operator/=(const Fractie& other) {
    this->numarator *= other.numitor;
    this->numitor *= other.numarator;
    return *this;
}

Fractie& Fractie::operator++() {  // Preincrementare
    this->numarator += this->numitor;
    return *this;
}

Fractie Fractie::operator++(int) {   // Postincrementare
    Fractie temp(*this);
    this->numarator += this->numitor;
    return temp;
}

Fractie& Fractie::operator--() {    // Predecrementare
    this->numarator -= this->numitor;
    return *this;
}

Fractie Fractie::operator--(int) {   // Postdecrementare
    Fractie temp(*this);
    this->numarator -= this->numitor;
    return temp;
}

Fractie& Fractie::operator=(const Fractie& other) {
    if (this != &other) { 
        numarator = other.numarator;
        numitor = other.numitor;
    }
    return *this;
}


// Suprascrierea operatorilor de citire si afisare folosind functii prietene
std::istream& operator>>(std::istream& input, Fractie& fractie) {
    std::cout << "Introduceti numaratorul: ";
    input >> fractie.numarator;

    std::cout << "Introduceti numitorul: ";
    input >> fractie.numitor;

    return input;
}

std::ostream& operator<<(std::ostream& output, const Fractie& fractie) {
    output << fractie.numarator << "/" << fractie.numitor;
    return output;
}



int main() {
    Fractie fractie1(1, 3);
    Fractie fractie2(2, 6);

    std::cout << "Fractie 1: ";
    fractie1.afisare();
    std::cout << std::endl;

    std::cout << "Fractie 2: ";
    fractie2.afisare();
    std::cout << std::endl;

    // Adunare
    Fractie suma = fractie1 + fractie2;
    std::cout << "Suma: ";
    suma.afisare();
    std::cout << std::endl;

    // Scadere
    Fractie diferenta = fractie1 - fractie2;
    std::cout << "Diferenta: ";
    diferenta.afisare();
    std::cout << std::endl;

    // Inmultire
    Fractie produs = fractie1 * fractie2;
    std::cout << "Produsul: ";
    produs.afisare();
    std::cout << std::endl;

    // Impartire
    Fractie impartire = fractie1 / fractie2;
    std::cout << "Impartirea: ";
    impartire.afisare();
    std::cout << std::endl;

    // Comparare
    if (fractie1 < fractie2) {
        std::cout << "Fractia 1 este mai mica decat Fractia 2." << std::endl;
    }
    else if (fractie1 > fractie2) {
        std::cout << "Fractia 1 este mai mare decat Fractia 2." << std::endl;
    }
    else {
        std::cout << "Fractiile sunt egale." << std::endl;
    }



    // Adunare
    fractie1 += fractie2;
    
    // Scadere
    fractie1 -= fractie2;
    
    // Inmultire
    fractie1 *= fractie2;
  
    // Impartire
    fractie1 /= fractie2;

    // Preincrementare
    ++fractie1;

    // Postincrementare
    Fractie fractie3 = fractie1++;

    // Predecrementare
    --fractie1;

    // Postdecrementare
    Fractie fractie4 = fractie1--;



    // Operator de atribuire
    fractie1 = fractie2;
    

    Fractie fractie;
    std::cin >> fractie; // Citire
    std::cout << "Fractia introdusa este: " << fractie << std::endl; // Afișare

    return 0;
}
