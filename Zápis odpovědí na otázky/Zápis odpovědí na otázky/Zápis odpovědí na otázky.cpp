
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

//Struktura pro otázku.
struct Otazka {
	string otazka;
	string a;
	string b;
	string c;
	string d;
	char spravnaOdpoved;
};

//Struktura pro dotazník.
struct Dotaznik {
	Otazka* otazky;
	int delka;
};

Dotaznik* buildDotaznik(string path);
int runDotaznik(Dotaznik * kviz);										//Funkce pro spuštění kvízu.
void reallocate(Otazka** old_arr, int old_size, int new_size);			//Funkce pro zvětšení pole o jednu otázku.
void vymazOtazky(Dotaznik* kviz);										//Funkce pro vymazání otázky.

int main()
{
	string path;
	cout << "Zadejte cestu k souboru s otazkami (nazev souboru): ";
	cin >> path;
	Dotaznik * kviz = buildDotaznik(path);
	cout << "Tve skore je: " << runDotaznik(kviz);
	vymazOtazky(kviz);
	delete kviz;
}

Dotaznik * buildDotaznik(string path)
{
	ifstream file;
	string line;
	Dotaznik* kviz = new Dotaznik{ new Otazka[1], 0 };					//Vytvoření struktury velikosti pole pro otázky.

	file.open("Otázky.txt");											//Otevření souboru s otázkami.

	while (getline(file, line)) {										//Čtení souboru po řádcích.
		if (kviz->delka != 0) {
			reallocate(&kviz->otazky, kviz->delka, kviz->delka + 1);	//Zvětšení pole o jednu otázku.
		}

		//Parsování řádků.
		stringstream ss(line);
		getline(ss, kviz->otazky[kviz->delka].otazka, ';');
		getline(ss, kviz->otazky[kviz->delka].a, ';');
		getline(ss, kviz->otazky[kviz->delka].b, ';');
		getline(ss, kviz->otazky[kviz->delka].c, ';');
		getline(ss, kviz->otazky[kviz->delka].d, ';');
		ss >> kviz->otazky[kviz->delka].spravnaOdpoved;
		kviz->delka++;
	}

	file.close();

	return kviz;
}

int runDotaznik(Dotaznik* kviz)
{
	int skore = 0;
	char odpoved;
	for (int i = 0; i < kviz->delka; i++) {
		cout << kviz->otazky[i].otazka << endl;
		cout << "A: " << kviz->otazky[i].a << endl;
		cout << "B: " << kviz->otazky[i].b << endl;
		cout << "C: " << kviz->otazky[i].c << endl;
		cout << "D: " << kviz->otazky[i].d << endl;
		cout << "Zadejte odpoved: ";
		cin >> odpoved;

		if (odpoved == kviz->otazky[i].spravnaOdpoved) {
			skore++;
			cout << "Spravne!" << endl << endl;
		}

		else {
			cout << "Spatne!" << endl << endl;
		}
	}

	return skore;
}

//Funkce pro zvětšení pole o jednu otázku.
void reallocate(Otazka** old_arr, int old_size, int new_size)
{
	Otazka* new_arr = new Otazka[new_size];								//Vytvoření nového pole o jednu otázku většího.
	
	copy(*old_arr, *old_arr + old_size, &new_arr[0]);					//Zkopírování starého pole do nového.

	delete[] * old_arr;													//Smaže staré pole.
	*old_arr = new_arr;													//Přiřazení nového pole do starého.
}

//Funkce vxčistí alokovanou pamět pro otázky.
void vymazOtazky(Dotaznik* kviz)
{
	delete[] kviz->otazky;
	kviz->otazky = nullptr;
}