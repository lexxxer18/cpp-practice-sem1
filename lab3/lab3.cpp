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
 * Сколько целиндров хотите рассчитать? 3
 * ---
 * Введите параметры цилиндра в формате (радиус высота):
 * Цилиндр №1: 1 1
 * Цилиндр №2: 2 2
 * Цилиндр №3: 100 100
 *
 * Рассчет введенных цилиндров
 * ---
 * Объем цилиндра №1 V = 3.14
 * Объем цилиндра №2 V = 25.13
 * Объем цилиндра №3 V = 3141592.65
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

    cout << "Нахождение объема V каждого из n-цилиндров" << endl;
    cout << "---" << endl;

    cout << "Сколько целиндров хотите рассчитать? ";
    cin >> count;
    cout << "---" << endl;

    cout << "Введите параметры цилиндра в формате (радиус высота):" << endl;

    // объявим дин. массив цилиндров
    vector<Cylinder> cylinders;

    for (int i = 0; i < count; i++) {
        Cylinder cyl;

        cout << "Цилиндр №" << i + 1 << ": ";
        cin >> cyl.radius >> cyl.height;

        cylinders.push_back(cyl);
    }

    cout.precision(2);
    cout << endl;
    cout << "Рассчет введенных цилиндров" << endl;
    cout << "---" << endl;

    for (int i = 0; i < count; i++) {
        double r = cylinders[i].radius;
        double h = cylinders[i].height;

        cout << "Объем цилиндра №" << i + 1 << " V = " << calcCylinderVolume(r, h) << endl;
    }

    return 0;
}