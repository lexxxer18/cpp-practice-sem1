#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * Программа проверки, одинаковое ли число открывающих и закрывающих скобок
 * в строке, которую ввел пользователь. Проверка будет пройдена, если все скобки
 * имею закрывающую скобку и являются парными. Например: {()<>}.
 * Стройка не пройдет проверку, если какая-либо открывающая скобка не будет иметь
 * закрывающую скобку, либо где-то будет не верный порядок скобок. Например: {[}]
 * или [{].
 *
 * --------
 *
 * Пример ввода-вывода (выбор запуска тестов):
 *
 * Выберите действия:
 * 1 - запустить тесты
 * 2 - ввести строку для проверки на расстановку скобок
 * 1
 * ❌ Скобки в *&NC)(N%^BW%Q)<}_)_C)WMW*ERGrh расставлены некорректно
 * ✅ Скобки в UYU<N>K<{IuNuiS9}><>7((6!!!!23)){.}+!9n8c4t расставлены корректно
 * ❌ Скобки в UYU<N>K<{IuNuiS9}><>7((6!!!!23)){.}]+!9n8c4t расставлены некорректно
 * ✅ Скобки в This ({is}[<{some}>]) string! расставлены корректно
 *
 * --------
 *
 * Пример ввода-вывода (выбор ввода строки для проверки на расстановку):
 *
 * Выберите действия:
 * 1 - запустить тесты
 * 2 - ввести строку для проверки на расстановку скобок
 * 2
 * Введите строку: лылап?()"№;%%%%{<<<<>>>>}
 * ✅ Скобки в лылап?()"№;%%%%{<<<<>>>>} расставлены корректно
 */

bool checkBracketsBalance(const string& str) {
    // стек закрывающих скобок
    stack<char> bracketsStack;

    for (const char ch : str) {
        switch (ch) {
            // если встречаем какую-либо открывающую скобку,
            // добавим в стек ее парную закрывающую скобку
            case '<':
                bracketsStack.push('>');
                break;
            case '{':
                bracketsStack.push('}');
                break;
            case '[':
                bracketsStack.push(']');
                break;
            case '(':
                bracketsStack.push(')');
                break;
            case '>':
            case '}':
            case ']':
            case ')':
                // если встречаем какую-либо закрывающую скобку,
                // то проверяем соответствует ли она той, что в стеке закрывающих скобок:
                // если стек пустой или верхний элемент стека не соответствует текущей закрывающей
                // скобке, то функция возвращается false
                if (bracketsStack.empty() || bracketsStack.top() != ch) {
                    return false;
                }

                // а иначе удаляем верхний элемент из стека
                bracketsStack.pop();
        }
    }

    // если стек пуст, то возвращаем true, в противном случае false
    return bracketsStack.empty();
}

void test(const string& str, int testNumber = 0) {
    if (checkBracketsBalance(str)) {
        cout << "✅ Тест " << testNumber << ": Скобки в \"" << str << "\" расставлены корректно."
             << endl;
    } else {
        cout << "❌ Тест " << testNumber << ": Скобки в \"" << str << "\" расставлены некорректно."
             << endl;
    }
}

int main() {
    cout << "Программа проверки баланса скобок в строке." << endl;

    int type;

    cout << "Выберите действия:" << endl;
    cout << "1 - запустить тесты" << endl;
    cout << "2 - ввести строку для проверки на расстановку скобок" << endl;
    cout << "Ваш выбор: ";
    cin >> type;

    cin.ignore();

    if (type == 1) {
        cout << "\nЗапуск тестов...\n" << endl;

        const string test1 = "*&NC)(N%^BW%Q)<}_)_C)WMW*ERGrh";
        const string test2 = "UYU<N>K<{IuNuiS9}><>7((6!!!!23)){.}+!9n8c4t";
        const string test3 = "UYU<N>K<{IuNuiS9}><>7((6!!!!23)){.}]+!9n8c4t";
        const string test4 = "This ({is}[<{some}>]) string!";
        const string test5 = "";
        const string test6 = "No brackets here";

        test(test1, 1);
        test(test2, 2);
        test(test3, 3);
        test(test4, 4);
        test(test5, 5);
        test(test6, 6);

        cout << "\nТесты завершены." << endl;
    } else if (type == 2) {
        string input;
        cout << "Введите строку: ";
        getline(cin, input);

        test(input);
    } else {
        cout << "❌ Ошибка: выбрано некорректное действие." << endl;
    }

    return 0;
}
