/*
 * ����������� ������ �3 �������� ������
 * ��� ������������ ��������� ������ ������������� ����� ������. �� ������������ STL.  ��� ������ ������������ ��������� ������ ���� ������������
 * ����������� ����� ������� - ����������/��������/������ ���������. �� ���� ������� �����������
 * ������� �������������� ����������. ���� ������ � ����������.
 *
 * ��� ����������� �������� ������ � ��������� �� ������ ������ P1. ����������
 * �������� �������� M ����� ������ ������ ��������� ������, � ������� ������ �� ���������
 * ������� ����������� ������ P2. ��� �������� ����� ��������� ��������� ������ � �����
 * ������ ��������� �� ����.
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
    void* getLastNodeAddress() const;  // �������� ������������ ���
    int getLastNodeValue() const;      // �������� ����� ��� ��������
    void clear();
    bool isEmpty() const;
};

#endif // LIST_H