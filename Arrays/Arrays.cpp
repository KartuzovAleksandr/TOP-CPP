#include <iostream>
#include <array>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    const int n = 10;
    array<int, n> m;

    srand(time(NULL));
    // m.fill(rand() % 101 - 50); // будут одинаковые к сожалению
    for (int i = 0; i < m.size(); i++)
    {
        m[i] = rand() % 101 - 50;
        cout << m[i] << endl;
    }
}