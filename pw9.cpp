#include <iostream>

using namespace std;

int maxValue(int number)
{
    int max = 0;
    while (number > 1)
    {
        number /= 10;
        max++;
    }
    return max;
}

int digitValue(int number, int value)
{
    while (value > 1)
    {
        number /= 10;
        value--;
    }
    return number % 10;
}

void sortingValue(int** arrayDrop, int* mas, int value, int n)
{
    int* amountArr, i, j, temp = 0;
    amountArr = new int[n];
    for (i = 0; i < n; i++)
        amountArr[i] = 0;
    for (i = 0; i < n; i++)
    {
        int a = digitValue(mas[i], value);
        arrayDrop[amountArr[a]][a] = mas[i];
        amountArr[a]++;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < amountArr[i]; j++)
        {
            mas[temp] = arrayDrop[j][i];
            temp++;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    int n, amountValue = 0;

    int value, i, * arr, ** arrayDrop;

    cout << "Введите размер последовательности: ";
    cin >> n;

    arr = new int[n];
    cout << "Введите элементы последовательности: " << endl;

    for (int i = 0; i < n; i++) // Функция rndm для заполнения  массива
    {
        arr[i] = rand() % 100; // Заполнение массива рандомными числами
        cout << "[" << i + 1 << "]=" << arr[i] << endl;
    }

    arrayDrop = new int* [n];

    for (i = 0; i < n; i++)
        arrayDrop[i] = new int[n];

    for (i = 0; i < n; i++)
        if (amountValue < maxValue(arr[i]))
            amountValue = maxValue(arr[i]);

    for (value = 1; value <= amountValue; value++)
        sortingValue(arrayDrop, arr, value, n);

    for (i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0; // Возвращение нуля
}
