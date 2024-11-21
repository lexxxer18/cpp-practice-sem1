#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
 * Версия 1.3 (графическое представление через SFML)
 *
 * Программа определяет принадлежит ли точка к области фигур, которые заданы
 * неравенствами по условию задачи.
 *
 * Пользователь вводит координаты точек, а по завершению ввода вводит символ `q`,
 * чтобы получить сводку о том, какие точки (координаты и их количество) принадлежат области фигур,
 * а какие точки (координаты и их количество) НЕ принадлежат области фигур.
 * Помимо сводки пользователь получает графическое представление принадлежности точки
 * областям фигуры, заданной неравенствами. Используется библиотека SFML.
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

// объявим пользовательский тип данных с полями x, y
struct Point {
    double x;
    double y;
};

bool checkInCircle(double x, double y) { return pow(x + 4, 2) + pow(y - 4, 2) <= 9; }

bool checkInTriangle(double x, double y) { return x >= 0 && y >= 0 && 6 - x >= y; }

/**
 * Функция рисования графического представления системы неравенств и точек,
 * которые принадлежат либо не принадлежат областям фигур.
 * В качестве аргумента функция получает динамический массив точек, которые
 * требуется нарисовать на координатной плоскости
 */
void renderView(vector<Point> points) {
    // создаём окно для отображения (размер 800x800 пикселей) с заголовком
    sf::RenderWindow window(sf::VideoMode(800, 800),
                            "Программа определения принадлежности точки к области фигур");

    // создаём камеру (вид), охватывающую определённую область
    sf::View view(sf::FloatRect(-10, -10, 20, 20));

    // устанавливаем центр вида в точке (0, 0)
    view.setCenter(0, 0);

    // устанавливаем размер области (20x20), инвертируя ось y
    view.setSize(20, -20);

    // применяем вид к окну
    window.setView(view);

    // создаём круг (представляющий область круга на графике)
    sf::CircleShape circle(3);

    // устанавливаем позицию центра круга (-4, 4), скорректированную на радиус
    circle.setPosition(-4 - 3, 4 - 3);

    // устанавливаем красный цвет с прозрачностью 100
    circle.setFillColor(sf::Color(255, 0, 0, 100));

    // создаём треугольник (область треугольника)
    sf::ConvexShape triangle;

    // устанавливаем количество вершин треугольника — 3
    triangle.setPointCount(3);

    // устанавливаем первую вершину в (0, 0)
    triangle.setPoint(0, sf::Vector2f(0, 0));

    // устанавливаем вторую вершину в (6, 0)
    triangle.setPoint(1, sf::Vector2f(6, 0));

    // устанавливаем третью вершину в (0, 6)
    triangle.setPoint(2, sf::Vector2f(0, 6));

    // устанавливаем синий цвет с прозрачностью 100
    triangle.setFillColor(sf::Color(0, 0, 255, 100));

    // создаём горизонтальную ось (ось x)
    sf::RectangleShape xAxis(sf::Vector2f(20, 0.05f));

    // размещаем ось по центру окна
    xAxis.setPosition(-10, 0);

    // устанавливаем чёрный цвет
    xAxis.setFillColor(sf::Color::Black);

    // создаём вертикальную ось (ось y)
    sf::RectangleShape yAxis(sf::Vector2f(20, 0.05f));

    // размещаем ось по центру окна
    yAxis.setPosition(0, -10);

    // поворачиваем ось на 90 градусов
    yAxis.setRotation(90);

    // устанавливаем чёрный цвет
    yAxis.setFillColor(sf::Color::Black);

    // основной цикл окна
    while (window.isOpen()) {
        // создаём объект для обработки событий
        sf::Event event;

        // проверяем все события окна
        while (window.pollEvent(event)) {
            // если событие — закрытие окна
            if (event.type == sf::Event::Closed) {
                // закрываем окно
                window.close();
            }
        }

        // очищаем окно, заполняя его белым цветом
        window.clear(sf::Color::White);

        // рисуем координатные оси
        window.draw(xAxis);
        window.draw(yAxis);

        // рисуем круг
        window.draw(circle);

        // рисуем треугольник
        window.draw(triangle);

        // в итераторе for будем определять тип point автоматически и передавать
        // по ссылке с помощью &, чтобы не расходовать память на копирование.
        for (const auto& point : points) {
            // создаём точку как маленький круг радиуса 0.1
            sf::CircleShape pointShape(0.1);

            // сдвигаем позицию, чтобы круг находился точно на точке
            pointShape.setPosition(point.x - 0.1, point.y - 0.1);

            if (checkInCircle(point.x, point.y) || checkInTriangle(point.x, point.y)) {
                pointShape.setFillColor(sf::Color::Green);
            } else {
                pointShape.setFillColor(sf::Color::Red);
            }

            // рисуем точку
            window.draw(pointShape);
        }

        // отображаем все нарисованные элементы на экране
        window.display();
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    string input;

    // объявим динамический массив точек с типом Point
    vector<Point> points;
    set<string> insidePoints;
    set<string> outsidePoints;

    cout << "Программа определения принадлежности точки к области фигур" << endl;
    cout << "Введите координаты точки через побел в формате (x y) или 'q' для завершения ввода"
         << endl;

    int i = 1;

    while (true) {
        cout << "Точка №" << i++ << ": ";

        getline(cin, input);

        Point point;

        if (input == "q") {
            break;
        }

        stringstream ss(input);
        ss >> point.x >> point.y;

        stringstream ss1;

        ss1 << "(" << point.x << "," << point.y << ")";
        string pointStr = ss1.str();

        if (checkInCircle(point.x, point.y) || checkInTriangle(point.x, point.y)) {
            insidePoints.insert(pointStr);
        } else {
            outsidePoints.insert(pointStr);
        }

        // добавляем в дин. массив точку
        points.push_back(point);
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

    renderView(points);

    return 0;
}