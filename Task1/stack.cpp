/*
 *  ����������� ������ �1 �������� �����
 *  ��� ��������� P1 �� ������� ��������� �����. ������� �� ����� ������ (�������)
 *  ������� � ������� ��� �������� D, � ����� ����� P2 ����� ������� �����. ���� �����
 *  ���������� �������� ���� �������� ������, �� �������� P2 = nullptr. ����� ����������
 *  �������� �� ����� ���������� ������, ���������� ���� ���������.
 *
 *  ��� ������ ������������ ��������� ������ ���� ������������ ����������� ����� ������� - ����������/��������/������ ���������.
 *  �� ���� ������� ����������� ������� �������������� ����������. ���� ������ � ����������.
 *
 *  � �������� ��������� ��������� ����� (stack) ������������ �������� ���������
 *  �����-������� ���� TNode. ���� Next ���������� �������� ������� ����� nullptr. ��������
 *  ����� (top) ��������� ������ ������� �������. ��� ������� � ����� ������������ ��������� ��
 *  ��� ������� (��� ������� ����� ������ ��������� ���������� ������ nullptr). ���������
 *  �������� ����� ��������� �������� ��� ���� Data
 */

#include "stack.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Stack::Stack() : topPtr(nullptr), count(0) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = topPtr;
    topPtr = newNode;
    ++count;
}

void Stack::pop() {
    if (isEmpty()) {
        throw runtime_error("Stack is empty");
    }

    Node* temp = topPtr;
    topPtr = topPtr->next;
    delete temp;
    --count;
}

int Stack::top() const {
    if (isEmpty()) {
        throw runtime_error("Stack is empty");
    }
    return topPtr->data;
}

bool Stack::isEmpty() const {
    return topPtr == nullptr;
}

void Stack::display() const {
    Node* current = topPtr;
    while (current != nullptr) {
        cout << current->data << "\n";
        current = current->next;
    }
}