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
    LinkedList list = nullptr;

    try {
        int n = getPositiveInteger("Введите количество элементов в списке: ");

        cout << "Введите элементы списка:\n";
        for (int i = 0; i < n; ++i) {
            int value = getInteger("Элемент " + to_string(i+1) + ": ");
            list.append(value);
        }

        cout << "\nИсходный список: ";
        list.display();

        int M = getInteger("\nВведите значение M для вставки: ");
        list.insertBeforeEverySecond(M);

        cout << "\nСписок после вставки: ";
        list.display();

        void* lastNodeAddr = list.getLastNodeAddress();
        int lastNodeValue = list.getLastNodeValue();

        if (lastNodeAddr != nullptr) {
            cout << "\nАдрес последнего элемента: " << lastNodeAddr
                 << "\nЗначение последнего элемента: " << lastNodeValue << endl;
        } else {
            cout << "\nСписок пуст." << endl;
        }

    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}
