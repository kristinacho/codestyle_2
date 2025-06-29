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

#include "list.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList() : head_(nullptr), tail_(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::append(int value) {
    DoublyNode* newNode = new DoublyNode(value);
    if (isEmpty()) {
        head_ = tail_ = newNode;
    } else {
        tail_->next = newNode;
        newNode->prev = tail_;
        tail_ = newNode;
    }
}

void DoublyLinkedList::printBetweenMinMax() const {
    if (isEmpty() || head_ == tail_) {
        cout << "Недостаточно элементов в списке!" << endl;
        return;
    }

    DoublyNode* minNode = head_;
    DoublyNode* maxNode = head_;
    DoublyNode* current = head_->next;

    while (current != nullptr) {
        if (current->value < minNode->value) minNode = current;
        if (current->value > maxNode->value) maxNode = current;
        current = current->next;
    }

    if (minNode == maxNode) {
        cout << "Все элементы одинаковые!" << endl;
        return;
    }

    DoublyNode* start = minNode;
    DoublyNode* end = maxNode;

    if (minNode->value > maxNode->value ||
        (minNode->value == maxNode->value && minNode->next == maxNode)) {
        start = maxNode;
        end = minNode;
    }

    cout << "Элементы между " << start->value << " и " << end->value << ": ";

    bool elementsFound = false;
    current = start->next;
    while (current != nullptr && current != end) {
        cout << current->value << " ";
        elementsFound = true;
        current = current->next;
    }

    if (!elementsFound) {
        cout << "отсутствуют";
    }
    cout << endl;
}

void DoublyLinkedList::clear() {
    while (head_ != nullptr) {
        DoublyNode* temp = head_;
        head_ = head_->next;
        delete temp;
    }
    tail_ = nullptr;
}

bool DoublyLinkedList::isEmpty() const {
    return head_ == nullptr;
}

std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& list) {
    DoublyNode* current = list.head_;
    while (current != nullptr) {
        os << current->value << " ";
        current = current->next;
    }
    return os;
}

std::istream& operator>>(std::istream& is, DoublyLinkedList& list) {
    int value = 0;
    is >> value;
    list.append(value);
    return is;
}
