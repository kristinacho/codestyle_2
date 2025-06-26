/* Продолжение задания №5 Контейнер.
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

void FillContainer(DequePtr dq, int size) {
    int method_choice = 0; 
    int value = 0;         

    cout << "Выберите способ заполнения дека (1 - клавиатура, 2 - случайные числа, 3 - файл): ";
    while (!(cin >> method_choice) || method_choice < static_cast<int>(InputMethod::KEYBOARD) || method_choice > static_cast<int>(InputMethod::FILE_INPUT)) {
        cout << "Неверный метод ввода. Пожалуйста, введите 1, 2 или 3: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (static_cast<InputMethod>(method_choice)) {
        case InputMethod::KEYBOARD:
            cout << "Введите " << size << " элементов для дека:\n";
            for (int i = 0; i < size; i++) {
                while (!(cin >> value)) {
                    cout << "Неверный ввод. Пожалуйста, введите целое число: " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                PushBackDeque(dq, value);
            }
            break;

        case InputMethod::RANDOM:
            srand(time(0));
            for (int i = 0; i < size; i++) {
                PushBackDeque(dq, rand() % 100 - 50);
            }
            break;

        case InputMethod::FILE_INPUT: {
            ifstream file("input.txt");
            if (!file) {
                cout << "Не удалось открыть файл input.txt" << endl;
                return;
            }
            for (int i = 0; i < size && file >> value; ++i) {
                PushBackDeque(dq, value);
            }
            const int containerSize = GetDequeSize(dq);
            if (containerSize < size) {
                cout << "Недостаточно данных в файле. Заполнено только " << containerSize << " элементов." << endl;
            }
            file.close();
            break;
        }

        default:
            cout << "Неверный метод заполнения (внутренняя ошибка)." << endl;
            break;
    }
}

void FillContainer(ListPtr lst, int size) {
    int method_choice = 0; 
    int value = 0;         

    cout << "Выберите способ заполнения списка (1 - клавиатура, 2 - случайные числа, 3 - файл): ";
    while (!(cin >> method_choice) || method_choice < static_cast<int>(InputMethod::KEYBOARD) || method_choice > static_cast<int>(InputMethod::FILE_INPUT)) {
        cout << "Неверный метод ввода. Пожалуйста, введите 1, 2 или 3: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (static_cast<InputMethod>(method_choice)) {
        case InputMethod::KEYBOARD:
            cout << "Введите " << size << " элементов для списка:\n";
            for (int i = 0; i < size; i++) {
                while (!(cin >> value)) {
                    cout << "Неверный ввод. Пожалуйста, введите целое число: " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                PushBackList(lst, value);
            }
            break;

        case InputMethod::RANDOM:
            srand(time(0));
            for (int i = 0; i < size; ++i) {
                PushBackList(lst, rand() % 100 - 50);
            }
            break;

        case InputMethod::FILE_INPUT: {
            ifstream file("input.txt");
            if (!file) {
                cout << "Не удалось открыть файл input.txt" << endl;
                return;
            }
            for (int i = 0; i < size && file >> value; ++i) {
                PushBackList(lst, value);

            const int containerSize = GetListSize(lst);
            if (containerSize < size) {
                cout << "Недостаточно данных в файле. Заполнено только " << containerSize << " элементов." << endl;
            }
            file.close();
            break;
        }

        default:
            cout << "Неверный метод заполнения (внутренняя ошибка)." << endl; // Ошибки через cout.
            break;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    DequePtr dq = CreateDeque();
    ListPtr lst = CreateList();
    
    int dequeSize = 0;
    int listSize = 0;

    bool insert_success = false;

    cout << "Введите размер дека (>= 5): ";
    while (!(cin >> dequeSize) || dequeSize < 5) {
        cout << "Размер дека должен быть >= 5. Пожалуйста, введите корректное значение: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введите размер списка (>= 5): ";
    while (!(cin >> listSize) || listSize < 5) {
        cout << "Размер списка должен быть >= 5. Пожалуйста, введите корректное значение: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\nЗаполнение дека:\n";
    FillContainer(dq, dequeSize);

    cout << "\nЗаполнение списка:\n";
    FillContainer(lst, listSize);

    cout << "\nИсходный дек:\n";
    DisplayDeque(dq);

    cout << "Исходный список:\n";
    DisplayList(lst);

    insert_success = InsertBeforeFifthFromEnd(lst, dq);

    if (insert_success) {
        cout << "\nРезультат после вставки:\n";
        cout << "Дек (не изменился):\n";
        DisplayDeque(dq);

        cout << "Список (измененный):\n";
        DisplayList(lst);
    } else {
        cout << "\nОперация вставки не выполнена из-за предыдущих ошибок." << endl;
    }

    DestroyDeque(dq);
    DestroyList(lst);

    return 0;
}
