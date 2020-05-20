#include "Plata.h"
#include "exceptions.h"
#include "PlataNumerar.h"
#include "PlataCard.h"
#include "PlataCEC.h"

Plata::Plata()
	: data_zi(0), data_luna(0), data_an(0), suma(0)
{}

Plata::Plata(int zi, int luna, int an, float suma)
	: data_zi(zi), data_luna(luna), data_an(an), suma(suma)
{}

Plata::Plata(const Plata& other)
{
	data_zi = other.data_zi;
	data_luna = other.data_luna;
	data_an = other.data_an;
	suma = other.suma;
}

Plata& Plata::operator=(const Plata& other)
{
	if (this != &other)
	{
		data_zi = other.data_zi;
		data_luna = other.data_luna;
		data_an = other.data_an;
		suma = other.suma;
	}
	return *this;
}

Plata::~Plata()
{
	data_an = 0;
	data_luna = 0;
	data_zi = 0;
	suma = 0;
}


std::istream& operator>>(std::istream& in, Plata& plata)
{
	if (dynamic_cast<PlataNumerar*>(&plata))
	{
		std::cout << std::endl << "Se efectueaza plata numerar"; 
		std::cout << std::endl << "Introduceti pe rand:\ndata, ziua, anul, suma" << std::endl;

	}
	else if (dynamic_cast<PlataCard*>(&plata))
	{
		std::cout << std::endl << "Se efectueaza plata cu cardul";
		std::cout << std::endl << "Introduceti pe rand:\ndata, ziua, anul, suma, nume client, numar card" << std::endl;
	}
	else if (dynamic_cast<PlataCec*>(&plata))
	{
		std::cout << std::endl << "Se efectueaza plata prin CEC";
		std::cout << std::endl << "Introduceti pe rand:\ndata, ziua, anul, suma, nume client, iban" << std::endl;

	}
citire_zi:
	try
	{
		in >> plata.data_zi;
		if (plata.data_zi < 1 || plata.data_zi >31) throw wrongDate();
	}
	catch (wrongDate)
	{
		std::cout << "Data nu este corecta. Reintroduceti\n";
		goto citire_zi;
	}
	catch (...)
	{
		std::cout << "Eroare. Reintroduceti\n";
		goto citire_zi;
	}
citire_luna:
	try
	{ 
		in >> plata.data_luna;
		if (plata.data_luna < 1 || plata.data_luna > 12) throw wrongDate();
	}
	catch (wrongDate)
	{
		std::cout << "Luna nu este corecta. Reintroduceti\n";
		goto citire_luna;
	}
	catch (...)
	{
		std::cout << "Eroare. Reintroduceti\n";
		goto citire_luna;
	}
citire_an:
	try
	{
		in >> plata.data_an;
		if (plata.data_an < 1970 || plata.data_an > 2020) throw wrongDate();
	}
	catch (wrongDate)
	{
		std::cout << "Anul nu este corect. Reintroduceti\n";
		goto citire_an;
	}
	catch (...)
	{
		std::cout << "Eroare. Reintroduceti\n";
		goto citire_an;
	}
citire_suma:
	try
	{
		in >> plata.suma;
		if (plata.suma < 0) throw negative();
	}
	catch (negative)
	{
		std::cout << "Valoarea nu poate fi negativa.Reintroduceti\n";
		goto citire_suma;
	}
	catch (...)
	{
		std::cout << "Eroare. Reintroduceti\n";
		goto citire_suma;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Plata& plata)
{
	plata.afisare();
	return out;
}

