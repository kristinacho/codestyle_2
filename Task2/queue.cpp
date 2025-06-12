/*
 * ����������� ������ �2 �������� �������
 *
 * ���� ��������� P1 � P2 �� ������ � ����� �������� �������. ��������� �� �������
 * ��������, ���� �������� ���������� �������� ������� �� ������ ������, � �������� ��������
 * ����������� ���������(���� ������� �� �������� ��������� � ������� ����������, �� �������
 * ��� �� ��������).������� ����� ����� ������ ������ � ����� �������(��� ������ �������
 * ������ ������� nullptr).����� ���������� ��������� �� ������� ����������� ������, �������
 * ��� ��������
 *
 * ��� ������ ������������ ��������� ������ ���� ������������ ����������� ����� ������� - ����������/��������/������ ���������.
 * �� ���� ������� ����������� ������� �������������� ����������. ���� ������ � ����������.
 *
 * � �������� ������ ��������� ��������� ��������� (queue) ������������ �������� ���������
 * �����-������� ���� TNode. ���� Next ���������� �������� ������� ����� nullptr. �������
 * ������� (��������, head) ��������� ������ ������� �������, ������ (��������, tail) � ��
 * ��������� �������. ��� ����������� �������� ���������� � ����� ������� ������ ��������
 * ������ �������, ������ ��������� �� ������ �������, ����� � ��������� �� �� �����. � ������
 * ������ ������� ��������� �� �� ������ � ����� ���������� ������� nullptr. ��� � ��� �����,
 * ��������� �������� ������� ��������� �������� ��� ���� Data.
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
    }
    else {
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
    cout << "����� ������: " << head << endl;
    cout << "����� �����: " << tail << endl;
}