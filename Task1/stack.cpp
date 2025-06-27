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
#include <stdexcept>

using namespace std;

Stack::Stack() : topPtr(nullptr), count(0) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = topPtr;
    topPtr = newNode;
    ++count;
}

void Stack::pop() {
    if (isEmpty()) {
        throw runtime_error("Stack is empty");
    }

    Node* temp = topPtr;
    topPtr = topPtr->next;
    delete temp;
    --count;
}

int Stack::top() const {
    if (isEmpty()) {
        throw runtime_error("Stack is empty");
    }
    return topPtr->data;
}

bool Stack::isEmpty() const {
    return topPtr == nullptr;
}

void Stack::display() const {
    Node* current = topPtr;
    while (current != nullptr) {
        cout << current->data << "\n";
        current = current->next;
    }
}
