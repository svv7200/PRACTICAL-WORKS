#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

int pos(const char* s, const char* p, int n)
{
    int i, j;
    int lol, kek;

    for (lol = 0; p[lol]; lol++);
    for (kek = 0; s[kek]; kek++);

    for (i = 0; i <= kek - lol; i++){
        for (j = 0; s[i + j] == p[j]; j++);
        if (j - lol == 1 && i == kek - lol && !(n - 1)) return i;
        if (j == lol)
            if (n - 1) n--;
            else return i;
    }
    return -1;
}
int main() {
    setlocale(LC_ALL, "rus");

    char x[30];char y[33];
    int N, k, g;
    int ar[30];
    string line, a;
    ifstream f("//Users//sergejvasatkin//CLionProjects//pw12//module.txt");
    cout << "ASCII code\n : ";
    k = 0;
    while (f >> N) {
        ar[k++] = N;
    }
    for (int i = 0; i < k; i++) {
        cout << ar[i] << " ";
    }
    f.close();
    cout << endl;
    cout << "Перевод с языка: \n";
    for (int i = 0; i < 30; i++) {
        y[i] = ar[i];
        cout << y[i] << "";
    }
    cout << endl;
    ofstream out("//Users//sergejvasatkin//CLionProjects//pw12//binar.txt", ios::binary | ios::out);
    out.write((char*)&y, sizeof y);
    out.close();

    ifstream in("//Users//sergejvasatkin//CLionProjects//pw12//binarGroup.txt", ios::binary | ios::in);
    in.read((char*)&x, sizeof x);
    in.close();
    cout << "Данные из файла:\n";
    cout << x << endl;
    cout << "Введите номер для поиска: \n";
    cin >> a;
    const char* s = x;
    const char* p = a.c_str();
    int i, n = 0;
    for (i = 1; n != -1; i++){
        n = pos(s, p, i);

        if (n >= 0)
            cout << n << endl;
    }
    cout << "После удаления:\n ";
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j < 30; ++j) {
            x[j] = x[j + 1];
        }
    }
    for (int i = 0; i <= 30; i++) {
        cout << x[i] << "";
    }
    return 0;
}