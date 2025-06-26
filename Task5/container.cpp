/*
 * Продолжение задания №5 Контейнер.
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

#include "container.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Ðåàëèçàöèÿ ìåòîäîâ Deque
Deque::Deque() : front(nullptr), back(nullptr), size(0) {}

Deque::~Deque() {
    clear();
}

void Deque::pushBack(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        front = back = newNode;
    }
    else {
        back->next = newNode;
        newNode->prev = back;
        back = newNode;
    }
    size++;
}

void Deque::pushFront(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        front = back = newNode;
    }
    else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    size++;
}

int Deque::popBack() {
    if (isEmpty()) throw runtime_error("Deque is empty");

    int value = back->value;
    Node* temp = back;

    if (front == back) {
        front = back = nullptr;
    }
    else {
        back = back->prev;
        back->next = nullptr;
    }

    delete temp;
    size--;
    return value;
}

int Deque::popFront() {
    if (isEmpty()) throw runtime_error("Deque is empty");

    int value = front->value;
    Node* temp = front;

    if (front == back) {
        front = back = nullptr;
    }
    else {
        front = front->next;
        front->prev = nullptr;
    }

    delete temp;
    size--;
    return value;
}

int Deque::getBack(int index) const {
    if (index < 0 || index >= size) throw out_of_range("Index out of range");

    Node* current = back;
    for (int i = 0; i < index; i++) {
        current = current->prev;
    }
    return current->value;
}

int Deque::getSize() const {
    return size;
}

bool Deque::isEmpty() const {
    return size == 0;
}

void Deque::clear() {
    while (!isEmpty()) {
        popBack();
    }
}

void Deque::display() const {
    Node* current = front;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void Deque::displayReverse() const {
    Node* current = back;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->prev;
    }
    cout << endl;
}

// Ðåàëèçàöèÿ ìåòîäîâ List
List::List() : head(nullptr), tail(nullptr), size(0) {}

List::~List() {
    clear();
}

void List::pushBack(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void List::pushFront(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

int List::popBack() {
    if (isEmpty()) throw runtime_error("List is empty");

    int value = tail->value;
    Node* temp = tail;

    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete temp;
    size--;
    return value;
}

int List::popFront() {
    if (isEmpty()) throw runtime_error("List is empty");

    int value = head->value;
    Node* temp = head;

    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
    size--;
    return value;
}

bool List::isEmpty() const {
    return size == 0;
}

int List::getSize() const {
    return size;
}

void List::clear() {
    while (!isEmpty()) {
        popBack();
    }
}

void List::display() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void List::displayReverse() const {
    Node* current = tail;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->prev;
    }
    cout << endl;
}

void List::insertBeforeFifthFromEnd(const Deque& deque) {
    if (size < 5) throw runtime_error("List size must be at least 5");
    if (deque.getSize() < 5) throw runtime_error("Deque size must be at least 5");

    // Íàõîäèì ïîçèöèþ äëÿ âñòàâêè (5-é ñ êîíöà)
    Node* current = tail;
    for (int i = 0; i < 4; i++) {
        current = current->prev;
    }

    // Âñòàâëÿåì ýëåìåíòû äåêà â îáðàòíîì ïîðÿäêå
    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node(deque.getBack(i));
        newNode->next = current;
        newNode->prev = current->prev;

        if (current->prev != nullptr) {
            current->prev->next = newNode;
        }
        else {
            head = newNode;
        }

        current->prev = newNode;
        size++;
    }
}
