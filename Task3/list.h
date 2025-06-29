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

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <ostream>

struct ListNode {
    int data;
    ListNode* next;
    explicit ListNode(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void append(int value);
    void insertBeforeEverySecond(int M);
    void clear();
    bool isEmpty() const;

    void* getLastNodeAddress() const;
    int getLastNodeValue() const;

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);
    friend std::istream& operator>>(std::istream& is, LinkedList& list);

private:
    ListNode* head_;
    ListNode* tail_;
};

#endif // LIST_H
