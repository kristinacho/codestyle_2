/*
 * Продолжение задания №5 Контейнер.
 * Элементами контейнеров являются целые числа. Для
 * заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
 * для вывода элементов использовать итератор (для вывода элементов в обратном порядке
 * использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
 * Обязательно наличие дружественного интерфейса. Ввод данных организовать
 * разными способами (с клавиатуры, рандом, из файла)
 *
 * Даны дек D и список L. Каждый исходный контейнер содержит не менее 5
 * элементов. Вставить перед пятым с конца элементом списка последние 5 элементов дека в
 * обратном порядке. Использовать один вызов функции-члена insert.
*/


#include "container.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

enum class InputMethod { KEYBOARD = 1, RANDOM, FILE_INPUT };

void FillContainer(Deque& container, int size) {
    int method = 2, value = 3;
    cout << "Выберите способ заполнения (1 - клавиатура, 2 - случайные числа, 3 - файл): ";
    while (!(cin >> method) || method < static_cast<int>(InputMethod::KEYBOARD) || method > static_cast<int>(InputMethod::FILE_INPUT)) {
        cerr << "Неверный метод ввода. Пожалуйста, введите 1, 2 или 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (static_cast<InputMethod>(method)) {
        case InputMethod::KEYBOARD:
            cout << "Введите " << size << " элементов:\n";
            for (int i = 0; i < size; i++) {
                while (!(cin >> value)) {
                    cerr << "Неверный ввод. Пожалуйста, введите целое число: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                container.pushBack(value);
            }
            break;

        case InputMethod::RANDOM:
            srand(time(0));
            for (int i = 0; i < size; i++) {
                container.pushBack(rand() % 100 - 50);
            }
            break;

        case InputMethod::FILE_INPUT: {
            ifstream file("input.txt");
            if (!file) {
                cerr << "Не удалось открыть файл\n";
                return;
            }
            for (int i = 0; i < size && file >> value; ++i) {
                container.pushBack(value);
            }
            const int containerSize = container.getSize();
            if (containerSize < size) {
                cerr << "Недостаточно данных в файле. Заполнено только " << containerSize<< " элементов.\n";
            }
            file.close();
            break;
        }

        default:
            cerr << "Неверный метод ввода\n";
            break;
    }
}

void FillContainer(List& container, int size) {
    int method, value;
    cout << "Выберите способ заполнения (1 - клавиатура, 2 - случайные числа, 3 - файл): ";
    while (!(cin >> method) || method < static_cast<int>(InputMethod::KEYBOARD) || method > static_cast<int>(InputMethod::FILE_INPUT)) {
        cerr << "Неверный метод ввода. Пожалуйста, введите 1, 2 или 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (static_cast<InputMethod>(method)) {
        case InputMethod::KEYBOARD:
            cout << "Введите " << size << " элементов:\n";
            for (int i = 0; i < size; i++) {
                while (!(cin >> value)) {
                    cerr << "Неверный ввод. Пожалуйста, введите целое число: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                container.pushBack(value);
            }
            break;

        case InputMethod::RANDOM:
            srand(time(0));
            for (int i = 0; i < size; ++i) {
                container.pushBack(rand() % 100 - 50);
            }
            break;

        case InputMethod::FILE_INPUT: {
            ifstream file("input.txt");
            if (!file) {
                cerr << "Не удалось открыть файл\n";
                return;
            }
            for (int i = 0; i < size && file >> value; ++i) {
                container.pushBack(value);
            }

            const int containerSize = container.getSize();
            if (containerSize < size) {
                cerr << "Недостаточно данных в файле. Заполнено только " << containerSize << " элементов.\n";
            }
            file.close();
            break;
        }

        default:
            cerr << "Неверный метод ввода\n";
            break;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        int dequeSize = 1, listSize = 1;

        cout << "Введите размер дека (>= 5): ";
        while (!(cin >> dequeSize) || dequeSize < 5) {
            cerr << "Размер дека должен быть >= 5. Пожалуйста, введите корректное значение: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Введите размер списка (>= 5): ";
        while (!(cin >> listSize) || listSize < 5) {
            cerr << "Размер списка должен быть >= 5. Пожалуйста, введите корректное значение: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        Deque dq = nullptr;
        List lst = nullptr;

        cout << "\nЗаполнение дека:\n";
        FillContainer(dq, dequeSize);

        cout << "\nЗаполнение списка:\n";
        FillContainer(lst, listSize);

        cout << "\nИсходный дек:\n";
        dq.display();

        cout << "Исходный список:\n";
        lst.display();

        lst.insertBeforeFifthFromEnd(dq);

        cout << "\nРезультат после вставки:\n";
        cout << "Дек (не изменился):\n";
        dq.display();

        cout << "Список (измененный):\n";
        lst.display();

    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}
