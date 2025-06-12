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


#include "container.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

enum class InputMethod { KEYBOARD = 1, RANDOM, FILE_INPUT };

void FillContainer(Deque& container, int size) {
    int method = 2, value = 3;
    cout << "�������� ������ ���������� (1 - ����������, 2 - ��������� �����, 3 - ����): ";
    while (!(cin >> method) || method < static_cast<int>(InputMethod::KEYBOARD) || method > static_cast<int>(InputMethod::FILE_INPUT)) {
        cerr << "�������� ����� �����. ����������, ������� 1, 2 ��� 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (static_cast<InputMethod>(method)) {
    case InputMethod::KEYBOARD:
        cout << "������� " << size << " ���������:\n";
        for (int i = 0; i < size; i++) {
            while (!(cin >> value)) {
                cerr << "�������� ����. ����������, ������� ����� �����: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            container.pushBack(value);
        }
        break;

    case InputMethod::RANDOM:
        srand(time(0));
        for (int i = 0; i < size; i++) {
            container.pushBack(rand() % 100 - 50);
        }
        break;

    case InputMethod::FILE_INPUT: {
        ifstream file("input.txt");
        if (!file) {
            cerr << "�� ������� ������� ����\n";
            return;
        }
        for (int i = 0; i < size && file >> value; ++i) {
            container.pushBack(value);
        }
        const int containerSize = container.getSize();
        if (containerSize < size) {
            cerr << "������������ ������ � �����. ��������� ������ " << containerSize << " ���������.\n";
        }
        file.close();
        break;
    }

    default:
        cerr << "�������� ����� �����\n";
        break;
    }
}

void FillContainer(List& container, int size) {
    int method, value;
    cout << "�������� ������ ���������� (1 - ����������, 2 - ��������� �����, 3 - ����): ";
    while (!(cin >> method) || method < static_cast<int>(InputMethod::KEYBOARD) || method > static_cast<int>(InputMethod::FILE_INPUT)) {
        cerr << "�������� ����� �����. ����������, ������� 1, 2 ��� 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (static_cast<InputMethod>(method)) {
    case InputMethod::KEYBOARD:
        cout << "������� " << size << " ���������:\n";
        for (int i = 0; i < size; i++) {
            while (!(cin >> value)) {
                cerr << "�������� ����. ����������, ������� ����� �����: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            container.pushBack(value);
        }
        break;

    case InputMethod::RANDOM:
        srand(time(0));
        for (int i = 0; i < size; ++i) {
            container.pushBack(rand() % 100 - 50);
        }
        break;

    case InputMethod::FILE_INPUT: {
        ifstream file("input.txt");
        if (!file) {
            cerr << "�� ������� ������� ����\n";
            return;
        }
        for (int i = 0; i < size && file >> value; ++i) {
            container.pushBack(value);
        }

        const int containerSize = container.getSize();
        if (containerSize < size) {
            cerr << "������������ ������ � �����. ��������� ������ " << containerSize << " ���������.\n";
        }
        file.close();
        break;
    }

    default:
        cerr << "�������� ����� �����\n";
        break;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        int dequeSize = 1, listSize = 1;

        cout << "������� ������ ���� (>= 5): ";
        while (!(cin >> dequeSize) || dequeSize < 5) {
            cerr << "������ ���� ������ ���� >= 5. ����������, ������� ���������� ��������: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "������� ������ ������ (>= 5): ";
        while (!(cin >> listSize) || listSize < 5) {
            cerr << "������ ������ ������ ���� >= 5. ����������, ������� ���������� ��������: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        Deque dq = nullptr;
        List lst = nullptr;

        cout << "\n���������� ����:\n";
        FillContainer(dq, dequeSize);

        cout << "\n���������� ������:\n";
        FillContainer(lst, listSize);

        cout << "\n�������� ���:\n";
        dq.display();

        cout << "�������� ������:\n";
        lst.display();

        lst.insertBeforeFifthFromEnd(dq);

        cout << "\n��������� ����� �������:\n";
        cout << "��� (�� ���������):\n";
        dq.display();

        cout << "������ (����������):\n";
        lst.display();

    }
    catch (const exception& e) {
        cerr << "������: " << e.what() << endl;
        return 1;
    }

    return 0;
}