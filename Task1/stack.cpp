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

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

struct Stack {
    Node* topPtr;
    int count;
    
    Stack() : topPtr(nullptr), count(0) {}
    ~Stack() {
        while (topPtr != nullptr) {
            Node* temp = topPtr;
            topPtr = topPtr->next;
            delete temp;
        }
    }
};

StackPtr createStack() {
    return new Stack();
}

void destroyStack(StackPtr s) {
    delete s;
}

void push(StackPtr s, int value) {
    Node* newNode = new Node(value);
    newNode->next = s->topPtr;
    s->topPtr = newNode;
    s->count++;
}

void pop(StackPtr s) {
    if (isEmpty(s)) {
        throw runtime_error("Stack is empty");
    }

    Node* temp = s->topPtr;
    s->topPtr = s->topPtr->next;
    delete temp;
    s->count--;
}

int top(StackPtr s) {
    if (isEmpty(s)) {
        throw runtime_error("Stack is empty");
    }
    return s->topPtr->data;
}

bool isEmpty(StackPtr s) {
    return s->topPtr == nullptr;
}

void display(StackPtr s) {
    Node* current = s->topPtr;
    while (current != nullptr) {
        cout << current->data << "\n";
        current = current->next;
    }
}
