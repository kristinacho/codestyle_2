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


#include "list.h"
#include <iostream>
#include <limits>

using namespace std;

struct Node {
    int data = 0;
    Node* next = nullptr;
    
    explicit Node(int value) : data(value) {}
};

struct LinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;
};

LinkedListPtr createList() {
    LinkedList* list = new (nothrow) LinkedList();
    if (list == nullptr) {
        cout << "Ошибка: не удалось выделить память для списка" << endl;
        return nullptr;
    }
    return list;
}

void destroyList(LinkedListPtr list) {
    if (list == nullptr) {
        cout << "Предупреждение: попытка удалить nullptr список" << endl;
        return;
    }
    
    Node* current = list->head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    delete list;
}

bool append(LinkedListPtr list, int value) {
    if (list == nullptr) {
        cout << "Ошибка: список не инициализирован" << endl;
        return false;
    }
    
    Node* newNode = new (nothrow) Node(value);
    if (newNode == nullptr) {
        cout << "Ошибка: не удалось выделить память для нового узла" << endl;
        return false;
    }
    
    if (list->head == nullptr) {
        list->head = list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    return true;
}

void insertBeforeEverySecond(LinkedListPtr list, int M) {
    if (list == nullptr) {
        cout << "Ошибка: список не инициализирован" << endl;
        return;
    }
    if (list->head == nullptr || list->head->next == nullptr) {
        return;
    }

    Node* current = list->head;
    int position = 1;

    while (current != nullptr && current->next != nullptr) {
        if (position % 2 == 1) {
            Node* newNode = new (nothrow) Node(M);
            if (newNode == nullptr) {
                cout << "Ошибка: не удалось вставить элемент" << endl;
                return;
            }
            
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;

            if (current == nullptr) {
                list->tail = newNode;
            }
        } else {
            current = current->next;
        }
        position++;
    }
}

void displayList(LinkedListPtr list) {
    if (list == nullptr) {
        cout << "Список не инициализирован" << endl;
        return;
    }
    
    Node* current = list->head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void* getLastNodeAddress(LinkedListPtr list) {
    if (list == nullptr || list->tail == nullptr) {
        cout << "Список пуст или не инициализирован" << endl;
        return nullptr;
    }
    return static_cast<void*>(list->tail);
}

int getLastNodeValue(LinkedListPtr list) {
    if (list == nullptr || list->tail == nullptr) {
        cout << "Список пуст или не инициализирован" << endl;
        return -1;
    }
    return list->tail->data;
}

bool isEmpty(LinkedListPtr list) {
    if (list == nullptr) {
        cout << "Список не инициализирован" << endl;
        return true;
    }
    return list->head == nullptr;
}
