/*
 * Продолжение задания №4 двусвязный список
 * Дан двусвязный линейный список и указатель первый элемент этого
 * списка. Все элементы списка хранят различные между собой значения. Необходимо
 * вывести значения элементов списка, которые находятся между наименьшим и
 * наибольшим элементами списка, в том порядке, в каком они находятся в исходном
 * списке. Использовать процедуры.
 *
 * Все динамические структуры данных реализовывать через классы. Не использовать STL.  Для каждой динамической структуры должен быть предусмотрен
 * стандартный набор методов - добавления/удаления/вывода элементов.
 * Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
 */

#include "double_list.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int GetPositiveInteger(const string& prompt) {
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

int GetInteger(const string& prompt) {
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
    setlocale(LC_ALL, "Russian");
    
    DoublyLinkedListPtr list = nullptr;
    int n = 0;
    int value = 0;
    bool success = true;

    list = CreateList();
    if (list == nullptr) {
        cout << "Ошибка при создании списка" << endl;
        return 1;
    }

    n = GetPositiveInteger("Введите количество элементов в списке: ");
    
    cout << "Введите элементы списка:\n";
    for (int i = 0; i < n; ++i) {
        value = GetInteger("Элемент " + to_string(i + 1) + ": ");
        success = Append(list, value);
        if (!success) {
            cout << "Ошибка при добавлении элемента" << endl;
            DestroyList(list);
            return 1;
        }
    }

    cout << "\nСодержимое списка: ";
    DisplayList(list);

    cout << "\nРезультат:\n";
    PrintBetweenMinMax(list);

    DestroyList(list);
    return 0;
}
