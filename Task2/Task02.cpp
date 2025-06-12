/* ���� ��������� P1 � P2 �� ������ � ����� �������� �������. ��������� �� �������
��������, ���� �������� ���������� �������� ������� �� ������ ������, � �������� ��������
����������� ���������(���� ������� �� �������� ��������� � ������� ����������, �� �������
��� �� ��������).������� ����� ����� ������ ������ � ����� �������(��� ������ �������
������ ������� nullptr).����� ���������� ��������� �� ������� ����������� ������, �������
��� ��������.


��� ������ ������������ ��������� ������ ���� ������������ ����������� ����� ������� - ����������/��������/������ ���������.
�� ���� ������� ����������� ������� �������������� ����������. ���� ������ � ����������.



� �������� ������ ��������� ��������� ��������� (queue) ������������ �������� ���������
�����-������� ���� TNode. ���� Next ���������� �������� ������� ����� nullptr. �������
������� (��������, head) ��������� ������ ������� �������, ������ (��������, tail) � ��
��������� �������. ��� ����������� �������� ���������� � ����� ������� ������ ��������
������ �������, ������ ��������� �� ������ �������, ����� � ��������� �� �� �����. � ������
������ ������� ��������� �� �� ������ � ����� ���������� ������� nullptr. ��� � ��� �����,
��������� �������� ������� ��������� �������� ��� ���� Data.*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool IsNumber(const  string& str) {
    if (str.empty()) return false;
    int start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    for (int i = start; i < str.length(); ++i) {
        if (!isdigit(str[i])) return false;
    }
    return start < str.length();
}
class Queue {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* P1;
    Node* P2;

public:
    Queue() : P1(nullptr), P2(nullptr) {}

    void push(int num) { // ���������� �������� � �������
        Node* newNode = new Node;
        newNode->data = num;
        newNode->next = nullptr;
        if (!P2) {
            P1 = P2 = newNode;
        }
        else {
            P2->next = newNode;
            P2 = newNode;
        }
        newNode->next = nullptr;
    }
    void show() { // ����� ���������
        Node* temp = P1;
        if (!temp) {
            cout << "������� ������" << endl;
            return;
        }
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool pop(int& num) {  // ���������� �������� �� �������
        if (!P1) return false; // ������� �����

        Node* temp = P1;
        num = P1->data;
        P1 = P1->next;
        if (!P1) P2 = nullptr; // ���� ������� ����� ������

        delete temp;
        return true;
    }

    Node* getP1() const {
        return P1;
    }
    void getP1data() const {
        int num1 = P1->data;
        cout << num1;
    }

    void getP2data() const {
        int num1 = P2->data;
        cout << num1;
    }

    Node* getP2() const {
        return P2;
    }

    void EvenHead() { // ���������� ���������, ���� �� ���������� ������ ��������
        int num;
        while (!(P1 == nullptr) && (P1->data % 2 != 0)) {
            pop(num);
            cout << num << " ";
        }
        cout << endl;
    }

    ~Queue() {
        int del;
        while (pop(del));
    }
};
int main() {
    setlocale(LC_ALL, "ru");
    Queue q;
    string in;
    string inum;
    int num;
    int n;
    cout << "������� ���������� ��������� � �������: ";
    cin >> in;
    if (!IsNumber(in)) {
        cout << "������������ ��������.";
        return 1;
    }
    else {
        n = stoi(in);
    }
    cout << "������� �������� �������: ";
    for (int i = 1; i <= n; i++) {
        cin >> inum;
        if (!IsNumber(inum)) {
            cout << "������������ ��������.";
            return 1;
        }
        else {
            num = stoi(inum);
            q.push(num);
        }
    }
    cout << "����������� �������: ";
    q.show();

    cout << "����������� ��������: ";
    q.EvenHead();
    cout << "���������� �������: ";
    q.show();
    cout << "�������� ������� ��������: ";
    q.getP1data();
    cout << endl;
    cout << "����� ����� ������ ������� (P1): " << q.getP1() << endl;
    cout << "�������� ���������� ��������: ";
    q.getP2data();
    cout << endl;
    cout << "����� ����� ����� ������� (P2): " << q.getP2() << endl;

    return 0;
}