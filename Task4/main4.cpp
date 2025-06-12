/*
 * ����������� ������� �4 ���������� ������
 * ��� ���������� �������� ������ � ��������� ������ ������� �����
 * ������. ��� �������� ������ ������ ��������� ����� ����� ��������. ����������
 * ������� �������� ��������� ������, ������� ��������� ����� ���������� �
 * ���������� ���������� ������, � ��� �������, � ����� ��� ��������� � ��������
 * ������. ������������ ���������.
 *
 * ��� ������������ ��������� ������ ������������� ����� ������. �� ������������ STL.  ��� ������ ������������ ��������� ������ ���� ������������
 * ����������� ����� ������� - ����������/��������/������ ���������.
 * �� ���� ������� ����������� ������� �������������� ����������. ���� ������ � ����������.
 */

#include "double_list.h"
#include <iostream>
#include <limits>

using namespace std;

int GetPositiveInteger(const string& prompt) {
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

int GetInteger(const string& prompt) {
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

    DoublyLinkedList list = nullptr;
    try {
        int n = GetPositiveInteger("������� ���������� ��������� � ������: ");

        cout << "������� �������� ������:\n";
        for (int i = 0; i < n; ++i) {
            int value = getInteger("������� " + to_string(i + 1) + ": ");
            list.Append(value);
        }

        cout << "\n���������� ������: ";
        list.Display();

        cout << "\n���������:\n";
        list.PrintBetweenMinMax();

    }
    catch (const exception& e) {
        cerr << "������: " << e.what() << endl;
        return 1;
    }

    return 0;
}