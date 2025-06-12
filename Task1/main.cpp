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
#include <limits>

using namespace std;

int getPositiveInteger(const char* prompt) {
    int value = 0;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������! ������� ������������� �����: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int getInteger(const char* prompt) {
    int value = 0;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������! ������� ����� �����: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    Stack stack = nullptr;
    try {
        int n = getPositiveInteger("������� ���������� ��������� �����: ");

        for (int i = 0; i < n; ++i) {
            int num = getInteger("������� ������� �����: ");
            stack.push(num);
        }

        cout << "���������� �����:\n";
        stack.display();

        if (!stack.isEmpty()) {
            cout << "������ ������� �����: " << stack.top() << "\n";
            stack.pop();

            if (stack.isEmpty()) {
                cout << "���� ������ ����.\n";
            }
            else {
                cout << "����� ������� �������: " << stack.top() << "\n";
            }
        }
    }
    catch (const exception& e) {
        cerr << "������: " << e.what() << "\n";
        return 1;
    }

    return 0;
}