#include "PlataNumerar.h"

PlataNumerar::PlataNumerar ()
	: Plata()
{}
PlataNumerar::PlataNumerar(int zi, int luna, int an, float suma)
	: Plata(zi, luna, an, suma)
{}
PlataNumerar& PlataNumerar::operator=(const PlataNumerar& other)
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
PlataNumerar::~PlataNumerar()
{
}
void PlataNumerar::afisare() const
{
	std::cout << data_zi << "." << data_luna << "." << data_an << std::endl;
	std::cout << "Plata numerar" << std::endl;
	std::cout << "Suma: " << suma;
}

std::istream& operator>>(std::istream& in, PlataNumerar& platanumerar)
{
	in >> *reinterpret_cast<Plata*>(&platanumerar);
	return in;
}

std::ostream& operator<<(std::ostream& out, const PlataNumerar& platanumerar)
{
	platanumerar.afisare();
	return out;
}