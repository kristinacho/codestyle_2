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


#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
    explicit Node(int value) : data(value), next(nullptr) {}
};

class Stack {
public:
    Stack() : topPtr(nullptr), count(0) {}
    ~Stack();

    void push(int value);
    void pop();
    int top() const;
    bool isEmpty() const;
    int size() const;

    friend ostream& operator<<(ostream& os, const Stack& stack);
    friend istream& operator>>(istream& is, Stack& stack);

    void display() const;

private:
    Node* topPtr;
    int count;
};

#endif // STACK_H
