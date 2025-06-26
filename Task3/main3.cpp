/*
 * Продолжение задачи №3 создание списка
 * Все динамические структуры данных реализовывать через классы. Не использовать STL.  Для каждой динамической структуры должен быть предусмотрен
 * стандартный набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно
 * наличие дружественного интерфейса. Ввод данных с клавиатуры.
 *
 * Дан односвязный линейный список и указатель на голову списка P1. Необходимо
 * вставить значение M перед каждым вторым элементом списка, и вывести ссылку на последний
 * элемент полученного списка P2. При нечетном числе элементов исходного списка в конец
 * списка вставлять не надо.
*/

#include "list.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int getPositiveInteger(const string& prompt) {
    int value = 0;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите положительное число: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int getInteger(const string& prompt) {
    int value = 0;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите целое число: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    LinkedListPtr list = nullptr;
    int n = 0;
    int M = 0;
    void* lastNodeAddr = nullptr;
    int lastNodeValue = 0;
    int value = 0;
    bool success = true;

    list = createList();
    if (list == nullptr) {
        cout << "Ошибка: не удалось создать список. Программа завершена." << endl;
        return 1;
    }

    n = getPositiveInteger("Введите количество элементов в списке: ");

    cout << "Введите элементы списка:\n";
    for (i = 0; i < n; ++i) {
        value = getInteger("Элемент " + to_string(i + 1) + ": ");
        success = append(list, value);
        if (!success) {
            cout << "Ошибка при добавлении элемента. Программа завершена." << endl;
            destroyList(list);
            return 1;
        }
    }

    cout << "\nИсходный список: ";
    displayList(list);

    M = getInteger("\nВведите значение M для вставки: ");
    insertBeforeEverySecond(list, M);

    cout << "\nСписок после вставки: ";
    displayList(list);

    lastNodeAddr = getLastNodeAddress(list);
    lastNodeValue = getLastNodeValue(list);

    if (lastNodeAddr != nullptr) {
        cout << "\nАдрес последнего элемента: " << lastNodeAddr
             << "\nЗначение последнего элемента: " << lastNodeValue << endl;
    } else {
        cout << "\nСписок пуст." << endl;
    }

    destroyList(list);
    return 0;
}
