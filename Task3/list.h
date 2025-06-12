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

#ifndef LIST_H
#define LIST_H

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    LinkedList();
    ~LinkedList();

    void append(int value);
    void insertBeforeEverySecond(int M);
    void display() const;
    void* getLastNodeAddress() const;  // Изменили возвращаемый тип
    int getLastNodeValue() const;      // Добавили метод для значения
    void clear();
    bool isEmpty() const;
};

#endif // LIST_H