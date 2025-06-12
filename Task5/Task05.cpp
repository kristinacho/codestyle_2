/* ���������� ����������� �������� ����� �����. ���
���������� ���������� ������������ �������� � ����������� ���������������� ����������,
��� ������ ��������� ������������ �������� (��� ������ ��������� � �������� �������
������������ �������� ���������, ������������ ���������-������� rbegin � rend)
����������� ������� �������������� ����������. ���� ������ ������������
������� ��������� (� ����������, ������, �� �����)

���� ��� D � ������ L. ������ �������� ��������� �������� �� ����� 5
���������. �������� ����� ����� � ����� ��������� ������ ��������� 5 ��������� ���� �
�������� �������. ������������ ���� ����� �������-����� insert.

*/


#include <ctime>
#include <deque>
#include <list>
#include <fstream>
#include <iostream>
using namespace std;
template <typename Container>
void Input(Container& N, int n)//���������� �����������
{
    int m, x;
    cout << "�������� ������ ���������� ����������: " << endl;
    cout << "1)���� � ����������." << endl;
    cout << "2)���� � ������� ������������." << endl;
    cout << "3)���� ������ �� ���������� �����." << endl;
    cin >> m;
    if (n < 5)
    {
        cout << "������. ������������ ������." << endl;
        return;
    }
    switch (m)
    {
    case 1:
    {
        for (int i = 0; i < n; i++)
        {
            cout << "������� " << i + 1 << " �������: ";
            cin >> x;
            N.insert(N.end(), x);
        }
        break;
    }
    case 2:
    {
        srand(time(0));
        for (int i = 0; i < n; i++)
            N.insert(N.end(), rand() % 101 - 50);
        break;
    }
    case 3:
    {
        ifstream file("a.txt", ios::in);// a.txt {9 3 -44-82 75 2 5 9 -43 74 927 94 -27 3 57 1 0 74 473 84}
        if (!file)
        {
            cout << "������. ���� �� ��� ������.";
            return;
        }
        for (int i = 0; i < n; i++)
        {
            file >> x;
            N.insert(N.end(), x);
        }
        file.close();
        break;
    }
    default:
    {
        cout << "������ �����." << endl;
        break;
    }
    }
}
template <typename Container>
void Print(const Container& N)//����� ����������� �����������
{
    for (auto it = N.begin(); it != N.end(); it++)
        cout << *it << " ";
    cout << endl;
}
void Insert(deque<int>& D, list<int>& L)//������� ����� 5 � ����� �������� ������ ��������� 5 ��������� ���� � �������� �������
{
    list<int>::iterator it = L.end();
    for (int i = 0; i < 5; i++)
        --it;
    for (int i = 4; i >= 0; i--)
        it = L.insert(it, D[D.size() - 1 - i]);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n1, n2;
    deque <int> D;
    list <int> L;
    cout << "������� ����������� ���� n1 (n1 >= 5): ";
    cin >> n1;
    Input(D, n1);
    cout << "������� ����������� ������ n2 (n2 >= 5): ";
    cin >> n2;
    Input(L, n2);
    cout << "����������� ���������� �����������." << endl;
    cout << "���: ";
    Print(D);
    cout << "������: ";
    Print(L);
    Insert(D, L);
    cout << "��������� ���������� �����������." << endl;
    cout << "���: ";
    Print(D);
    cout << "������: ";
    Print(L);
    return 0;
}