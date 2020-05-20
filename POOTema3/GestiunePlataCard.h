#pragma once

#include "Gestiune.h"

template<>
class Gestiune<PlataCard>
{
	static int nrPlati;
	std::unordered_map<int, PlataCard> plati;
	static int nrClienti;
	std::vector<std::string> numeClienti;
public:
	Gestiune()
	{
		nrPlati = 0;
		nrClienti = 0;
	}
	Gestiune<PlataCard>& operator=(const Gestiune<PlataCard>& other)
	{
		this->plati = other.plati;
		return *this;
	}
	~Gestiune()
	{
		plati.clear();
		nrPlati = 0;
		nrClienti = 0;
	}
	Gestiune<PlataCard>& operator+=(PlataCard plata)
	{
		nrPlati++;
		int esteClient = 0;
		for (std::string nume : numeClienti)
		{
			if (nume == plata.returnNumeClient())
			{
				esteClient = 1;
			}
		}
		if (!esteClient)
		{
			numeClienti.push_back(plata.returnNumeClient());
			nrClienti++;
		}

		plati.insert({ nrPlati, plata });
		return *this;
	}
	void afisare()
	{
		for (auto it : plati)
		{
			std::cout << it.first << ") " << it.second << std::endl << std::endl;
		}
	}
	void afisareClienti() const
	{
		for (auto client : numeClienti)
		{
			std::cout << client << std::endl;
		}
	}
};