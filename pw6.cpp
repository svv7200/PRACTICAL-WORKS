#include <iostream>
#include <fstream>

using namespace std;

int postr(const char* s, const char* p, int n)
{

	int lenghtC;
	int lenghtS;

	int i, j;

			//���������� ������� ������ � ��������� �������� 

	for (lenghtC = 0; p[lenghtC]; lenghtC++);
	for (lenghtS = 0; s[lenghtS]; lenghtS++);

	for (i = 0; i <= lenghtS - lenghtC; i++) // ����� �� ����� �������
	{
		for (j = 0; s[i + j] == p[j]; j++);				/** ��������� ����������: ���� ��������� 
																	����������� �� ����� �������� 
																		������ �� ������� ����� ������, 
																			������ ���������� ����������;
																				������ ����������  **/

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

	string stroke; // ���������� ������

	char buff[5000]; // ������������� �������� 

	ifstream fin("�:\\txt.txt"); // �������� �����

	while (!fin.eof())			//���� ��� ������ txt.txt
	{
		fin.getline(buff, sizeof(buff));

		cout << buff << endl;
	}

	cin >> stroke; // ���� ������

	const char* s = buff;
	const char* p = stroke.c_str();

	int i, n = 0;

	for (i = 1; n != -1; i++)
	{
		n = postr(s, p, i); // ���������� ������� ������ � ��������� �������� 

		if (n >= 0)

			cout << n << endl;
	}
}