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

#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <iostream>
#include <ostream>

struct DoublyNode {
    int value = 0;
    DoublyNode* prev = nullptr;
    DoublyNode* next = nullptr;
    explicit DoublyNode(int val) : value(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void append(int value);
    void clear();
    bool isEmpty() const;

    void printBetweenMinMax() const;

    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& list);
    friend std::istream& operator>>(std::istream& is, DoublyLinkedList& list);

private:
    DoublyNode* head_ = nullptr;
    DoublyNode* tail_ = nullptr;
};

#endif // DOUBLE_LIST_H
