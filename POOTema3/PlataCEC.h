#pragma once

#include "Plata.h"

class PlataCec : public Plata
{
	std::string IBAN;
	std::string numeClient;
public:
	PlataCec();

	PlataCec(int zi, int luna, int an, float suma, std::string IBAN, std::string numeClient);

	PlataCec& operator=(const PlataCec& other);

	~PlataCec();

	void afisare() const;

	friend std::istream& operator>>(std::istream& in, PlataCec& platacec);
};
