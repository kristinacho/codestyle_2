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
#include <limits>

using namespace std;

struct Node {
    int value = 0;
    Node* prev = nullptr;
    Node* next = nullptr;
    
    explicit Node(int val) : value(val) {}
};

struct DoublyLinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;
};

DoublyLinkedListPtr CreateList() {
    DoublyLinkedList* list = new (nothrow) DoublyLinkedList();
    if (list == nullptr) {
        cout << "Ошибка: не удалось создать список" << endl;
    }
    return list;
}

void DestroyList(DoublyLinkedListPtr list) {
    if (list == nullptr) return;
    
    Node* current = list->head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete list;
}

bool Append(DoublyLinkedListPtr list, int value) {
    if (list == nullptr) {
        cout << "Ошибка: список не инициализирован" << endl;
        return false;
    }
    
    Node* newNode = new (nothrow) Node(value);
    if (newNode == nullptr) {
        cout << "Ошибка: не удалось создать новый узел" << endl;
        return false;
    }
    
    if (list->head == nullptr) {
        list->head = list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    return true;
}

void DisplayList(const DoublyLinkedListPtr list) {
    if (list == nullptr || list->head == nullptr) {
        cout << "Список пуст" << endl;
        return;
    }
    
    Node* current = list->head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void PrintBetweenMinMax(const DoublyLinkedListPtr list) {
    if (list == nullptr || list->head == nullptr || list->head == list->tail) {
        cout << "Недостаточно элементов в списке!" << endl;
        return;
    }

    Node* minNode = list->head;
    Node* maxNode = list->head;
    Node* current = list->head->next;

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

bool IsEmpty(const DoublyLinkedListPtr list) {
    return list == nullptr || list->head == nullptr;
}
