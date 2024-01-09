#include <iostream>

using namespace std;


struct Matice
{
	int radky;
	int sloupce;
	int** matice;
};

Matice* initMatrix(int radky, int sloupce)
{
	Matice* matice = new Matice;
	matice->radky = radky;
	matice->sloupce = sloupce;
	matice->matice = new int* [radky];

	for (int i = 0; i < radky; i++)
	{
		matice->matice[i] = new int[sloupce];
	}

	return matice;
}

int** initArray(int radky, int sloupce)
{
	int** matice = new int* [radky];

	for (int i = 0; i < radky; i++)
	{
		matice[i] = new int[sloupce];
	}

	return matice;
}
void sestrojMatici(int** matice, int radky, int sloupce)
{
	for (int i = 0; i < radky; i++)
	{
		for (int j = 0; j < sloupce; j++)
		{
			std::cout << "Zadej hodnotu pro [" << i << "][" << j << "]: ";
			std::cin >> matice[i][j];
		}
	}

	std::cout << std::endl << "Vypis matice:" << std::endl;

	for (int i = 0; i < radky; i++)
	{
		for (int j = 0; j < sloupce; j++)
		{
			std::cout << matice[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	int radky, sloupce;

	std::cout << "Zadej pocet radku: ";
	std::cin >> radky;
	std::cout << "Zadej pocet sloupcu: ";
	std::cin >> sloupce;
	std::cout << std::endl;

	int** matice = initArray(radky, sloupce);
	sestrojMatici(matice, radky, sloupce);

	return 0;
}