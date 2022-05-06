#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    const int a =4;
    int array[a][a];
    int d;
    cout << "Функция выбора:" << endl <<  "1 - ручная" << endl << "2 - автоматически" << endl;
    cin >> d;
    switch (d)
    {
    case 1:
    {
        for(int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                cout << "Функция ввода графов a[" << i << "][" << j << "] ";
                cin >> array[i][j];
            }
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                array[i][j]= rand() % 10;
            }
        }
        break;
    }
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    int n = 7;
    bool* was_been = new bool[n];
    memset(was_been, false, sizeof(bool) * n);
    was_been[0] = true;
    for (int l = 0; l < n - 1; l++) {
        int minx = -1, miny = -1;
        for (int i = 0; i < n; i++)
            if (was_been[i])
                for (int j = 0; j < n; j++)
                    if (!was_been[j] && array[i][j] > 0 && (miny == -1 || array[i][j] < array[miny][minx]))
                        miny = i, minx = j;
        was_been[minx] = true;
        cout << miny << "->" << minx << endl;
    }

    system("pause");
}