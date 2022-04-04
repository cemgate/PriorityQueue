#include "msg.h"
#include<fstream>

void Msg::divideMsg()
{
	letter = msg.size();
	if (letter != 0)
	{
		cout << "Podaj na ile pakietow podzielic wiadomosc:";
		cin >> n;
		auto plik = new ofstream[n];
		pierwszeW = letter % n;
		liczbaznakow = (letter - pierwszeW) / n;
		ostatnieW = n - pierwszeW;
		for (int i = 0; i < pierwszeW; i++)
		{

			size_t length = msg.copy(buffor, liczbaznakow + 1, 0);
			buffor[length] = '\0';
			sprintf_s(buffor1, "W%d.txt", i + 1);
			plik[i].open(buffor1);
			plik[i] << buffor;
			plik[i].close();

			msg.erase(0, liczbaznakow + 1);
		}

		for (int i = n - ostatnieW; i < n; i++)
		{

			size_t length = msg.copy(buffor, liczbaznakow, 0);
			buffor[length] = '\0';
			sprintf_s(buffor1, "W%d.txt", i + 1);
			plik[i].open(buffor1);
			plik[i] << buffor;
			plik[i].close();
			msg.erase(0, liczbaznakow);
		}
		delete[] plik;
	}
	else
	{
		cout << "Brak pliku do podzielenia" << endl;
	}
}

void Msg::getMsg()
{
	cout << "Wpisz wiadomosc do wyslania:";
	cin.ignore();
	getline(cin, msg);
}
