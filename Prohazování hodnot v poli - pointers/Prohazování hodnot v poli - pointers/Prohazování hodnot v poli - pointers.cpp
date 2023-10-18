#include <iostream>

using namespace std;

void prohodPromene(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a;
	int b;

	cout << "Zadejte a: ";
	cin >> a;
	cout << "Zadejte b: ";
	cin >> b;
	cout << endl;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl << endl;

	prohodPromene(&a, &b);

	cout << "a = " << a << " po prohozeni" << endl;
	cout << "b = " << b << " po prohozeni" << endl;

	return 0;
}