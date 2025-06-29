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
#include "stack.h"

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top_;
    top_ = newNode;
    count_++;
}

int Stack::pop() {
    if (isEmpty()) {
        std::cout << "Error: stack is empty" << std::endl;
        return -1;
    }

    Node* temp = top_;
    int value = temp->data;
    top_ = top_->next;
    delete temp;
    count_--;

    return value;
}

int Stack::top() const {
    if (isEmpty()) {
        std::cout << "Error: stack is empty" << std::endl;
        return -1;
    }
    return top_->data;
}

bool Stack::isEmpty() const {
    return top_ == nullptr;
}

int Stack::size() const {
    return count_;
}

std::ostream& operator<<(std::ostream& os, const Stack& stack) {
    Node* current = stack.top_;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}
