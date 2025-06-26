/*
 * Продолжение задачи №2 Создание очереди
 *
 * Даны указатели P1 и P2 на начало и конец непустой очереди. Извлекать из очереди
 * элементы, пока значение начального элемента очереди не станет четным, и выводить значения
 * извлеченных элементов(если очередь не содержит элементов с четными значениями, то извлечь
 * все ее элементы).Вывести также новые адреса начала и конца очереди(для пустой очереди
 * дважды вывести nullptr).После извлечения элементов из очереди освобождать память, которую
 * они занимали
 *
 * Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - добавления/удаления/вывода элементов.
 * Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
 *
 * В заданиях данной подгруппы структура «очередь» (queue) моделируется цепочкой связанных
 * узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Началом
 * очереди («головой», head) считается первый элемент цепочки, концом («хвостом», tail) — ее
 * последний элемент. Для возможности быстрого добавления в конец очереди нового элемента
 * удобно хранить, помимо указателя на начало очереди, также и указатель на ее конец. В случае
 * пустой очереди указатели на ее начало и конец полагаются равными nullptr. Как и для стека,
 * значением элемента очереди считается значение его поля Data.
 */


#include "queue.h"
#include <iostream>

using namespace std;

struct Node {
    int data = 0;
    Node* next = nullptr;
    explicit Node(int val) : data(val) {}
};

struct Queue {
    Node* head = nullptr;
    Node* tail = nullptr;
};

QueuePtr createQueue() {
    Queue* q = new (nothrow) Queue();
    if (!q) {
        cout << "Ошибка: не удалось создать очередь" << endl;
    }
    return q;
}

void destroyQueue(QueuePtr q) {
    if (!q) return;
    
    int tempValue = 0;
    while (pop(q, tempValue)) {}
    delete q;
}

bool push(QueuePtr q, int value) {
    if (!q) {
        cout << "Ошибка: невалидный указатель на очередь" << endl;
        return false;
    }

    Node* newNode = new (nothrow) Node(value);
    if (!newNode) {
        cout << "Ошибка: не удалось выделить память для элемента" << endl;
        return false;
    }

    if (isEmpty(q)) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    return true;
}

bool pop(QueuePtr q, int& outValue) {
    if (!q || isEmpty(q)) {
        cout << "Ошибка: очередь пуста или невалидна" << endl;
        return false;
    }

    Node* temp = q->head;
    outValue = q->head->data;
    q->head = q->head->next;

    if (!q->head) {
        q->tail = nullptr;
    }

    delete temp;
    return true;
}

bool isEmpty(QueuePtr q) {
    return !q || !q->head;
}

void displayQueue(QueuePtr q) {
    if (!q) {
        cout << "Ошибка: очередь не существует" << endl;
        return;
    }

    Node* current = q->head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void processUntilEven(QueuePtr q) {
    if (!q) {
        cout << "Ошибка: очередь не существует" << endl;
        return;
    }

    int value = 0;
    while (!isEmpty(q) && (q->head->data % 2 != 0)) {
        if (!pop(q, value)) {
            cout << "Ошибка при извлечении элемента" << endl;
            return;
        }
        cout << value << " ";
    }
}

void getQueueAddresses(QueuePtr q) {
    if (!q) {
        cout << "Ошибка: очередь не существует" << endl;
        return;
    }

    cout << "Адрес начала: " << static_cast<void*>(q->head) << endl;
    cout << "Адрес конца: " << static_cast<void*>(q->tail) << endl;
}
