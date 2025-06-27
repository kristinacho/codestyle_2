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

Queue::Queue() : head(nullptr), tail(nullptr) {}

Queue::~Queue() {
    int temp;
    while (pop(temp));
}

void Queue::push(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

bool Queue::pop(int& value) {
    if (isEmpty()) return false;

    Node* temp = head;
    value = head->data;
    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
    return true;
}

void Queue::display() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Queue::processUntilEven() {
    int value;
    while (!isEmpty() && (head->data % 2 != 0)) {
        pop(value);
        cout << value << " ";
    }
}

bool Queue::isEmpty() const {
    return head == nullptr;
}

void Queue::getHeadAndTailAddresses() const {
    cout << "Адрес начала: " << head << endl;
    cout << "Адрес конца: " << tail << endl;
}
