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

#include "container.h"
#include <iostream> 

using namespace std;

class Deque {
  private:
    struct Node {
        int value;
        Node* prev;
        Node* next;
        Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    };

    Node* front;
    Node* back;
    int size; 

  public:
    Deque() : front(nullptr), back(nullptr), size(0) {}
    ~Deque() {
        clear();
    }

    void pushBack(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = back = newNode;
        } else {
            back->next = newNode;
            newNode->prev = back;
            back = newNode;
        }
        size++;
    }

    void pushFront(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = back = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    int popBack() {
        if (isEmpty()) {
            cout << "Ошибка: Дек пуст, невозможно удалить элемент из конца." << endl;
            return 0;
        }
        int value = back->value;
        Node* temp = back;
        if (front == back) {
            front = back = nullptr;
        } else {
            back = back->prev;
            back->next = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    int popFront() {
        if (isEmpty()) {
            cout << "Ошибка: Дек пуст, невозможно удалить элемент из начала." << endl;
            return 0;
        }
        int value = front->value;
        Node* temp = front;
        if (front == back) {
            front = back = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    int getBack(int index) const {
        if (index < 0 || index >= size) {
            cout << "Ошибка: Индекс " << index << " вне допустимого диапазона для дека (размер " << size << ")." << endl;
            return 0;
        }
        Node* current = back;
        for (int i = 0; i < index; i++) {
            current = current->prev;
        }
        return current->value;
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void clear() {
        while (!isEmpty()) {
            popFront();
        }
    }

void display() const {
        Node* current = front;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

void displayReverse() const {
        Node* current = back;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->prev;
        }
        cout << endl;
    }
};


DequePtr CreateDeque() {
    return new Deque();
}

void DestroyDeque(DequePtr dq) {
    if (dq) {
        delete dq;
    }
}

void PushBackDeque(DequePtr dq, int value) {
    if (dq) {
        dq->pushBack(value);
    } else {
        cout << "Ошибка: Указатель на дек недействителен для pushBack." << endl;
    }
}

void PushFrontDeque(DequePtr dq, int value) {
    if (dq) {
        dq->pushFront(value);
    } else {
        cout << "Ошибка: Указатель на дек недействителен для pushFront." << endl;
    }
}

int PopBackDeque(DequePtr dq) {
    if (!dq) {
        cout << "Ошибка: Указатель на дек недействителен для popBack." << endl;
        return 0;
    }
    return dq->popBack();
}

int PopFrontDeque(DequePtr dq) {
    if (!dq) {
        cout << "Ошибка: Указатель на дек недействителен для popFront." << endl;
        return 0;
    }
    return dq->popFront();
}

int GetBackDeque(const DequePtr dq, int index) {
    if (!dq) {
        cout << "Ошибка: Указатель на дек недействителен для GetBackDeque." << endl;
        return 0;
    }
    return dq->getBack(index);
}

int GetDequeSize(const DequePtr dq) {
    if (!dq) {
        cout << "Предупреждение: Указатель на дек недействителен для GetDequeSize, возвращен размер 0." << endl;
        return 0;
    }
    return dq->getSize();
}

bool IsDequeEmpty(const DequePtr dq) {
    if (!dq) {
        cout << "Предупреждение: Указатель на дек недействителен для IsDequeEmpty, считается пустым." << endl;
        return true;
    }
    return dq->isEmpty();
}

void ClearDeque(DequePtr dq) {
    if (dq) {
        dq->clear();
    } else {
        cout << "Ошибка: Указатель на дек недействителен для ClearDeque." << endl;
    }
}

void DisplayDeque(const DequePtr dq) {
    if (dq) {
        dq->display();
    } else {
        cout << "Ошибка: Указатель на дек недействителен для DisplayDeque." << endl;
    }
}

void DisplayDequeReverse(const DequePtr dq) {
    if (dq) {
        dq->displayReverse();
    } else {
        cout << "Ошибка: Указатель на дек недействителен для DisplayDequeReverse." << endl;
    }
}


class List {
  private:
    struct Node {
        int value;
        Node* prev;
        Node* next;
        Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

  public:
    List() : head(nullptr), tail(nullptr), size(0) {}
    ~List() {
        clear();
    }

void pushBack(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void pushFront(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    int popBack() {
        if (isEmpty()) {
            cout << "Ошибка: Список пуст, невозможно удалить элемент из конца." << endl;
            return 0;
        }
        int value = tail->value;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    int popFront() {
        if (isEmpty()) {
            cout << "Ошибка: Список пуст, невозможно удалить элемент из начала." << endl;
            return 0;
        }
        int value = head->value;
        Node* temp = head;
        if (head == tail) { 
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
        return value;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            popFront();
        }
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void displayReverse() const {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void insertNodeBefore(Node* newNode, Node* targetNode) {
        if (!targetNode) {
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        } else {
            newNode->next = targetNode;
            newNode->prev = targetNode->prev;

            if (targetNode->prev != nullptr) {
                targetNode->prev->next = newNode;
            } else {
                head = newNode; // Вставка в начало списка.
            }
            targetNode->prev = newNode;
        }
        size++;
    }
};


ListPtr CreateList() {
    return new List();
}

void DestroyList(ListPtr lst) {
    if (lst) {
        delete lst;
    }
}

void PushBackList(ListPtr lst, int value) {
    if (lst) {
        lst->pushBack(value);
    } else {
        cout << "Ошибка: Указатель на список недействителен для PushBackList." << endl;
    }
}

void PushFrontList(ListPtr lst, int value) {
    if (lst) {
        lst->pushFront(value);
    } else {
        cout << "Ошибка: Указатель на список недействителен для PushFrontList." << endl;
    }
}

int PopBackList(ListPtr lst) {
    if (!lst) {
        cout << "Ошибка: Указатель на список недействителен для PopBackList." << endl;
        return 0;
    }
    return lst->popBack();
}

int PopFrontList(ListPtr lst) {
    if (!lst) {
        cout << "Ошибка: Указатель на список недействителен для PopFrontList." << endl;
        return 0;
    }
    return lst->popFront();
}

bool IsListEmpty(const ListPtr lst) {
    if (!lst) {
        cout << "Предупреждение: Указатель на список недействителен для IsListEmpty, считается пустым." << endl;
        return true;
    }
    return lst->isEmpty();
}

int GetListSize(const ListPtr lst) {
    if (!lst) {
        cout << "Предупреждение: Указатель на список недействителен для GetListSize, возвращен размер 0." << endl;
        return 0;
    }
    return lst->getSize();
}

void ClearList(ListPtr lst) {
    if (lst) {
        lst->clear();
    } else {
        cout << "Ошибка: Указатель на список недействителен для ClearList." << endl;
    }
}

void DisplayList(const ListPtr lst) {
    if (lst) {
        lst->display();
    } else {
        cout << "Ошибка: Указатель на список недействителен для DisplayList." << endl;
    }
}

void DisplayListReverse(const ListPtr lst) {
    if (lst) {
        lst->displayReverse();
    } else {
        cout << "Ошибка: Указатель на список недействителен для DisplayListReverse." << endl;
    }
}

bool InsertBeforeFifthFromEnd(ListPtr lst, const DequePtr dq) {
    if (!lst) {
        cout << "Ошибка: Указатель на список недействителен для InsertBeforeFifthFromEnd." << endl;
        return false;
    }
    if (!dq) {
        cout << "Ошибка: Указатель на дек недействителен для InsertBeforeFifthFromEnd." << endl;
        return false;
    }

    if (lst->getSize() < 5) {
        cout << "Ошибка: Размер списка (" << lst->getSize() << ") должен быть не менее 5 для выполнения вставки." << endl;
        return false;
    }
    if (dq->getSize() < 5) {
        cout << "Ошибка: Размер дека (" << dq->getSize() << ") должен быть не менее 5 для предоставления элементов." << endl;
        return false;
    }

    List::Node* insertPos = lst->tail;
    for (int i = 0; i < 4; i++) {
        insertPos = insertPos->prev;
    }

    for (int i = 0; i < 5; i++) {
        List::Node* newNode = new List::Node(dq->getBack(i));
        lst->insertNodeBefore(newNode, insertPos);
    }
    return true;
}
