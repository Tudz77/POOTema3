#pragma once

#include "Plata.h"

class PlataCard : public Plata
{
	std::string numeClient;
	std::string nrCard;
public:
	PlataCard();
	PlataCard(int zi, int luna, int an, float suma, std::string numeClient, std::string nrCard);
	PlataCard& operator=(const PlataCard& other);
	~PlataCard();

	void afisare() const;

	friend std::istream& operator>>(std::istream& in, PlataCard& platacard);
	friend std::ostream& operator<<(std::ostream& out, const PlataCard& platacard);

	std::string returnNumeClient() const;
};
