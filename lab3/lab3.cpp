#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Программа нахождения объема V_i каждого из n цилиндров,
 * при заданных радиусах оснований {R_1, R_2, ..., R_n} и высотах {H_1, H_2, ..., H_n}
 *
 * Пример ввода-вывода:
 *
 * 📐📊 Нахождение объема V каждого из n-цилиндров
 *
 * 👉 Сколько целиндров хотите рассчитать? 3
 * 👉 Введите параметры цилиндра в формате (радиус высота):
 * 📊 Цилиндр №1: 10 1.45
 * 📊 Цилиндр №2: -45 -5
 * ❌ Введен отрицательный радиус. Число взято по модулю.
 * ❌ Введена отрицательная высота. Число взято по модулю.
 * 📊 Цилиндр №3: 0.0001 -1
 * ❌ Введена отрицательная высота. Число взято по модулю.
 *
 * 🏁📈 Рассчет введенных цилиндров
 * 🔖 Объем цилиндра №1 V = 4.6e+02
 * 🔖 Объем цилиндра №2 V = 3.2e+04
 * 🔖 Объем цилиндра №3 V = 3.1e-08
 */

struct Cylinder {
    double radius;
    double height;
};

double calcCylinderVolume(double r, double h) { return M_PI * pow(r, 2) * h; }

int main() {
    setlocale(LC_ALL, "Russian");
    string input;

    int count = 0;

    cout << "📐📊 Нахождение объема V каждого из n-цилиндров" << endl;
    cout << endl;

    cout << "👉 Сколько целиндров хотите рассчитать? ";
    cin >> count;

    if (count < 0) {
        cout << "❌ Введено отрицательное количество. Число взято по модулю." << endl;
        count = abs(count);
    }

    cout << "👉 Введите параметры цилиндра в формате (радиус высота):" << endl;

    // объявим дин. массив цилиндров
    vector<Cylinder> cylinders;

    for (int i = 0; i < count; i++) {
        Cylinder cyl;

        cout << "📊 Цилиндр №" << i + 1 << ": ";
        cin >> cyl.radius >> cyl.height;

        if (cyl.radius < 0) {
            cout << "❌ Введен отрицательный радиус. Число взято по модулю." << endl;
            cyl.radius = abs(cyl.radius);
        }

        if (cyl.height < 0) {
            cout << "❌ Введена отрицательная высота. Число взято по модулю." << endl;
            cyl.height = abs(cyl.height);
        }

        cylinders.push_back(cyl);
    }

    cout.precision(2);
    cout << endl;
    cout << "🏁📈 Рассчет введенных цилиндров" << endl;

    for (int i = 0; i < count; i++) {
        double r = cylinders[i].radius;
        double h = cylinders[i].height;

        cout << "🔖 Объем цилиндра №" << i + 1 << " V = " << calcCylinderVolume(r, h) << endl;
    }

    return 0;
}