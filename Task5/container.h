/* Продолжение задания №5 Контейнер.
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

#ifndef CONTAINER_H
#define CONTAINER_H

typedef Deque* DequePtr;
typedef List* ListPtr;

/**
 * @brief Создает новый пустой дек.
 * @return Указатель на созданный дек или nullptr при ошибке выделения памяти.
 */
DequePtr CreateDeque();

/**
 * @brief Уничтожает дек и освобождает все связанные ресурсы.
 * @param dq Указатель на дек.
 */
void DestroyDeque(DequePtr dq);

/**
 * @brief Добавляет элемент в конец дека.
 * @param dq Указатель на дек.
 * @param value Значение для добавления.
 */
void PushBackDeque(DequePtr dq, int value);

/**
 * @brief Добавляет элемент в начало дека.
 * @param dq Указатель на дек.
 * @param value Значение для добавления.
 */
void PushFrontDeque(DequePtr dq, int value);

/**
 * @brief Удаляет и возвращает элемент из конца дека.
 * @param dq Указатель на дек.
 * @return Удаленное значение или 0 в случае ошибки (дек пуст/nullptr).
 */
int PopBackDeque(DequePtr dq);

/**
 * @brief Удаляет и возвращает элемент из начала дека.
 * @param dq Указатель на дек.
 * @return Удаленное значение или 0 в случае ошибки (дек пуст/nullptr).
 */
int PopFrontDeque(DequePtr dq);

/**
 * @brief Возвращает элемент дека по индексу с конца.
 * @param dq Указатель на дек.
 * @param index Индекс элемента (0 для последнего, 1 для предпоследнего и т.д.).
 * @return Значение элемента или 0 в случае ошибки (индекс вне диапазона/nullptr).
 */
int GetBackDeque(const DequePtr dq, int index);

/**
 * @brief Возвращает текущий размер дека.
 * @param dq Указатель на дек.
 * @return Количество элементов в деке или 0 в случае ошибки (nullptr).
 */
int GetDequeSize(const DequePtr dq);

/**
 * @brief Проверяет, пуст ли дек.
 * @param dq Указатель на дек.
 * @return true, если дек пуст или указатель nullptr, false в противном случае.
 */
bool IsDequeEmpty(const DequePtr dq);

/**
 * @brief Очищает дек, удаляя все элементы.
 * @param dq Указатель на дек.
 */
void ClearDeque(DequePtr dq);

/**
 * @brief Выводит элементы дека в прямом порядке.
 * @param dq Указатель на дек.
 */
void DisplayDeque(const DequePtr dq);

/**
 * @brief Выводит элементы дека в обратном порядке.
 * @param dq Указатель на дек.
 */
void DisplayDequeReverse(const DequePtr dq);

/**
 * @brief Создает новый пустой список.
 * @return Указатель на созданный список или nullptr при ошибке выделения памяти.
 */
ListPtr CreateList();

/**
 * @brief Уничтожает список и освобождает все связанные ресурсы.
 * @param lst Указатель на список.
 */
void DestroyList(ListPtr lst);

/**
 * @brief Добавляет элемент в конец списка.
 * @param lst Указатель на список.
 * @param value Значение для добавления.
 */
void PushBackList(ListPtr lst, int value);

/**
 * @brief Добавляет элемент в начало списка.
 * @param lst Указатель на список.
 * @param value Значение для добавления.
 */
void PushFrontList(ListPtr lst, int value);

/**
 * @brief Удаляет и возвращает элемент из конца списка.
 * @param lst Указатель на список.
 * @return Удаленное значение или 0 в случае ошибки (список пуст/nullptr).
 */
int PopBackList(ListPtr lst);

/**
 * @brief Удаляет и возвращает элемент из начала списка.
 * @param lst Указатель на список.
 * @return Удаленное значение или 0 в случае ошибки (список пуст/nullptr).
 */
int PopFrontList(ListPtr lst);

/**
 * @brief Проверяет, пуст ли список.
 * @param lst Указатель на список.
 * @return true, если список пуст или указатель nullptr, false в противном случае.
 */
bool IsListEmpty(const ListPtr lst);

/**
 * @brief Возвращает текущий размер списка.
 * @param lst Указатель на список.
 * @return Количество элементов в списке или 0 в случае ошибки (nullptr).
 */
int GetListSize(const ListPtr lst);

/**
 * @brief Очищает список, удаляя все элементы.
 * @param lst Указатель на список.
 */
void ClearList(ListPtr lst);

/**
 * @brief Выводит элементы списка в прямом порядке.
 * @param lst Указатель на список.
 */
void DisplayList(const ListPtr lst);

/**
 * @brief Выводит элементы списка в обратном порядке.
 * @param lst Указатель на список.
 */
void DisplayListReverse(const ListPtr lst);

/**
 * @brief Вставляет последние 5 элементов дека (в обратном порядке) перед пятым с конца элементом списка.
 * @param lst Указатель на список.
 * @param dq Указатель на дек.
 * @return true в случае успешной вставки, false в случае ошибки.
 */
bool InsertBeforeFifthFromEnd(ListPtr lst, const DequePtr dq);

#endif // CONTAINER_H
