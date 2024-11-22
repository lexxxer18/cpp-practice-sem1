#include <cmath>
#include <iostream>

using namespace std;

/**
 * Программа нахождения суммы ряда с заданной точностью методами:
 * - рекуррентного соотношения
 * - расчета каждого слагаемого
 *
 * Пример ввода-вывода:
 *
 * 🔢🔍 Расчет суммы ряда для 2*sin(x)^2 с заданной точностью
 *
 * 👉 Введите значение x: 1
 * ❌ Значение x должно быть в диапазоне (-1, 1). Выбрано по-умолчанию значение 0.5
 * 👉 Введите точность epsilon: 0.0001
 * 👉 Введите количество членов m ряда: 10
 *
 * 🌀 Методом рекуррентного соотношения
 * 👉 Полученная сумма S = 0.4596974206
 * 👉 Кол-во членов в сумме: 3 из 10
 *
 * 🧮 Методом расчета каждого слагаемого
 * 👉 Получення сумма S = 0.4596974206
 * 👉 Кол-во членов в сумме: 4 из 10
 *
 * ✅ Контроль: 2*sin(x)^2 = 0.4596976941
 *
 */

// укажем возвращаемый тип данных long long для работы с большими числами
long long fact(int n) { return (n == 0 || n == 1) ? 1 : n * fact(n - 1); }

void recurrence(double x, double eps, int m) {
    double a = 2 * pow(x, 2);
    double sum = a;
    int i = 0;

    while (fabs(a) >= eps && i <= m) {
        a *= -pow(2 * x, 2) / ((2 * i + 3) * (2 * i + 4));
        sum += a;

        i++;
    }

    cout << "🌀 Методом рекуррентного соотношения" << endl;
    cout << "👉 Полученная сумма S = " << sum << endl;
    cout << "👉 Кол-во членов в сумме: " << i << " из " << m << endl;
}

void sequence(double x, double eps, int m) {
    double a = x, sum = 0;
    int i = 0;

    while (fabs(a) >= eps && i <= m) {
        a = pow(-1, i) * pow(2 * x, 2 * (i + 1)) / fact(2 * (i + 1));
        sum += a;

        i++;
    }

    cout << "🧮 Методом расчета каждого слагаемого" << endl;
    cout << "👉 Получення сумма S = " << sum << endl;
    cout << "👉 Кол-во членов в сумме: " << i << " из " << m << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout.precision(10);

    cout << "🔢🔍 Расчет суммы ряда для 2*sin(x)^2 с заданной точностью" << endl;
    cout << endl;

    double x, eps;
    int m;

    cout << "👉 Введите значение x: ";
    cin >> x;

    if (abs(x) >= 1) {
        cout << "❌ Значение x должно быть в диапазоне (-1, 1). Выбрано по-умолчанию значение 0.5"
             << endl;
        x = .5;
    }

    cout << "👉 Введите точность epsilon: ";
    cin >> eps;
    cout << "👉 Введите количество членов m ряда: ";
    cin >> m;
    cout << endl;

    recurrence(x, eps, m);
    cout << endl;
    sequence(x, eps, m);
    cout << endl;
    cout << "✅ Контроль: 2*sin(x)^2 = " << 2 * pow(sin(x), 2) << endl;
    cout << endl;

    return 0;
}
