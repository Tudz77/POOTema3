#pragma once

#include "Plata.h"

class PlataNumerar : public Plata
{
public:
	PlataNumerar();

	PlataNumerar(int zi, int luna, int an, float suma);

	PlataNumerar& operator=(const PlataNumerar& other);
	
	~PlataNumerar();

	void afisare() const;

	friend std::istream& operator>>(std::istream& in, PlataNumerar& plata);
	friend std::ostream& operator<<(std::ostream& out, const PlataNumerar& plata);
};
