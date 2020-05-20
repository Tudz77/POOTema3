#include "GestiunePlataCard.h"
#include "Gestiune.cpp"

int Gestiune<PlataNumerar>::nrPlati= 0;
int Gestiune<PlataCard>::nrPlati = 0;
int Gestiune<PlataCec>::nrPlati = 0;
int Gestiune<PlataCard>::nrClienti = 0;


int main()
{
	//std::unordered_map<int, Plata*> plati;

	Gestiune<PlataNumerar> g_PlataNumerar;
	Gestiune<PlataCard> g_PlataCard;
	Gestiune<PlataCec> g_PlataCec;
	
	int optiune;
	do
	{
		std::cout << "==============================\n"
			<< "1. Adauga plata numerar\n"
			<< "2. Adauga plata cu cardul\n"
			<< "3. Adauga plata prin CEC\n"
			<< "4. Vezi platile numerar\n"
			<< "5. Vezi platile cu cardul\n"
			<< "6. Vezi platile prin CEC\n"
			<< "7. Afisare platitori cu cardul\n"
			<< "8. Iesire"
			<< "\n==============================\n";
		std::cin >> optiune;
		if (optiune == 1)
		{
			PlataNumerar temp;
			std::cin >> temp;
			g_PlataNumerar += temp;
			std::cout << std::endl << std::endl;
		}
		else if (optiune == 2)
		{
			PlataCard temp;
			std::cin >> temp;
			g_PlataCard += temp;
			std::cout << std::endl << std::endl;
		}
		else if (optiune == 3)
		{
			PlataCec temp;
			std::cin >> temp;
			g_PlataCec += temp;
			std::cout << std::endl << std::endl;
		}
		else if (optiune == 4)
		{
			std::cout << std::endl << "------------------------\nLista de plati numerar:\n";
			g_PlataNumerar.afisare();
			std::cout << "------------------------" << std::endl << std::endl;
		}
		else if (optiune == 5)
		{
			std::cout << std::endl << "------------------------\nLista de plati cu cardul:\n";
			g_PlataCard.afisare();
			std::cout << "------------------------" << std::endl << std::endl;
		}
		else if (optiune == 6)
		{
			std::cout << std::endl << "------------------------\nLista de plati prin Cec:\n";
			g_PlataCec.afisare();
			std::cout << "------------------------" << std::endl << std::endl;
		}
		else if (optiune == 7)
		{
			std::cout << std::endl << "------------------------\nLista de platitori cu cardul:\n";
			g_PlataCard.afisareClienti();
			std::cout << "------------------------" << std::endl << std::endl;
		}
		else if (optiune == 8)
		{
			break;
		}
		else
		{
			std::cout << "\nAlegeti o optiune valida!\n\n";
		}

	} while (true);
	

	//Gestiune<PlataCard> gestiune_card;
	//Gestiune<PlataCec> gestiune_cec;
	//Gestiune<PlataNumerar> gestiune_numerar;
	return 0;
}