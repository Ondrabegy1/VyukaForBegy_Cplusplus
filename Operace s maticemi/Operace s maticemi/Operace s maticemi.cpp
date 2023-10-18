
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void sestrojMatici(int** pole, int radky, int sloupce) {
	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			cout << setw(4) << pole[i][j];
		}
		cout << endl;
	}
}

void sčítejMatice(int** pole1, int** pole2, int radky, int sloupce) {
	int** pole3 = new int* [radky];

	for (int i = 0; i < radky; i++) {
		pole3[i] = new int[sloupce];
	}

	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			pole3[i][j] = pole1[i][j] + pole2[i][j];
		}
	}

	sestrojMatici(pole3, radky, sloupce);
}

void odečtiMatice(int** pole1, int** pole2, int radky, int sloupce) {
	int** pole3 = new int* [radky];

	for (int i = 0; i < radky; i++) {
		pole3[i] = new int[sloupce];
	}

	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			pole3[i][j] = pole1[i][j] - pole2[i][j];
		}
	}

	sestrojMatici(pole3, radky, sloupce);
}

void násobMatice(int** pole1, int** pole2, int radky1, int sloupce1, int radky2, int sloupce2) {
	if (sloupce1 == radky2) {
		int** pole3 = new int* [radky1];
		for (int i = 0; i < radky1; i++) {
			pole3[i] = new int[sloupce2];
		}

		for (int i = 0; i < radky1; i++) {
			for (int j = 0; j < sloupce2; j++) {
				pole3[i][j] = 0;
				for (int k = 0; k < sloupce1; k++) {
					pole3[i][j] += pole1[i][k] * pole2[k][j];
				}
			}
		}

		sestrojMatici(pole3, radky1, sloupce2);
	}

	else {
		cout << "Nelze provest nasobeni" << endl;
	}
}

void vydělMatice(int** pole1, int** pole2, int radky1, int sloupce1, int radky2, int sloupce2) {
	if (sloupce1 == radky2) {
		int** pole3 = new int* [radky1];
		for (int i = 0; i < radky1; i++) {
			pole3[i] = new int[sloupce2];
		}

		for (int i = 0; i < radky1; i++) {
			for (int j = 0; j < sloupce2; j++) {
				pole3[i][j] = 0;
				for (int k = 0; k < sloupce1; k++) {
					pole3[i][j] += pole1[i][k] / pole2[k][j];
				}
			}
		}

		sestrojMatici(pole3, radky1, sloupce2);
	}

	else {
		cout << "Nelze provest deleni" << endl;
	}
}

void transMatice(int** pole, int radky, int sloupce) {
	int** pole3 = new int* [sloupce];

	for (int i = 0; i < sloupce; i++) {
		pole3[i] = new int[radky];
	}

	for (int i = 0; i < radky; i++) {
		for (int j = 0; j < sloupce; j++) {
			pole3[j][i] = pole[i][j];
		}
	}

	sestrojMatici(pole3, sloupce, radky);
}

int main()
{
	int radky1, sloupce1, radky2, sloupce2;

	cout << "Zadejte pocet radku prvni matice: ";
	cin >> radky1;
	cout << "Zadejte pocet sloupcu prvni matice: ";
	cin >> sloupce1;
	cout << "Zadejte pocet radku druhe matice: ";
	cin >> radky2;
	cout << "Zadejte pocet sloupcu druhe matice: ";
	cin >> sloupce2;

	int** pole1 = new int* [radky1];

	for (int i = 0; i < radky1; i++) {
		pole1[i] = new int[sloupce1];
	}

	int** pole2 = new int* [radky2];

	for (int i = 0; i < radky2; i++) {
		pole2[i] = new int[sloupce2];
	}
	cout << endl;
	cout << "Chcete matice vygenerovat nahodne? (ANO/NE): ";

	string odpoved;
	cin >> odpoved;

	if (odpoved == "ANO") {
		for (int i = 0; i < radky1; i++) {
			for (int j = 0; j < sloupce1; j++) {
				pole1[i][j] = rand() % 10;
			}
		}

		for (int i = 0; i < radky2; i++) {
			for (int j = 0; j < sloupce2; j++) {
				pole2[i][j] = rand() % 10;
			}
		}
	}

	else {
		cout << "Zadejte prvni matici: " << endl;
		for (int i = 0; i < radky1; i++) {
			for (int j = 0; j < sloupce1; j++) {
				cin >> pole1[i][j];
			}
		}

		cout << "Zadejte druhou matici: " << endl;
		for (int i = 0; i < radky2; i++) {
			for (int j = 0; j < sloupce2; j++) {
				cin >> pole2[i][j];
			}
		}
	}

	cout << endl;

	cout << "Prvni matice: " << endl;
	sestrojMatici(pole1, radky1, sloupce1);

	cout << endl;

	cout << "Druha matice: " << endl;
	sestrojMatici(pole2, radky2, sloupce2);

	cout << endl;

	if (radky1 == radky2 && sloupce1 == sloupce2) {
		cout << "Soucet matic: " << endl;
		sčítejMatice(pole1, pole2, radky1, sloupce1);
	}

	else {
		cout << "Nelze provest scitani" << endl;
	}

	cout << endl;

	if (radky1 == radky2 && sloupce1 == sloupce2) {
		cout << "Rozdil matic: " << endl;
		odečtiMatice(pole1, pole2, radky1, sloupce1);
	}

	else {
		cout << "Nelze provest odcitani" << endl;
	}

	cout << endl;

	cout << "Soucin matic: " << endl;
	násobMatice(pole1, pole2, radky1, sloupce1, radky2, sloupce2);

	cout << endl;

	cout << "Podil matic: " << endl;
	vydělMatice(pole1, pole2, radky1, sloupce1, radky2, sloupce2);

	cout << endl;

	cout << "Transponovane matice: " << endl;
	transMatice(pole1, radky1, sloupce1);
	cout << endl;
	transMatice(pole2, radky2, sloupce2);

	return 0;
}