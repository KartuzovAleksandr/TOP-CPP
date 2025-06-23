#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// если число четное
bool is_even(int n) { return n % 2 == 0; }
// если число положительное
bool is_positive(int n) { return n > 0; }
// если число больше 10
bool is_greater10(int n) { return n > 10; }

template <typename T>
void findValue(const vector<T>& data, bool(*condition)(T))
{
    auto result{ find_if(begin(data), end(data), condition) };
    if (result == end(data))
        cout << "Value not found" << endl;
    else
        cout << "Value found at position " << (result - begin(data)) << endl;
}

bool compare(int& left, int& right)
{
    return left > right;
}

int main()
{
    setlocale(LC_ALL, "RU");
    vector<int> numbers{ -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5 };
    cout << "Min: " << *min_element(begin(numbers), end(numbers)) << endl;
    cout << "Max: " << *max_element(begin(numbers), end(numbers) - 3) << endl;
    findValue(numbers, is_even);        // Value found at position 1
    findValue(numbers, is_positive);    // Value found at position 6
    findValue(numbers, is_greater10);   // Value not found
    sort(begin(numbers), end(numbers)); // сортируем вектор
    cout << "По возрастанию:" << endl;
    for (const auto& n : numbers)
    {
        cout << n << endl;
    }
    // sort(begin(numbers), end(numbers), compare); // сортируем вектор
    sort(rbegin(numbers), rend(numbers)); // сортируем вектор
    cout << "По убыванию:" << endl;
    for (const auto& n : numbers)
    {
        cout << n << endl;
    }
}