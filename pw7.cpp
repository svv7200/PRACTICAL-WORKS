#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef struct list_t
{
    int value;
    struct list_t* next;
}  

OPlist;

OPlist* Push(OPlist** list, int value)
{
    OPlist* node = (OPlist*)malloc(sizeof(OPlist)); // Динамическое выделение памяти для OPlist

    node->value = value;

    node->next = *list;

    *list = node;

    return *list;
}

OPlist* FND(OPlist* list, int value)
{
    for (; list && (list->value != value); list = list->next) { ; }

    return list;
}

void PRNT(OPlist* list) {
    for (; list; list = list->next) {
        printf("%d ", list->value);
    }
    cout << endl;
}

int RNDM(int minV, int maxV) // Функция для реализации рандомных значений
{
    return (rand() % (maxV - minV) + minV);
}

OPlist* GetGenList(size_t count, int minV, int maxV)
{
    OPlist* list = NULL;

    while(count--)
    {
        Push(&list, RNDM(minV, maxV));
    }

    return list;
}

OPlist* UniqueValue(OPlist* first, OPlist* second) // Получение уникального значения
{
    OPlist* list = NULL;

    for (; first; first = first->next)
    {
        if (!FND(list, first->value) && !FND(second, first->value))
        {
            Push(&list, first->value);
        }
    }

    return list;  // Возвращение списка, после отрабатывания цикла с условием
}


/*   Вывод
        списка  */

int main()
{
    setlocale(LC_ALL, "Ru");

    srand(time(NULL)); // Функция реального времени для работы RNDM

    OPlist* l1 = GetGenList(10, 3, 10);

    OPlist* l2 = GetGenList(10, 0, 7);

    OPlist* l = UniqueValue(l1, l2);
    
    
    cout <<"Выводим L1: "; PRNT(l1);

    cout << "Выводим L2: "; PRNT(l2);

    cout << "\tВывод L: "; PRNT(l);

    return 0;
}