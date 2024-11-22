#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

/**
 * Версия 1.1 (указание кол-ва точек и самих точек)
 *
 * Программа определяет принадлежит ли точка к области фигур, которые заданы
 * неравенствами по условию задачи.
 *
 * Пользователь вводит количество точек, их координаты и получает сводку о том,
 * какие точки (координаты и их количество) принадлежат области фигур, а какие точки
 * (координаты и их количество) НЕ принадлежат области фигур.
 *
 * Общее логическое выражение области:
 * (x + 4)^2 + (y - 4)^2 <= 9 OR (x >= 0 AND y => 0 AND 6 - x >= y)
 *
 * Пример ввода-вывода:
 *
 * ✨💻 Программа определения принадлежности точки к области фигур
 * 👉 Укажите кол-во точек: -5
 * ❌ Кол-во точек не может быть отрицательным числом. Число взято по модулю.
 *
 * 👉 Укажите координаты точки №1 в формате (x y): -1 2
 * 👉 Укажите координаты точки №2 в формате (x y): 2 2
 * 👉 Укажите координаты точки №3 в формате (x y): 33 333
 * 👉 Укажите координаты точки №4 в формате (x y): 4 2
 * 👉 Укажите координаты точки №5 в формате (x y): 4 -67
 *
 * 🎯 Точки, попавшие в области фигур:
 * (2,2)
 * (4,2)
 *
 * 📊 Кол-во точек: 2
 *
 * ❌ Точки, не попавшие в области фигур:
 * (-1,2)
 * (33,333)
 * (4,-67)
 *
 * 📊 Кол-во точек: 3
 */

// Проверка находится ли точка внутри круга, включая границы
bool checkInCircle(double x, double y) { return pow(x + 4, 2) + pow(y - 4, 2) <= 9; }

// Проверка находится ли точка внутри треугольника, включая границы
bool checkInTriangle(double x, double y) { return x >= 0 && y >= 0 && 6 - x >= y; }

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    double x, y;

    // множество уникальных строк с координатами точек, попавших в область
    set<string> insidePoints;

    // множество уникальных строк с координатами точек, НЕ попавших в область
    set<string> outsidePoints;

    cout << "✨💻 Программа определения принадлежности точки к области фигур" << endl;

    cout << "👉 Укажите кол-во точек: ";
    cin >> n;
    cin.ignore();

    cout << endl;

    if (n < 0) {
        cout << "❌ Кол-во точек не может быть отрицательным числом. Число взято по модулю."
             << endl;
        n = abs(n);
    }

    int m = 0;

    while (m++ < n) {
        cout << "👉 Укажите координаты точки №" << m << " в формате (x y): ";
        cin >> x >> y;

        // объявляем поток ввода-вывода, чтобы работать с текстовыми данными прямо в памяти
        stringstream ss;

        // отправляем строку в поток
        ss << "(" << x << "," << y << ")";

        // получаем строку из содержимого потока и записываем в переменную строки символов
        string point = ss.str();

        if (checkInCircle(x, y) || checkInTriangle(x, y)) {
            insidePoints.insert(point);
        } else {
            outsidePoints.insert(point);
        }
    }

    cout << endl;

    cout << "🎯 Точки, попавшие в области фигур:" << endl;
    for (auto point : insidePoints) {
        cout << point << endl;
    }
    cout << endl;
    cout << "📊 Кол-во точек: " << insidePoints.size() << endl;

    cout << endl;

    cout << "❌ Точки, не попавшие в области фигур:" << endl;
    for (auto point : outsidePoints) {
        cout << point << endl;
    }
    cout << endl;
    cout << "📊 Кол-во точек: " << outsidePoints.size() << endl;

    return 0;
}