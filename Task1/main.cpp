/*
 *  Продолжение задачи №1 Создание стека
 *  Дан указатель P1 на вершину непустого стека. Извлечь из стека первый (верхний)
 *  элемент и вывести его значение D, а также адрес P2 новой вершины стека. Если после
 *  извлечения элемента стек окажется пустым, то положить P2 = nullptr. После извлечения
 *  элемента из стека освободить память, занимаемую этим элементом.
 *
 *  Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - добавления/удаления/вывода элементов.
 *  Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
 *
 *  В заданиях подгруппы структура «стек» (stack) моделируется цепочкой связанных
 *  узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Вершиной
 *  стека (top) считается первый элемент цепочки. Для доступа к стеку используется указатель на
 *  его вершину (для пустого стека данный указатель полагается равным nullptr). Значением
 *  элемента стека считается значение его поля Data
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
        }
        else {
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
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    StackPtr stack = createStack();
    try {
        int n = getPositiveInteger("Введите количество элементов стека: ");

        for (int i = 0; i < n; ++i) {
            int num = getInteger("Введите элемент стека: ");
            push(stack, num);
        }

        cout << "Содержимое стека:\n";
        display(stack);

        if (!isEmpty(stack)) {
            cout << "Первый элемент стека: " << top(stack) << "\n";
            cout << "Адрес вершины стека: " << stack->topPtr << "\n";
            
            pop(stack);
            
            if (isEmpty(stack)) {
                cout << "Стек теперь пуст (P2 = nullptr)\n";
            }
            else {
                cout << "Новый верхний элемент: " << top(stack) << "\n";
                cout << "Адрес новой вершины стека (P2): " << stack->topPtr << "\n";
            }
        }
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << "\n";
        destroyStack(stack);
        return 1;
    }

    destroyStack(stack);
    return 0;
}
