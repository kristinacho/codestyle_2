/* Продолжение задания №5 Контейнер.
 * Элементами контейнеров являются целые числа. Для
 * заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
 * для вывода элементов использовать итератор (для вывода элементов в обратном порядке
 * использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
 * Обязательно наличие дружественного интерфейса. Ввод данных организовать
 * разными способами (с клавиатуры, рандом, из файла)
 *
 * Даны дек D и список L. Каждый исходный контейнер содержит не менее 5
 * элементов. Вставить перед пятым с конца элементом списка последние 5 элементов дека в
 * обратном порядке. Использовать один вызов функции-члена insert.
 */

#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <iterator>

struct DequeNode {
    int value;
    DequeNode* prev;
    DequeNode* next;
    explicit DequeNode(int val) : value(val), prev(nullptr), next(nullptr) {}
};

struct ListNode {
    int value;
    ListNode* prev;
    ListNode* next;
    explicit ListNode(int val) : value(val), prev(nullptr), next(nullptr) {}
};

class Deque {
public:
    class Iterator;
    class ReverseIterator;
    
    Deque();
    ~Deque();

    void pushBack(int value);
    void pushFront(int value);
    int popBack();
    int popFront();
    void clear();


    int back() const;
    int front() const;
    int at(int index) const;
    int size() const;
    bool empty() const;

    Iterator begin() const;
    Iterator end() const;
    ReverseIterator rbegin() const;
    ReverseIterator rend() const;

    friend std::ostream& operator<<(std::ostream& os, const Deque& deque);
    friend std::istream& operator>>(std::istream& is, Deque& deque);

private:
    DequeNode* frontPtr;
    DequeNode* backPtr;
    int currentSize;
};

class List {
public:
    class Iterator;
    class ReverseIterator;
    
    List();
    ~List();

    void pushBack(int value);
    void pushFront(int value);
    int popBack();
    int popFront();
    void clear();

    int back() const;
    int front() const;
    int size() const;
    bool empty() const;

    void insertBeforeFifthFromEnd(const Deque& deque);

    Iterator begin() const;
    Iterator end() const;
    ReverseIterator rbegin() const;
    ReverseIterator rend() const;


    friend std::ostream& operator<<(std::ostream& os, const List& list);
    friend std::istream& operator>>(std::istream& is, List& list);

private:
    ListNode* head;
    ListNode* tail;
    int currentSize;
};

class Deque::Iterator {
public:
    Iterator(DequeNode* node);
    int operator*() const;
    Iterator& operator++();
    bool operator!=(const Iterator& other) const;
    
private:
    DequeNode* current;
};

class Deque::ReverseIterator {
public:
    ReverseIterator(DequeNode* node);
    int operator*() const;
    ReverseIterator& operator++();
    bool operator!=(const ReverseIterator& other) const;
    
private:
    DequeNode* current;
};

class List::Iterator {
public:
    Iterator(ListNode* node);
    int operator*() const;
    Iterator& operator++();
    bool operator!=(const Iterator& other) const;
    
private:
    ListNode* current;
};

class List::ReverseIterator {
public:
    ReverseIterator(ListNode* node);
    int operator*() const;
    ReverseIterator& operator++();
    bool operator!=(const ReverseIterator& other) const;
    
private:
    ListNode* current;
};

#endif // CONTAINER_H
