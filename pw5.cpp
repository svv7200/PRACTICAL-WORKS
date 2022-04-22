#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int key, n, i, j, buff;
    cout << "Введите размер массива: "; cin >> n;
    int* arr = new int[n]; // создали массив на n элементов

    for (int i = 0; i < n; i++) //Рандом заполнение массива
    {
        arr[i] = rand() % 100; // заполняем массив случайными числами
        cout << arr[i] << "  "; // вывод массива на экран
    }
    cout << endl;
    //Сортировка начало
    for (i = 1; i < n; i++)
    {
        buff = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > buff; j--)
            arr[j + 1] = arr[j];

        arr[j + 1] = buff;
    }
    //Сортировка конец
    cout << "Отсортированный массив" << endl;//Сорутируем массив для того чтобы сработал поиск,тк для него нужен отср массив
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl << "Введите ключ: ";

    cin >> key; // считываем ключ

    bool flag = false;
    int l = 0; // левая граница
    int r = n - 1; // правая граница
    int mid;

    while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

        if (arr[mid] == key) flag = true; //проверяем ключ со серединным элементом
        if (arr[mid] > key) r = mid - 1; // проверяем, какую часть нужно отбросить
        else l = mid + 1;
    }

    if (flag) cout << "Индекс элемента " << key << " в массиве равен: " << mid + 1 << endl;
    return 0;
}
