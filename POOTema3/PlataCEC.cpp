#include "PlataCEC.h"

PlataCec::PlataCec()
	: Plata()
{}
PlataCec::PlataCec(int zi, int luna, int an, float suma, std::string IBAN, std::string numeClient)
	: Plata(zi, luna, an, suma), IBAN(IBAN), numeClient(numeClient)
{}
PlataCec& PlataCec::operator=(const PlataCec& other)
{
	if (this != &other)
	{
		data_zi = other.data_zi;
		data_luna = other.data_luna;
		data_an = other.data_an;
		suma = other.suma;
		numeClient = other.numeClient;
		IBAN = other.IBAN;
	}
	return *this;
}
PlataCec::~PlataCec()
{
	IBAN = "";
	numeClient = "";
}
void PlataCec::afisare() const
{
	std::cout << data_zi << "." << data_luna << "." << data_an << std::endl;
	std::cout << "Plata prin CEC" << std::endl;
	std::cout << "Client: " << numeClient << std::endl;
	std::cout << "IBAN: " << IBAN << std::endl;
	std::cout << "Suma: " << suma;
}

std::istream& operator>>(std::istream& in, PlataCec& platacec)
{
	in >> *reinterpret_cast<Plata*>(&platacec) >> platacec.numeClient >> platacec.IBAN;
	return in;
}


std::ostream& operator<<(std::ostream& out, const PlataCec& platacec)
{
	platacec.afisare();
	return out;
}