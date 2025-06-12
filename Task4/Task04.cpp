/* ��� ���������� �������� ������ � ��������� ������ ������� �����
������. ��� �������� ������ ������ ��������� ����� ����� ��������. ����������
������� �������� ��������� ������, ������� ��������� ����� ���������� �
���������� ���������� ������, � ��� �������, � ����� ��� ��������� � ��������
������. ������������ ���������.

��� ������������ ��������� ������ ������������� ����� ������. �� ������������ STL.  ��� ������ ������������ ��������� ������ ���� ������������
����������� ����� ������� - ����������/��������/������ ���������.
�� ���� ������� ����������� ������� �������������� ����������. ���� ������ � ����������.*/

#include <iostream>
using namespace std;

// ��������� ���� ����������� ������
struct Uzel {
    int Znachenie;         // �������� ����
    Uzel* Predydushiy;      // ��������� �� ���������� ����
    Uzel* Sleduyushiy;      // ��������� �� ��������� ����
};

// ����� ��� ������ � ���������� �������
class Spisok {
private:
    Uzel* PerviyElement;    // ��������� �� ������ ������� ������

public:
    // ������������� ������
    void Initsializatsiya() {
        PerviyElement = nullptr;
    }

    // ������� ������
    void Ochistka() {
        Uzel* Tekushiy = PerviyElement;
        while (Tekushiy != nullptr) {
            Uzel* Vremenniy = Tekushiy;
            Tekushiy = Tekushiy->Sleduyushiy;
            delete Vremenniy;
        }
        PerviyElement = nullptr;
    }

    // ���������� �������� � ����� ������
    void DobavitElement(int Znachenie) {
        Uzel* Noviy = new Uzel;
        Noviy->Znachenie = Znachenie;
        Noviy->Predydushiy = nullptr;
        Noviy->Sleduyushiy = nullptr;

        if (PerviyElement == nullptr) {
            PerviyElement = Noviy;
        }
        else {
            Uzel* Tekushiy = PerviyElement;
            while (Tekushiy->Sleduyushiy != nullptr) {
                Tekushiy = Tekushiy->Sleduyushiy;
            }
            Tekushiy->Sleduyushiy = Noviy;
            Noviy->Predydushiy = Tekushiy;
        }
    }

    // ����� ���� ��������� ������
    void VivodSpiska() {
        Uzel* Tekushiy = PerviyElement;
        while (Tekushiy != nullptr) {
            cout << Tekushiy->Znachenie << " ";
            Tekushiy = Tekushiy->Sleduyushiy;
        }
        cout << endl;
    }

    // ����� ������������ � ������������� ���������
    void PoiskMinMax(Uzel*& Min, Uzel*& Max) {
        if (PerviyElement == nullptr) return;

        Min = Max = PerviyElement;
        Uzel* Tekushiy = PerviyElement->Sleduyushiy;

        while (Tekushiy != nullptr) {
            if (Tekushiy->Znachenie < Min->Znachenie) Min = Tekushiy;
            if (Tekushiy->Znachenie > Max->Znachenie) Max = Tekushiy;
            Tekushiy = Tekushiy->Sleduyushiy;
        }
    }

    // ��������, ����� ������� ����������� ������
    bool ProverkaPoryadka(Uzel* A, Uzel* B) {
        Uzel* Tekushiy = PerviyElement;
        while (Tekushiy != nullptr) {
            if (Tekushiy == A) return true;
            if (Tekushiy == B) return false;
            Tekushiy = Tekushiy->Sleduyushiy;
        }
        return false;
    }

    // ����� ��������� ����� ����������� � ������������
    void VivodMezhduMinMax() {
        Uzel* Min = nullptr;
        Uzel* Max = nullptr;
        PoiskMinMax(Min, Max);

        if (Min == nullptr || Max == nullptr || Min == Max) {
            cout << "��� ��������� ��� ������!" << endl;
            return;
        }

        bool MinPerviy = ProverkaPoryadka(Min, Max);
        Uzel* Start = MinPerviy ? Min : Max;
        Uzel* End = MinPerviy ? Max : Min;

        cout << "�������� ����� " << Min->Znachenie << " � " << Max->Znachenie << ": ";
        Uzel* Tekushiy = Start->Sleduyushiy;
        bool EstElementy = false;

        while (Tekushiy != nullptr && Tekushiy != End) {
            cout << Tekushiy->Znachenie << " ";
            EstElementy = true;
            Tekushiy = Tekushiy->Sleduyushiy;
        }

        if (!EstElementy) cout << "�����������";
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Spisok Spisok;
    Spisok.Initsializatsiya();

    cout << "������� ���������� ���������: ";
    int N;
    cin >> N;

    if (N <= 0) {
        cout << "������������ �����!" << endl;
        return 0;
    }

    cout << "������� ��������:" << endl;
    for (int i = 0; i < N; i++) {
        int Chislo;
        if (!(cin >> Chislo)) {
            cout << "������ �����!" << endl;
            return 0;
        }
        Spisok.DobavitElement(Chislo);
    }

    cout << "������: ";
    Spisok.VivodSpiska();
    Spisok.VivodMezhduMinMax();
    Spisok.Ochistka();

    return 0;
}