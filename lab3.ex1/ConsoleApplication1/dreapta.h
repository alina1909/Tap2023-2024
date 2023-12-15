#pragma once
#ifndef DREAPTA_H
#define DREAPTA_H

class Dreapta {
private:
	float m;   //panta dreptei
	float n;   //ordonata la origine

public:
	Dreapta(float panta = 1, float ordonata = 0);
	Dreapta(const Dreapta& other);
	~Dreapta();

	float calculeazaValoareaY(float x) const;
	void afisareD() const;

};


#endif
