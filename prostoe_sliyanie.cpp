#include <iostream>
#include <time.h>
using namespace std;

//функция, сливающая массивы
void connect(int* a, int first, int last)
{
    int middle, start, final, j;
    int* mas = new int[1001];
    middle = (first + last) / 2; //вычисление среднего элемента
    start = first; //начало левой части
    final = middle + 1; //начало правой части
    for (j = first; j <= last; j++) //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (a[start] < a[final])))
        {
            mas[j] = a[start];
            start++;
        }
        else
        {
            mas[j] = a[final];
            final++;
        }
    //возвращение результата в список5

    for (j = first; j <= last; j++) a[j] = mas[j];
    delete[]mas;
};
//рекурсивная процедура сортировки
void Sort(int* a, int first, int last)
{
    {
        if (first < last)
        {
            Sort(a, first, (first + last) / 2); //сортировка левой части
            Sort(a, (first + last) / 2 + 1, last); //сортировка правой части
            connect(a, first, last); //слияние двух частей
        }
    }
};
//главная функция
int main()
{
    setlocale(LC_ALL, "Rus");
    int i, n;
    cout << "Размер массива: "; cin >> n;
    int* a = new int[1001];
    clock_t start, end;
    start = clock();
    for (int i = 0; i < n; i++){
        a[i] = rand() % 101; // заполняем массив случайными числами
        cout << a[i] << "  "; // вывод массива на экран
    }
    Sort(a, 0, n); //вызов сортирующей процедуры
    cout <<endl; //вывод упорядоченного массива
    for (i = 1; i <= n; i++) cout << a[i] << "  ";
    cout << endl;
    end = clock();
    printf("Время выполнение программы %.4f\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
    delete[]a;
}