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

Queue::Queue() : head_(nullptr), tail_(nullptr) {}

Queue::~Queue() {
    int temp;
    while (dequeue(temp));
}

void Queue::enqueue(int value) {
    QueueNode* newNode = new QueueNode(value);
    if (isEmpty()) {
        head_ = tail_ = newNode;
    } else {
        tail_->next = newNode;
        tail_ = newNode;
    }
}

bool Queue::dequeue(int& value) {
    if (isEmpty()) return false;

    QueueNode* temp = head_;
    value = head_->data;
    head_ = head_->next;

    if (head_ == nullptr) {
        tail_ = nullptr;
    }

    delete temp;
    return true;
}

void Queue::processUntilEven() {
    int value;
    while (!isEmpty() && (head_->data % 2 != 0)) {
        dequeue(value);
        cout << value << " ";
    }
}

bool Queue::isEmpty() const {
    return head_ == nullptr;
}

void Queue::getEndpoints() const {
    cout << "Head address: " << head_ << endl;
    cout << "Tail address: " << tail_ << endl;
}

std::ostream& operator<<(std::ostream& os, const Queue& queue) {
    QueueNode* current = queue.head_;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Queue& queue) {
    int value;
    is >> value;
    queue.enqueue(value);
    return is;
}
