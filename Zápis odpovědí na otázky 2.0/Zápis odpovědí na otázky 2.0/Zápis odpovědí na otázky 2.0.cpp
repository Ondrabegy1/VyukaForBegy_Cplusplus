#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Otazka {
    string otazka;
    string a;
    string b;
    string c;
    string d;
    char spravnaOdpoved;
};

int main()
{
	ifstream soubor("Otazky.txt");
	vector<Otazka> otazky;
	string radek;

    while (getline(soubor, radek)) {
		Otazka otazka;
		otazka.otazka = radek.substr(0, radek.find(';'));
		radek.erase(0, radek.find(';') + 1);
		otazka.a = radek.substr(0, radek.find(';'));
		radek.erase(0, radek.find(';') + 1);
		otazka.b = radek.substr(0, radek.find(';'));
		radek.erase(0, radek.find(';') + 1);
		otazka.c = radek.substr(0, radek.find(';'));
		radek.erase(0, radek.find(';') + 1);
		otazka.d = radek.substr(0, radek.find(';'));
		radek.erase(0, radek.find(';') + 1);
		otazka.spravnaOdpoved = radek[0];
		otazky.push_back(otazka);
	}

	soubor.close();

	int pocetBodu = 0;
	for (int i = 0; i < otazky.size(); i++) {
		cout << otazky[i].otazka << endl;
		cout << "A) " << otazky[i].a << endl;
		cout << "B) " << otazky[i].b << endl;
		cout << "C) " << otazky[i].c << endl;
		cout << "D) " << otazky[i].d << endl;
		cout << endl;
		cout << "Zadej odpoved: ";

		char odpoved;
		cin >> odpoved;

		if (odpoved == otazky[i].spravnaOdpoved) {
			pocetBodu++;
			cout << "Spravne!" << endl;
		}

		else {
			cout << "Spatne!" << endl;
		}

		cout << endl;
	}

	cout << "Pocet bodu: " << pocetBodu << endl;

	return 0;
}
