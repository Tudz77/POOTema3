#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class Plata
{
protected:
	int data_zi, data_luna, data_an;
	float suma;
public:
	Plata();
	Plata(int zi, int luna, int an, float suma);
	Plata(const Plata& other);
	Plata& operator=(const Plata& other);
	virtual ~Plata();
	virtual void afisare() const = 0;
	friend std::istream& operator>>(std::istream& in, Plata& plata);
	friend std::ostream& operator<<(std::ostream& out, const Plata& plata);
};
