#include <iostream>
#include <fstream>

using namespace std;

int postr(const char* s, const char* p, int n)
{

	int lenghtC;
	int lenghtS;

	int i, j;

			//Нахождение размера строки и исходного занчения 

	for (lenghtC = 0; p[lenghtC]; lenghtC++);
	for (lenghtS = 0; s[lenghtS]; lenghtS++);

	for (i = 0; i <= lenghtS - lenghtC; i++) // Поиск до конца условия
	{
		for (j = 0; s[i + j] == p[j]; j++);				/** Проверяем совпадение: если совпадает 
																	посимвольно по длине искомого 
																		вернем из функции номер ячейки, 
																			откуда начинается совпадение;
																				учесть терминатор  **/

		if (j - lenghtC == 1 && i == lenghtS - lenghtC && !(n - 1)) { return i; };

		if (j == lenghtC)
			if (n - 1) n--;

			else return i;
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "Ru");

	string stroke; // Объявление строки

	char buff[5000]; // Промежуточное хранение 

	ifstream fin("с:\\txt.txt"); // Открытие файла

	while (!fin.eof())			//Цикл для чтения txt.txt
	{
		fin.getline(buff, sizeof(buff));

		cout << buff << endl;
	}

	cin >> stroke; // Ввод строки

	const char* s = buff;
	const char* p = stroke.c_str();

	int i, n = 0;

	for (i = 1; n != -1; i++)
	{
		n = postr(s, p, i); // Нахождение размера строки и исходного занчения 

		if (n >= 0)

			cout << n << endl;
	}
}