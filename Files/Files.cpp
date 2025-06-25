#include <iostream>
#include <fstream>
#include <string>     // для getline
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    // открываем новый файл для записи
    ofstream out("hello.txt");
    if (out.is_open())
    {
        out << "Привет Вася !" << endl;
    }
    out.close();
    cout << "Файл hello.txt создан" << endl;

    // открываем файл для добавления
    out.open("hello.txt", ios::app);
    if (out.is_open())
    {
        out << "Welcome to C++" << endl;
        cout << "Файл hello.txt дописан" << endl;
    }
    else
    {
        out << "Файл hello.txt не найден !!!" << endl;
    }
    out.close();

    // чтение файла
    string line;

    ifstream in("hello.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        out << "Файл hello.txt не найден !!!" << endl;
    }
    in.close();     // закрываем файл
}