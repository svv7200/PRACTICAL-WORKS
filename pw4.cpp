#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n, i, j, q;
    int position = 0;
    cout << "Введите размер массива: "; cin >> n;
    int* arr = new int[n]; // создали массив на n элементов

    for (int i = 0; i < n; i++) //Рандом заполнение массива
    {
        arr[i] = rand() % 100; // заполняем массив случайными числами
        cout << arr[i] << "  "; // вывод массива на экран
    }
    cout << endl;
    cout << "Введите число которые надо найти: "; cin >> q;
    if (arr[n - 1] != q) //Проверим, нет ли искомого элемента на последней позиции
    {
        arr[n - 1] = q;  //Установим &quot;барьер&quot;
        for (; arr[position] != q; position++);  //Поиск
        position++; //Корректируем номер позиции
    }
    else {
        cout << n;
        return 0;
    }
    cout <<"Позиция введенного числа равна: " << position; //Если элемент найден, то возвращаем его позицию, если нет, то 0
}
