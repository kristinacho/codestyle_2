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

int getPositiveInteger(const std::string& prompt) {
    int value = 0;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error! Enter positive number: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

int getInteger(const std::string& prompt) {
    int value = 0;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error! Enter integer: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    Stack stack;
    int n = 0;
    int num = 0;
    Node* P1 = nullptr;
    int D = 0;
    Node* P2 = nullptr;

    n = getPositiveInteger("Enter stack size: ");

    for (int i = 0; i < n; ++i) {
        num = getInteger("Enter element: ");
        stack.push(num);
    }

    std::cout << "Stack content: ";
    std::cout << stack << std::endl;

    if (!stack.isEmpty()) {
        P1 = stack.getTopAddress();
        std::cout << "P1 address: " << P1 << std::endl;

        D = stack.pop();
        P2 = stack.getTopAddress();

        std::cout << "D value: " << D << std::endl;
        std::cout << "P2 address: " << P2 << std::endl;

        if (stack.isEmpty()) {
            std::cout << "Stack is now empty" << std::endl;
        } else {
            std::cout << "New top: " << stack.top() << std::endl;
        }
    } else {
        std::cout << "Stack is empty" << std::endl;
    }

    return 0;
}
