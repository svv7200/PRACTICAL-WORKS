#include <iostream>
#include <list>
using namespace std;

class hashingDDA
{
    int capacity;
    list<int>* chair;

public:
    hashingDDA(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);

    int dataAuthentication(int n)
    {
        int i;
        if (n == 1 || n == 0)
        {
            return 0;
        }
        for (i = 2; i < n / 2; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    int get_datAuthentication(int n)
    {
        if (n % 2 == 0)
        {
            n++;
        }
        while (!dataAuthentication(n))
        {
            n += 2;
        }
        return n;
    }

    int hashingDDA_Function(int key)
    {
        return (key % capacity);
    }
    void displayHash();
};
hashingDDA::hashingDDA(int c)
{
    int size = get_datAuthentication(c);
    this->capacity = size;
    chair = new list<int>[capacity];
}
void hashingDDA::insertItem(int key, int data)
{
    int index = hashingDDA_Function(key);
    chair[index].push_back(data);
}

void hashingDDA::deleteItem(int key)
{
    int index = hashingDDA_Function(key);

    list<int>::iterator i;
    for (i = chair[index].begin();
         i != chair[index].end(); i++)
    {
        if (*i == key)
            break;
    }

    if (i != chair[index].end())
        chair[index].erase(i);
}

void hashingDDA::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "Chair[" << i << "]";
        for (auto x : chair[i])
            cout << " --> " << x;
        cout << endl;
        cout << "Table[" << i << "]";
        for (auto x : chair[i])
            cout << " --> " << x;
        cout << endl;
    }
}

/***********************************************/

int main()
{
    int key[] = { 236561, 326561, 215652, 367621, 456533, 266762 };

    int data[] = { 127873, 433432, 523223, 909043, 676423, 114541 };

    int n = sizeof(key) / sizeof(key[0]);

    hashingDDA h(n);

    for (int i = 0; i < n; i++)
        h.insertItem(key[i], data[i]);

    h.deleteItem(12);

    h.displayHash();
}