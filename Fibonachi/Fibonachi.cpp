#include <iostream>
using namespace std;

int fibo(int n);

int main()
{
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите значение n: ";
    cin >> n;
    cout << endl;
    cout << "Число Фибоначчи: " << fibo(n) << endl;
}
// написать рекурсией
int fibo(int n) {
    switch (n) {
    case 0: return 0;
        break;
    case 1: return 1;
        break;
    default:
        return fibo(n - 2) + fibo(n - 1);
    }
}