#include <iostream> 
#include <stack>

using namespace std;

int main() {
    int n;
    int x;

    stack<int> s; // Объявление структуры стек

    cout << "Enter n : " ;
    cin >> n; // Ручной ввод N
    
    for (int i = 0; i < n; i++) {
        
        cout << "Enter x : ";
        cin >> x; // Ручной ввод X
        
        if (i == 0) {
            s.push(x); // Элемент в начало списка
        }
        if (i > 0) {
            if (x > s.top()) {//  stack.
                s.push(x); // Элемент в начало списка
            }
        }
    }
    cout << s.size() << endl; // 
    return 0;
}
