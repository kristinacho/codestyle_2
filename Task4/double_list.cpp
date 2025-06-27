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

#include "double_list.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoublyLinkedList::display() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void DoublyLinkedList::printBetweenMinMax() const {
    if (isEmpty() || head == tail) {
        cout << "Недостаточно элементов в списке!" << endl;
        return;
    }

    Node* minNode = head;
    Node* maxNode = head;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->value < minNode->value) minNode = current;
        if (current->value > maxNode->value) maxNode = current;
        current = current->next;
    }

    if (minNode == maxNode) {
        cout << "Все элементы одинаковые!" << endl;
        return;
    }

    Node* start = minNode;
    Node* end = maxNode;

    // Определяем порядок следования min и max
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
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

bool DoublyLinkedList::isEmpty() const {
    return head == nullptr;
}
