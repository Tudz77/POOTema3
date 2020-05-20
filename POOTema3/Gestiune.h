#pragma once

#include "PlataCec.h"
#include "PlataNumerar.h"
#include "PlataCard.h"

template<class T>
class Gestiune
{
	static int nrPlati;
	std::unordered_map<int, T> plati;
public:
	Gestiune();
	Gestiune<T>& operator=(const Gestiune<T>& other);
	~Gestiune();
	Gestiune<T>& operator+=(T plata);
	void afisare();
};

