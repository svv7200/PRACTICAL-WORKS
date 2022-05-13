#include <iostream>
using namespace std;

int main()
{
    int n, m, a, b;

    //n-конвееры
    // m-рабочие

    cout<<"Введите количетсво конвееров:\n";
    cin >> n;
    cout<<"Введите рабочих:\n"; cin >>m;

    if (n>m)
    {
        cout<<"Работы идут очень медленно,хочешь добавить рабочих?\n";
        cin>>a;
        switch (a) {
            case 1:
                cout<<"Введите количество новых рабочих\n";
                cin>>b;
                m+=b;
                if (b=0){
                    cout<<"Ты ничего не изменил";
                }
                else{
                    cout<<"Стало больше рабочих:"<<m<<"\nТеперь работы ускорились";
                }
                break;
            case 2:
                cout<<"Ты ничего не изменил";
                break;
            default:
                cout<<"Ничего";
                break;
        }
    }

    if (m>n){
        cout<<"Добавить еще конвееров?\n";
        cin>>a;

        switch (a) {
            case 1:
                cout<<"Введите желаемое количество конвееров\n";
                cin>>b;
                n+=b;
                if (b=0){
                    cout<<"Ничего не изменялось";
                }
                else{
                    cout<<"Добавилось больше конвееров:"<<n<<"\nработа пошла полным ходом";
                }
                break;
            case 2:
                cout<<"Ничего не изменялось";
                break;
            default:
                cout<<"Ничего";
                break;
        }
    }
    else{
        cout<<"Стабильность";
    }
}