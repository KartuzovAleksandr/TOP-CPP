// Заполните случайными целыми числами массив(vector) размерностью n > 0.
// Выделите четные числа и отсортируйте по возрастанию, нечетные - по убыванию
// Результат записать обратно

#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
using namespace std;

// если число четное
bool is_even(int n) { return n % 2 == 0; }
// если число нечетное
bool is_odd(int n) { return n % 2 != 0; }

// для вывода вектора на консоль
void print(const vector<int>& data)
{
    for (const auto& n : data)
    {
        cout << n << "\t";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "RU");
    srand(static_cast<unsigned>(time(0))); // функция генерирует рандомные числа
    // спросить размер и заполнить случайными числами
    int n;
    do {
        cout << "Введите размер массива (n > 0): ";
        cin >> n;
    } while (n <= 0);

    vector<int> numbers;
    numbers.reserve(n);
    for (int i = 0; i < n; ++i) {
        numbers.push_back(rand() % 100); // числа от 0 до 99
    }
    vector<int> even_numbers{ numbers };
    erase_if(even_numbers, is_odd);
    cout << "Четные числа:" << endl;
    print(even_numbers);
    sort(begin(even_numbers), end(even_numbers)); // сортируем четные
    cout << "По возрастанию:" << endl;
    print(even_numbers);

    vector<int> odd_numbers{ numbers };
    erase_if(odd_numbers, is_even);
    cout << "Нечетные числа:" << endl;
    print(odd_numbers);
    sort(rbegin(odd_numbers), rend(odd_numbers)); // сортируем вектор по убыванию
    cout << "По убыванию:" << endl;
    print(odd_numbers);

    // слияние результатов
    // cout << "Even " + even_numbers.size() << "Odd " + odd_numbers.size() << " " + numbers.size() << endl;
    vector<int> res_numbers;
    res_numbers.insert(res_numbers.end(), even_numbers.begin(), even_numbers.end());
    res_numbers.insert(res_numbers.end(), odd_numbers.begin(), odd_numbers.end());
    // merge(even_numbers.begin(), even_numbers.end(), odd_numbers.begin(), odd_numbers.end(), res_numbers.begin());
    cout << "Результат:" << endl;
    print(res_numbers);
}