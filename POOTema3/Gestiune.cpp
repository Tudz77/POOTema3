#include "Gestiune.h"

template<class T>
Gestiune<T>::Gestiune()
{
	nrPlati = 0;
}

template<class T>
Gestiune<T>& Gestiune<T>::operator=(const Gestiune& other)
{
	this->plati = other.plati;
	return *this;
}

template<class T>
Gestiune<T>::~Gestiune()
{
	plati.clear();
	nrPlati = 0;
}

template<class T>
Gestiune<T>& Gestiune<T>::operator+=(T plata)
{
	Gestiune<T>::nrPlati++;
	plati.insert({ nrPlati, plata });
	return *this;
}

template<class T>
void Gestiune<T>::afisare()
{
	for (auto it : plati)
	{
		std::cout << it.first << ") " << it.second << std::endl << std::endl;
	}
}
