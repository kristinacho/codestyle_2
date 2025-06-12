/*
��� ������������ ��������� ������ ������������� ����� ������. �� ������������ STL.  ��� ������ ������������ ��������� ������ ���� ������������
����������� ����� ������� - ����������/��������/������ ���������. �� ���� ������� �����������
������� �������������� ����������. ���� ������ � ����������.

 ��� ����������� �������� ������ � ��������� �� ������ ������ P1. ����������
�������� �������� M ����� ������ ������ ��������� ������, � ������� ������ �� ���������
������� ����������� ������ P2. ��� �������� ����� ��������� ��������� ������ � �����
������ ��������� �� ����.
*/

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:

    LinkedList() : head(nullptr) {}

    void add(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // ����� ��� ������� �������� M ����� ������ ������ ���������
    void insertBeforeEverySecond(int M) {
        Node* current = head;
        int count = 1;                  // ������� ��� ������������ �������

        while (current != nullptr && current->next != nullptr) {
            if (count % 2 == 1) {       // ���� ������� ������� � ������ � ����
                Node* newNode = new Node(M); // ������� ����� ���� �� ��������� M
                newNode->next = current->next; // ����� ���� ��������� �� ��������� �������
                current->next = newNode; // ������� ���� ��������� �� ����� ����
                current = newNode->next; // ��������� � ���������� ��������
            }
            else {
                current = current->next;
            }
            count++;
        }
    }


    void print() {
        Node* current = head;           // �������� � ������ ������
        while (current != nullptr) {    // ���� �� ������ �� ����� ������
            cout << current->data << " "; // ������� ������ �������� ����
            current = current->next;    // ��������� � ���������� ����
        }
        cout << endl;         // ������� �� ����� ������ ����� ������
    }

    // ����� ��� ��������� ��������� �� ��������� ������� ������
    Node* getLastNode() {
        Node* current = head;           // �������� � ������ ������
        while (current != nullptr && current->next != nullptr) { // ���� �� ���������� ����
            current = current->next;
        }
        return current;                 // ���������� ��������� �� ��������� ����
    }
    void clearList() {
        while (head != nullptr) {       // ���� ������ �� ����
            Node* temp = head;          // ��������� ������� ������
            head = head->next;          // ���������� ������ �� ��������� ����
            delete temp;                // ������� ����
        }
        cout << "������ ������." << endl;
    }

    friend void insertBeforeEverySecond(LinkedList& list, int M);
};


void insertBeforeEverySecond(LinkedList& list, int M) {
    list.insertBeforeEverySecond(M);
}

int main() {
    LinkedList list;                     // ������� ������
    int n, value, M;


    cout << "������� ���������� ��������� � ������: ";
    cin >> n;
    cout << "������� �������� ������: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;               // ������ �������� ��������
        list.add(value);                 // ��������� ������� � ������
    }


    cout << "������� �������� M ��� �������: ";
    cin >> M;

    // ������� �������� M ����� ������ ������ ���������
    insertBeforeEverySecond(list, M);


    cout << "������ ����� �������: ";
    list.print();

    // ��������� ��������� �� ��������� ������� ������
    Node* lastNode = list.getLastNode();

    // ����� ����������
    if (lastNode != nullptr) {
        cout << "��������� �� ��������� ������� ������: " << lastNode << endl;
        cout << "�������� ���������� ��������: " << lastNode->data << endl;
    }
    else {
        cout << "������ ����." << endl;

    }
    list.clearList();

    // ��������, ��� ������ ����
    cout << "�������� ������ ����� �������: ";
    list.print();


    return 0;
}