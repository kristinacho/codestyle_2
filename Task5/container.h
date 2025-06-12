/*
 * ����������� ������� �5 ���������.
 * ���������� ����������� �������� ����� �����. ���
 * ���������� ���������� ������������ �������� � ����������� ���������������� ����������,
 * ��� ������ ��������� ������������ �������� (��� ������ ��������� � �������� �������
 * ������������ �������� ���������, ������������ ���������-������� rbegin � rend)
 * ����������� ������� �������������� ����������. ���� ������ ������������
 * ������� ��������� (� ����������, ������, �� �����)
 *
 * ���� ��� D � ������ L. ������ �������� ��������� �������� �� ����� 5
 * ���������. �������� ����� ����� � ����� ��������� ������ ��������� 5 ��������� ���� �
 * �������� �������. ������������ ���� ����� �������-����� insert.
*/

#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

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
    Deque();
    ~Deque();

    void pushBack(int value);
    void pushFront(int value);
    int popBack();
    int popFront();
    int getBack(int index) const;
    int getSize() const;
    bool isEmpty() const;
    void clear();
    void display() const;
    void displayReverse() const;
};

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

public:
    List();
    ~List();

    void pushBack(int value);
    void pushFront(int value);
    int popBack();
    int popFront();
    bool isEmpty() const;
    int getSize() const;
    void clear();
    void display() const;
    void displayReverse() const;
    void insertBeforeFifthFromEnd(const Deque& deque);

    int size;
};

#endif // CONTAINER_H