/*
 * Продолжение задачи №3 создание списка
 * Все динамические структуры данных реализовывать через классы. Не использовать STL.  Для каждой динамической структуры должен быть предусмотрен
 * стандартный набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно
 * наличие дружественного интерфейса. Ввод данных с клавиатуры.
 *
 * Дан односвязный линейный список и указатель на голову списка P1. Необходимо
 * вставить значение M перед каждым вторым элементом списка, и вывести ссылку на последний
 * элемент полученного списка P2. При нечетном числе элементов исходного списка в конец
 * списка вставлять не надо.
*/

#ifndef LIST_H
#define LIST_H

typedef struct LinkedList* LinkedListPtr;

/**
 * @brief Создает новый пустой список
 * @return Указатель на список или nullptr при ошибке 
 */
LinkedListPtr createList();

/**
 * @brief Уничтожает список и освобождает память
 * @param list Указатель на список
 */
void destroyList(LinkedListPtr list);

/**
 * @brief Добавляет элемент в конец списка
 * @param list Указатель на список
 * @param value Значение для добавления
 * @return true при успехе, false при ошибке
 */
bool append(LinkedListPtr list, int value);

/**
 * @brief Вставляет M перед каждым вторым элементом
 * @param list Указатель на список
 * @param M Значение для вставки
 */
void insertBeforeEverySecond(LinkedListPtr list, int M);

/**
 * @brief Выводит содержимое списка
 * @param list Указатель на список
 */
void displayList(LinkedListPtr list);

/**
 * @brief Получает адрес последнего элемента списка
 * @param list Указатель на список
 * @return Указатель на последний элемент или nullptr
 */
void* getLastNodeAddress(LinkedListPtr list);

/**
 * @brief Получает значение последнего элемента списка
 * @param list Указатель на список
 * @return Значение элемента или -1 если список пуст
 */
int getLastNodeValue(LinkedListPtr list);

/**
 * @brief Проверяет, пуст ли список
 * @param list Указатель на список
 * @return true если список пуст или невалиден
 */
bool isEmpty(LinkedListPtr list);

#endif // LIST_H
