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

using namespace std;

struct Node {
    int data = 0;
    Node* next = nullptr;
    explicit Node(int val) : data(val) {}
};

struct Stack {
    Node* topPtr = nullptr;
    int count = 0;
};

StackPtr createStack() {
    Stack* s = new (nothrow) Stack();
    if (!s) {
        cout << "Ошибка: не удалось создать стек" << endl;
    }
    return s;
}

void destroyStack(StackPtr s) {
    if (!s) return;
    
    while (pop(s)) {}
    delete s;
}

bool push(StackPtr s, int value) {
    if (!s) {
        cout << "Ошибка: невалидный указатель на стек" << endl;
        return false;
    }

    Node* newNode = new (nothrow) Node(value);
    if (!newNode) {
        cout << "Ошибка: не удалось выделить память для элемента" << endl;
        return false;
    }

    newNode->next = s->topPtr;
    s->topPtr = newNode;
    s->count++;
    return true;
}

bool pop(StackPtr s) {
    if (!s || isEmpty(s)) {
        cout << "Ошибка: стек пуст или невалиден" << endl;
        return false;
    }

    Node* temp = s->topPtr;
    s->topPtr = s->topPtr->next;
    delete temp;
    s->count--;
    return true;
}

bool top(StackPtr s, int& outValue) {
    if (!s || isEmpty(s)) {
        cout << "Ошибка: стек пуст или невалиден" << endl;
        return false;
    }

    outValue = s->topPtr->data;
    return true;
}

bool isEmpty(StackPtr s) {
    return !s || !s->topPtr;
}

void display(StackPtr s) {
    if (!s) {
        cout << "Ошибка: стек не существует" << endl;
        return;
    }

    Node* current = s->topPtr;
    while (current) {
        cout << current->data << "\n";
        current = current->next;
    }
}
