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
    setlocale(LC_ALL, "Russian");

    Queue queue = nullptr;
    try {
        int n = getPositiveInteger("������� ���������� ��������� �������: ");

        cout << "������� �������� �������:\n";
        for (int i = 0; i < n; ++i) {
            int num = getInteger("������� " + to_string(i + 1) + ": ");
            queue.push(num);
        }

        cout << "\n�������� �������: ";
        queue.display();

        cout << "����������� ��������: ";
        queue.processUntilEven();
        cout << endl;

        cout << "���������� �������: ";
        queue.display();

        cout << "\n��������� ����������:\n";
        queue.getHeadAndTailAddresses();

    }
    catch (const exception& e) {
        cerr << "������: " << e.what() << endl;
        return 1;
    }

    return 0;
}