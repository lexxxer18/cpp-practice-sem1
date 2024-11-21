
#include <cmath>
#include <functional>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

/**
 * Программа сортировки массива, чтобы все отрицательные числа были
 * расположены вначале по возрастанию, а все положительные – в конце
 * по убыванию.
 *
 * Во всех заданиях предусмотреть заполнение массива по выбору
 * пользователя (случайным образом или из потока ввода). Размерность
 * массива должна быть определена пользователем в диапазоне [0, 100]
 *
 * Пример ввода-вывода (выбор случайного заполнения)
 *
 * Введите размерность массива в диапазоне [0,100]: 5
 * Выберите режим заполнения массива. Введите номер режима:
 * 1 - случайное заполнение
 * 2 - пользовательский ввод
 * 1
 * Вводите числа, нажимая Enter
 * -812 -421 -339 492 191
 *
 * ----------
 *
 * Пример ввода-вывода (выбор пользовательского ввода)
 *
 * Введите размерность массива в диапазоне [0,100]: 5
 * Выберите режим заполнения массива. Введите номер режима:
 * 1 - случайное заполнение
 * 2 - пользовательский ввод
 * 2
 * Вводите числа, нажимая Enter
 * Введите число: -0.1212
 * Введите число: -.2323
 * Введите число: 2222
 * Введите число: 1
 * Введите число: 0.000001
 * -0.2323 -0.1212 2222 1 1e-06
 */

// заполняем массив сгенерированными вещественными числами по сыслке
void generateRandomArr(vector<int>& arr, int size, int min = -100, int max = 100) {
    if (min > max) {
        cerr << "Минимальное значение не может быть больше максимального" << endl;
        return;
    }

    // установим начальное значение генератора
    srand(time(0));

    arr.resize(size);

    for (int i = 0; i < size; ++i) {
        // сгенерируем числа в диапазоне от min до max
        arr[i] = min + rand() % (max - min + 1);
    }
}

// пузырьковая сортировка с модификацией исходного массива по ссылке,
// с указанием функции направления сортировки
void bubbleSort(vector<double>& arr, function<bool(double, double)> compare) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// функция направления сортировки по убыванию
bool compareDescending(double a, double b) { return a < b; }

// функция направления сортировки по возрастанию
bool compareAscending(double a, double b) { return a > b; }

int main() {
    setlocale(LC_ALL, "Russian");
    cout.precision(10);

    int max;

    cout << "Упорядочивание массива по заданному правилу" << endl;
    cout << "---" << endl;

    cout << "Введите размерность массива в диапазоне [0,100]: ";
    cin >> max;

    if (max < 1 || max > 100) {
        cout << "Размер массива должен быть от 1 до 100. Установлено значение 100 по умолчанию"
             << endl;
        max = 100;
    }

    cout << "Выберите режим заполнения массива. Введите номер режима: " << endl;
    cout << "1 - случайное заполнение" << endl;
    cout << "2 - пользовательский ввод" << endl;

    int mode = 1;
    cin >> mode;

    if (mode > 2) {
        mode = 2;
    } else if (mode < 1) {
        mode = 1;
    }

    cout << "Вводите числа, нажимая Enter" << endl;

    vector<double> numbers;
    vector<int> randomNumbers;
    vector<double> negativeNums;
    vector<double> positiveNums;

    if (mode == 2) {
        for (int i = 0; i < max; i++) {
            double number;

            cout << "Введите число: ";
            cin >> number;

            if (number >= 0) {
                positiveNums.push_back(number);
            } else {
                negativeNums.push_back(number);
            }
        }

    } else if (mode == 1) {
        generateRandomArr(randomNumbers, max);

        for (int i = 0; i < max; i++) {
            if (randomNumbers[i] >= 0) {
                positiveNums.push_back(randomNumbers[i]);
            } else {
                negativeNums.push_back(randomNumbers[i]);
            }
        }
    }

    // отсортируем массив положительных чисел по убыванию
    bubbleSort(positiveNums, compareDescending);

    // отсортируем массив отрицательных чисел по возрастанию
    bubbleSort(negativeNums, compareAscending);

    // заполним итоговый массив отсоритрованными числами

    for (int i = 0; i < negativeNums.size(); i++) {
        numbers.push_back(negativeNums[i]);
    }

    for (int i = 0; i < positiveNums.size(); i++) {
        numbers.push_back(positiveNums[i]);
    }

    for (int i = 0; i < max; i++) {
        cout << numbers[i] << " ";
    }

    return 0;
}