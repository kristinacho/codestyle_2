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


#include "list.h"
#include <iostream>
#include <limits>

using namespace std;

int getPositiveInteger(const string& prompt) {
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

int getInteger(const string& prompt) {
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
    LinkedList list = nullptr;

    try {
        int n = getPositiveInteger("������� ���������� ��������� � ������: ");

        cout << "������� �������� ������:\n";
        for (int i = 0; i < n; ++i) {
            int value = getInteger("������� " + to_string(i + 1) + ": ");
            list.append(value);
        }

        cout << "\n�������� ������: ";
        list.display();

        int M = getInteger("\n������� �������� M ��� �������: ");
        list.insertBeforeEverySecond(M);

        cout << "\n������ ����� �������: ";
        list.display();

        void* lastNodeAddr = list.getLastNodeAddress();
        int lastNodeValue = list.getLastNodeValue();

        if (lastNodeAddr != nullptr) {
            cout << "\n����� ���������� ��������: " << lastNodeAddr
                << "\n�������� ���������� ��������: " << lastNodeValue << endl;
        }
        else {
            cout << "\n������ ����." << endl;
        }

    }
    catch (const exception& e) {
        cerr << "������: " << e.what() << endl;
        return 1;
    }

    return 0;
}