/*
 * Продолжение задачи №2 Создание очереди
 *
 * Даны указатели P1 и P2 на начало и конец непустой очереди. Извлекать из очереди
 * элементы, пока значение начального элемента очереди не станет четным, и выводить значения
 * извлеченных элементов(если очередь не содержит элементов с четными значениями, то извлечь
 * все ее элементы).Вывести также новые адреса начала и конца очереди(для пустой очереди
 * дважды вывести nullptr).После извлечения элементов из очереди освобождать память, которую
 * они занимали
 *
 * Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - добавления/удаления/вывода элементов.
 * Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
 *
 * В заданиях данной подгруппы структура «очередь» (queue) моделируется цепочкой связанных
 * узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Началом
 * очереди («головой», head) считается первый элемент цепочки, концом («хвостом», tail) — ее
 * последний элемент. Для возможности быстрого добавления в конец очереди нового элемента
 * удобно хранить, помимо указателя на начало очереди, также и указатель на ее конец. В случае
 * пустой очереди указатели на ее начало и конец полагаются равными nullptr. Как и для стека,
 * значением элемента очереди считается значение его поля Data.
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
            cout << "Ошибка! Введите положительное число: ";
        } else {
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
            cout << "Ошибка! Введите целое число: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    Queue queue = nullptr;
    try {
        int n = getPositiveInteger("Введите количество элементов очереди: ");

        cout << "Введите элементы очереди:\n";
        for (int i = 0; i < n; ++i) {
            int num = getInteger("Элемент " + to_string(i+1) + ": ");
            queue.push(num);
        }

        cout << "\nИсходная очередь: ";
        queue.display();

        cout << "Извлеченные элементы: ";
        queue.processUntilEven();
        cout << endl;

        cout << "Оставшаяся очередь: ";
        queue.display();

        cout << "\nСостояние указателей:\n";
        queue.getHeadAndTailAddresses();

    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}
