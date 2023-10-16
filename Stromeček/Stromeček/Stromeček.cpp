#include <iostream>

using namespace std;

void vytvoreniKmene(int vyska, int sirka, int vyska_stromu)
{
    for (int i = 0; i < vyska; i++)
    {
        for (int j = 0; j < vyska_stromu - sirka / 2; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < sirka; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void vytvoreniKoruny(int vyska)
{
    for (int i = 0; i < vyska; i++)
    {
        for (int j = 0; j < vyska - i; j++)
        {
            cout << " ";
        }

        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}



int main()
{
    int vyska_stromu;
    cout << "Zadejte vysku stromu: ";
    cin >> vyska_stromu;

    int sirka;
    cout << "Zadejte sirku kmene: ";
    cin >> sirka;

    int vyska;
    cout << "Zadejte vysku kmene: ";
    cin >> vyska;

    vytvoreniKoruny(vyska_stromu);
    vytvoreniKmene(vyska, sirka, vyska_stromu);

    
    return 0;
}