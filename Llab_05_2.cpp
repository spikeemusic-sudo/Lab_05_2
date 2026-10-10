// Lab_05_2.cpp
// Фащевський Богдан
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора за допомогою функцій
// Варіант 28 (1 спосіб)

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Прототипи допоміжних функцій
void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, dx, eps, s = 0;
    int n = 0;

    // Введення вхідних даних з клавіатури
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    // Форматування та вивід шапки таблиці
    cout << fixed;
    cout << "-----------------------------------------" << endl;
    cout << "|   x   |  arctg(x)  |     S      |  n  |" << endl;
    cout << "-----------------------------------------" << endl;

    // Цикл табулювання функції на інтервалі [xp, xk]
    double x = xp;
    while (x <= xk)
    {
        S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << atan(x) << " |"
            << setw(10) << setprecision(5) << s << " |"
            << setw(5) << n << " |"
            << endl;
        x += dx;
    }
    cout << "-----------------------------------------" << endl;

    return 0;
}

// Функція обчислення суми ряду Тейлора
void S(const double x, const double eps, int& n, double& s)
{
    const double PI = 4.0 * atan(1.0); // Константа pi
    n = 0;
    double a = -1.0 / x;               // Перший доданок ряду (при n = 0)
    s = PI / 2.0 + a;                  // Початкове значення суми (pi/2 + a0)

    do {
        n++;
        A(x, n, a);                    // Рекурентне обчислення наступного доданку
        s += a;                        // Накопичення суми
    } while (abs(a) >= eps);
}

// Функція обчислення нового доданку за рекурентною формулою
void A(const double x, const int n, double& a)
{
    double R = -(2.0 * n - 1.0) / ((2.0 * n + 1.0) * x * x); // Коефіцієнт рекурентності
    a *= R;
}