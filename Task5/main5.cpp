/*
 * Продолжение задания №5 Контейнер.
 * Элементами контейнеров являются целые числа. Для
 * заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
 * для вывода элементов использовать итератор (для вывода элементов в обратном порядке
 * использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
 * Обязательно наличие дружественного интерфейса. Ввод данных организовать
 * разными способами (с клавиатуры, рандом, из файла)
 *
 * Даны дек D и список L. Каждый исходный контейнер содержит не менее 5
 * элементов. Вставить перед пятым с конца элементом списка последние 5 элементов дека в
 * обратном порядке. Использовать один вызов функции-члена insert.
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
    cout << "Âûáåðèòå ñïîñîá çàïîëíåíèÿ (1 - êëàâèàòóðà, 2 - ñëó÷àéíûå ÷èñëà, 3 - ôàéë): ";
    while (!(cin >> method) || method < static_cast<int>(InputMethod::KEYBOARD) || method > static_cast<int>(InputMethod::FILE_INPUT)) {
        cerr << "Íåâåðíûé ìåòîä ââîäà. Ïîæàëóéñòà, ââåäèòå 1, 2 èëè 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (static_cast<InputMethod>(method)) {
    case InputMethod::KEYBOARD:
        cout << "Ââåäèòå " << size << " ýëåìåíòîâ:\n";
        for (int i = 0; i < size; i++) {
            while (!(cin >> value)) {
                cerr << "Íåâåðíûé ââîä. Ïîæàëóéñòà, ââåäèòå öåëîå ÷èñëî: ";
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
            cerr << "Íå óäàëîñü îòêðûòü ôàéë\n";
            return;
        }
        for (int i = 0; i < size && file >> value; ++i) {
            container.pushBack(value);
        }
        const int containerSize = container.getSize();
        if (containerSize < size) {
            cerr << "Íåäîñòàòî÷íî äàííûõ â ôàéëå. Çàïîëíåíî òîëüêî " << containerSize << " ýëåìåíòîâ.\n";
        }
        file.close();
        break;
    }

    default:
        cerr << "Íåâåðíûé ìåòîä ââîäà\n";
        break;
    }
}

void FillContainer(List& container, int size) {
    int method, value;
    cout << "Âûáåðèòå ñïîñîá çàïîëíåíèÿ (1 - êëàâèàòóðà, 2 - ñëó÷àéíûå ÷èñëà, 3 - ôàéë): ";
    while (!(cin >> method) || method < static_cast<int>(InputMethod::KEYBOARD) || method > static_cast<int>(InputMethod::FILE_INPUT)) {
        cerr << "Íåâåðíûé ìåòîä ââîäà. Ïîæàëóéñòà, ââåäèòå 1, 2 èëè 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (static_cast<InputMethod>(method)) {
    case InputMethod::KEYBOARD:
        cout << "Ââåäèòå " << size << " ýëåìåíòîâ:\n";
        for (int i = 0; i < size; i++) {
            while (!(cin >> value)) {
                cerr << "Íåâåðíûé ââîä. Ïîæàëóéñòà, ââåäèòå öåëîå ÷èñëî: ";
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
            cerr << "Íå óäàëîñü îòêðûòü ôàéë\n";
            return;
        }
        for (int i = 0; i < size && file >> value; ++i) {
            container.pushBack(value);
        }

        const int containerSize = container.getSize();
        if (containerSize < size) {
            cerr << "Íåäîñòàòî÷íî äàííûõ â ôàéëå. Çàïîëíåíî òîëüêî " << containerSize << " ýëåìåíòîâ.\n";
        }
        file.close();
        break;
    }

    default:
        cerr << "Íåâåðíûé ìåòîä ââîäà\n";
        break;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        int dequeSize = 1, listSize = 1;

        cout << "Ââåäèòå ðàçìåð äåêà (>= 5): ";
        while (!(cin >> dequeSize) || dequeSize < 5) {
            cerr << "Ðàçìåð äåêà äîëæåí áûòü >= 5. Ïîæàëóéñòà, ââåäèòå êîððåêòíîå çíà÷åíèå: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Ââåäèòå ðàçìåð ñïèñêà (>= 5): ";
        while (!(cin >> listSize) || listSize < 5) {
            cerr << "Ðàçìåð ñïèñêà äîëæåí áûòü >= 5. Ïîæàëóéñòà, ââåäèòå êîððåêòíîå çíà÷åíèå: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        Deque dq = nullptr;
        List lst = nullptr;

        cout << "\nÇàïîëíåíèå äåêà:\n";
        FillContainer(dq, dequeSize);

        cout << "\nÇàïîëíåíèå ñïèñêà:\n";
        FillContainer(lst, listSize);

        cout << "\nÈñõîäíûé äåê:\n";
        dq.display();

        cout << "Èñõîäíûé ñïèñîê:\n";
        lst.display();

        lst.insertBeforeFifthFromEnd(dq);

        cout << "\nÐåçóëüòàò ïîñëå âñòàâêè:\n";
        cout << "Äåê (íå èçìåíèëñÿ):\n";
        dq.display();

        cout << "Ñïèñîê (èçìåíåííûé):\n";
        lst.display();

    }
    catch (const exception& e) {
        cerr << "Îøèáêà: " << e.what() << endl;
        return 1;
    }

    return 0;
}
