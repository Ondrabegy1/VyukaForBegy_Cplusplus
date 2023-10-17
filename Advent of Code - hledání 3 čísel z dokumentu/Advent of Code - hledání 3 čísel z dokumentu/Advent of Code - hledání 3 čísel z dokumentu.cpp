//V tomto programu se hledají 3 čísla z dokumentu, která dohromady dávají 2020 a vypíše jejich součin.
//Název souboru je "2020.txt".

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("2020.txt");
    vector<int> numbers;
    int number;
    while (file >> number) {
        numbers.push_back(number);
    }
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size(); i++) {
        int left = i + 1;
        int right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[i] + numbers[left] + numbers[right];
            if (sum == 2020) {
                cout << numbers[i] << " * " << numbers[left] << " * " << numbers[right] << " = " << numbers[i] * numbers[left] * numbers[right] << "\n";
                return 0;
            }
            else if (sum < 2020) {
                left++;
            }
            else {
                right--;
            }
        }
    }
}