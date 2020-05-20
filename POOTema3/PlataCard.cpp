#include "PlataCard.h"
#include "exceptions.h"

PlataCard::PlataCard()
	: Plata(), nrCard(""), numeClient("")
{}

PlataCard::PlataCard(int zi, int luna, int an, float suma, std::string numeClient, std::string nrCard)
	: Plata(zi, luna, an, suma), numeClient(numeClient), nrCard(nrCard)
{}

PlataCard& PlataCard::operator=(const PlataCard& other)
{
	if (this != &other)
	{
		data_zi = other.data_zi;
		data_luna = other.data_luna;
		data_an = other.data_an;
		suma = other.suma;
		numeClient = other.numeClient;
		nrCard = other.nrCard;
	}
	return *this;
}

PlataCard::~PlataCard()
{
	numeClient = "";
	nrCard = "";
}

void PlataCard::afisare() const
{
	std::cout << data_zi << "." << data_luna << "." << data_an << std::endl;
	std::cout << "Plata cu cardul" << std::endl;
	std::cout << "Client: " << numeClient << std::endl;
	std::cout << "Numar card: " << nrCard << std::endl;
	std::cout << "Suma: " << suma;
}

std::istream& operator>>(std::istream& in, PlataCard& platacard)
{
	in >> *reinterpret_cast<Plata*>(&platacard);
citire_client:
	try 
	{
		in >> platacard.numeClient;
	}
	catch (...)
	{
		std::cout << "Eroare. Reintroduceti";
		goto citire_client;
	}
citire_card:
	try
	{
		in >> platacard.nrCard;
		if (platacard.nrCard.size() != 16) throw cardNumber();
	}
	catch (cardNumber)
	{
		std::cout << "Numarul cardului are lungime incorecta. Reintroduceti";
		goto citire_card;
	}
	catch (...)
	{
		std::cout << "Eroare. Reintroduceti";
		goto citire_card;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const PlataCard& platacard)
{
	platacard.afisare();
	return out;
}

std::string PlataCard::returnNumeClient() const
{
	return numeClient;
}