
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct struktura
{
	int hodnota;
	struktura* ukazatel;
};

void printStruktury(int* arr, int pocet);
void printList(struktura* str);
void deleteList(struktura* str);

int* randomStruktury(int pocet);

struktura* newStruktura(int hodnota);
struktura* randomList(int* arr, int pocet);
struktura* findStrukturu(struktura* str, int ukazatel);
void deleteStrukturu(struktura** str, int ukazatel);
struktura* addStrukturu(struktura* str, int ukazatel, int hodnota);

int main()
{
	int pocet, ukazatel, hodnota;

	cout << "Zadejte pocet struktur: ";
	cin >> pocet;

	int* arr = randomStruktury(pocet);
	struktura* str = randomList(arr, pocet);

	cout << "Pole: ";
	printStruktury(arr, pocet);

	cout << "Seznam: ";
	printList(str);

	cout << "Zadejte ukazatel: ";
	cin >> ukazatel;

	cout << "Zadejte hodnotu: ";
	cin >> hodnota;

	struktura* tmp = findStrukturu(str, ukazatel);

	if (tmp != NULL)
	{
		cout << "Nalezena struktura: " << tmp->hodnota << endl;
	}
	else
	{
		cout << "Struktura nenalezena" << endl;
	}

	str = addStrukturu(str, ukazatel, hodnota);

	cout << "Seznam: ";
	printList(str);

	deleteStrukturu(&str, ukazatel);

	cout << "Seznam: ";
	printList(str);

	deleteList(str);
	delete[] arr;

	return 0;
}

void printStruktury(int* arr, int pocet)
{
	for (int i = 0; i < pocet; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void printList(struktura* str)
{
	while (str != NULL)
	{
		cout << str->hodnota << " ";
		str = str->ukazatel;
	}

	cout << endl;
}

void deleteList(struktura* str)
{
	struktura* tmp;

	while (str != NULL)
	{
		tmp = str;
		str = str->ukazatel;
		delete tmp;
	}
}

int* randomStruktury(int pocet)
{
	int* arr = new int[pocet];

	for (int i = 0; i < pocet; i++)
	{
		arr[i] = rand() % 100;
	}

	return arr;
}

struktura* newStruktura(int hodnota)
{
	struktura* str = new struktura;
	str->hodnota = hodnota;
	str->ukazatel = NULL;

	return str;
}

struktura* randomList(int* arr, int pocet)
{
	struktura* str = newStruktura(arr[0]);
	struktura* tmp = str;

	for (int i = 1; i < pocet; i++)
	{
		tmp->ukazatel = newStruktura(arr[i]);
		tmp = tmp->ukazatel;
	}

	return str;
}

struktura* findStrukturu(struktura* str, int ukazatel)
{
	while (str != NULL)
	{
		if (str->hodnota == ukazatel)
		{
			return str;
		}

		str = str->ukazatel;
	}

	return NULL;
}

void deleteStrukturu(struktura** str, int ukazatel)
{
	struktura* tmp = *str;

	if (tmp->hodnota == ukazatel)
	{
		*str = tmp->ukazatel;
		delete tmp;
		return;
	}

	while (tmp->ukazatel != NULL)
	{
		if (tmp->ukazatel->hodnota == ukazatel)
		{
			struktura* tmp2 = tmp->ukazatel;
			tmp->ukazatel = tmp->ukazatel->ukazatel;
			delete tmp2;
			return;
		}

		tmp = tmp->ukazatel;
	}
}

struktura* addStrukturu(struktura* str, int ukazatel, int hodnota)
{
	struktura* tmp = str;

	while (tmp != NULL)
	{
		if (tmp->hodnota == ukazatel)
		{
			struktura* tmp2 = tmp->ukazatel;
			tmp->ukazatel = newStruktura(hodnota);
			tmp->ukazatel->ukazatel = tmp2;
			return str;
		}

		tmp = tmp->ukazatel;
	}

	return NULL;
}