/*
 * Продолжение задачи №1 Создание стека
 * Дан указатель P1 на вершину непустого стека. Извлечь из стека первый (верхний)
 * элемент и вывести его значение D, а также адрес P2 новой вершины стека. Если после
 * извлечения элемента стек окажется пустым, то положить P2 = nullptr. После извлечения
 * элемента из стека освободить память, занимаемую этим элементом.
 *
 * Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - добавления/удаления/вывода элементов.
 * Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
 *
 * В заданиях подгруппы структура «стек» (stack) моделируется цепочкой связанных
 * узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Вершиной
 * стека (top) считается первый элемент цепочки. Для доступа к стеку используется указатель на
 * его вершину (для пустого стека данный указатель полагается равным nullptr). Значением
 * элемента стека считается значение его поля Data
 */


#include "stack.h"
#include <iostream>
#include <limits>  

using namespace std;

int getPositiveInteger(const char* prompt) {
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

int getInteger(const char* prompt) {
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

    Stack stack;

    int n_elements_to_create = 0;
    int current_element_value = 0;
    void* p1_address = nullptr;
    int d_value = 0;
    void* p2_address = nullptr;

    n_elements_to_create = getPositiveInteger("Введите количество элементов стека для создания: ");

    for (int i = 0; i < n_elements_to_create; ++i) {
        current_element_value = getInteger("Введите элемент стека: ");
        stack.push(current_element_value);
    }

    cout << "\n--- Содержимое стека ---\n";
    stack.display();

    if (!stack.isEmpty()) {
        cout << "\n--- Извлечение верхнего элемента ---\n";

        p1_address = static_cast<void*>(stack.getTopAddress());
        cout << "Адрес P1 текущей вершины стека: " << p1_address << "\n";

        d_value = stack.pop();
        cout << "Извлеченное значение D: " << d_value << "\n";

        p2_address = static_cast<void*>(stack.getTopAddress());
        if (stack.isEmpty()) {
            p2_address = nullptr;
        }
        cout << "Адрес P2 новой вершины стека: " << p2_address << "\n";

        if (stack.isEmpty()) {
            cout << "Стек теперь пуст.\n";
        } else {
            cout << "Новый верхний элемент: " << stack.top() << "\n";
    } else {
        cout << "\nСтек пуст, нет элементов для извлечения.\n";
    }

    return 0;
}
