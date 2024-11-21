
#include <cmath>
#include <functional>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

/**
 * Программа генерирует двумерный массив чисел в диапазоне от -100 до 100, а потом выводит
 * сгенерированную матрицу пользователю.
 * Потом выводится сводка о том, все ли строки содержат хотя бы один отрицательный элемент.
 * Если не все, то выводится номер первой строки, где нет отрицательных элементов.
 *
 * Пример ввода-вывода:
 *
 *
 */

void generateRandomArr(vector<vector<int>>& arr, int rows, int cols, int min = -100,
                       int max = 100) {
    if (min > max) {
        std::cerr << "Минимальное значение не может быть больше максимального" << std::endl;
        return;
    }

    srand(time(0));
    arr.resize(rows);

    for (int i = 0; i < rows; ++i) {
        arr[i].resize(cols);

        for (int j = 0; j < cols; ++j) {
            arr[i][j] = min + rand() % (max - min + 1);
        }
    }
}

int main(int argc, char const* argv[]) {
    setlocale(LC_ALL, "Russian");
    int rows, cols, type = 1;

    cout << "Работа с двумерным массивом (матрицей)" << endl;
    cout << "---" << endl;

    cout << "Выберите какую матрицу хотите сгенерировать: " << endl;
    cout << "1 - квадратная матрица" << endl;
    cout << "2 - произвольная матрица" << endl;
    cin >> type;

    // если вышли за допустимые границы type, устанавливаем дефолтные
    if (type > 2) {
        cout << "Введен некорректный номер. По умолчанию выбран тип \"произвольная матрица\""
             << endl;
        type = 2;
    } else if (type < 1) {
        cout << "Введен некорректный номер. По умолчанию выбран тип \"квадратная матрица\"" << endl;
        type = 1;
    }

    vector<vector<int>> matrix;

    // генерация матрицы в зависимости от выбранного типа
    if (type == 1) {
        int size;

        cout << "Введите размерность массива в диапазоне [0,100] для составления квадратной "
                "матрицы: ";
        cin >> size;

        if (size < 1 || size > 100) {
            cout << "Размер массива должен быть от 1 до 100. Установлено значение 100 по умолчанию"
                 << endl;
            size = 100;
        }

        rows = cols = size;

        generateRandomArr(matrix, rows, cols);
    } else if (type == 2) {
        cout << "Введите кол-во строк в диапазоне [0,100] для составления про матрицы: ";
        cin >> rows;

        if (rows < 1 || rows > 100) {
            cout << "Количество строк быть от 1 до 100. Установлено значение 100 по умолчанию"
                 << endl;
            rows = 100;
        }

        cout << "Введите кол-во столбцов в диапазоне [0,100] для составления про матрицы: ";
        cin >> cols;

        if (cols < 1 || cols > 100) {
            cout << "Количество стообцов быть от 1 до 100. Установлено значение 100 по умолчанию"
                 << endl;
            cols = 100;
        }

        generateRandomArr(matrix, rows, cols);
    }

    cout << endl;
    cout << "Сгенерированная матрица двумерного массива:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout.width(5);
            cout << matrix[i][j] << "\t";
        }

        cout << endl;
    }

    cout << endl;

    int negativesCount = 0;
    vector<int> positiveRows;

    for (int i = 0; i < rows; i++) {
        int positiveRow = -1;

        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < 0) {
                positiveRow = -1;
                negativesCount++;
                break;
            } else {
                positiveRow = i + 1;
            }
        }

        if (positiveRow > -1) {
            positiveRows.push_back(positiveRow);
        }
    }

    cout << "Все ли строки содержат хотя бы один отрицательный элемент?" << endl;
    cout << "Ответ: " << (negativesCount == rows ? "Да" : "Нет") << endl;

    if (positiveRows.size() > 0) {
        cout << "Номер первой строки, в которой нет отрицательных элементов: " << positiveRows[0]
             << "\n\n";

        cout << "Список номеров всех строк, которые не содержат отрицательных чисел: " << endl;

        for (const auto& num : positiveRows) {
            cout << num << endl;
        }
    }

    return 0;
}
