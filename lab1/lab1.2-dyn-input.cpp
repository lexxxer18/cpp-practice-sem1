#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

/**
 * Версия 1.2 (динамический ввод точек)
 *
 * Программа определяет принадлежит ли точка к области фигур, которые заданы
 * неравенствами по условию задачи.
 *
 * Пользователь вводит координаты точек, а по завершению ввода вводит символ `q`,
 * чтобы получить сводку о том, какие точки (координаты и их количество) принадлежат области фигур,
 * а какие точки (координаты и их количество) НЕ принадлежат области фигур.
 *
 * Общее логическое выражение области:
 * (x + 4)^2 + (y - 4)^2 <= 9 OR (x >= 0 AND y => 0 AND 6 - x >= y)
 *
 * Пример ввода-вывода:
 *
 * Введите координаты точки через побел в формате (x y) или 'q' для завершения ввода
 * Точка №1: 1 1
 * Точка №2: 2 2
 * Точка №3: 3 3
 * Точка №4: 4 4
 * ==============
 * Точки, попавшие в области фигур:
 * (1,1)
 * (2,2)
 * (3,3)
 * ---
 * Кол-во точек: 3
 * ==============
 * Точки, не попавшие в области фигур:
 * (4,4)
 * ---
 * Кол-во точек: 1
 */

bool checkInCircle(double x, double y) { return pow(x + 4, 2) + pow(y - 4, 2) <= 9; }

bool checkInTriangle(double x, double y) { return x >= 0 && y >= 0 && 6 - x >= y; }

int main() {
    setlocale(LC_ALL, "Russian");

    string input;

    set<string> insidePoints;
    set<string> outsidePoints;

    cout << "Программа определения принадлежности точки к области фигур" << endl;
    cout << "Введите координаты точки через побел в формате (x y) или 'q' для завершения ввода"
         << endl;

    int i = 1;

    while (true) {
        cout << "Точка №" << i++ << ": ";

        // запишем в input целиком всю строку чисел, разделенных символами пробела,
        // чтобы можно было контролировать ввод символа `q`
        getline(cin, input);

        double x, y;

        // останавливаем ввод, если ввели `q`
        if (input == "q") {
            break;
        }

        // запишем строку в поток, чтобы использовать ввод-вывод прямо в памяти
        stringstream ss(input);

        // возьмем строку из памяти и извлечем из нее подстроки, разделенные знаками пробелов
        ss >> x >> y;

        stringstream ss1;

        ss1 << "(" << x << "," << y << ")";
        string pointStr = ss1.str();

        if (checkInCircle(x, y) || checkInTriangle(x, y)) {
            insidePoints.insert(pointStr);
        } else {
            outsidePoints.insert(pointStr);
        }
    }

    cout << "==============" << endl;

    cout << "Точки, попавшие в области фигур:" << endl;
    for (const auto& point : insidePoints) {
        cout << point << endl;
    }
    cout << "---" << endl;
    cout << "Кол-во точек: " << insidePoints.size() << endl;

    cout << "==============" << endl;

    cout << "Точки, не попавшие в области фигур:" << endl;
    for (const auto& point : outsidePoints) {
        cout << point << endl;
    }
    cout << "---" << endl;
    cout << "Кол-во точек: " << outsidePoints.size() << endl;

    return 0;
}