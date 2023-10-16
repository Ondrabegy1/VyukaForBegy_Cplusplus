//Dva způsoby řešení. Jeden přes cyklus a druhý přes rekurzní funkci.

#include <iostream>

using namespace std;

//První způsob řešení (cyklus).
/*void vypocetFaktorialu(int cislo)
{
    int vysledek = 1;

    for (int i = 1; i <= cislo; i++)
    {
        vysledek *= i;
    }

    cout << vysledek << endl;
}*/

//Druhý způsob řešení (rekurze).
int vypocetFaktorialu(int cislo)
{
    if (cislo == 1)
    {
        return 1;
    }
    else
    {
        return cislo * vypocetFaktorialu(cislo - 1);
    }
}

int main()
{
    int cislo;
    cout << "Zadejte cislo: ";
    cin >> cislo;

    vypocetFaktorialu(cislo);

    cout << vypocetFaktorialu(cislo) << endl;

    return 0;
}