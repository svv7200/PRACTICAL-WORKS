#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define MAX_TREE_HT 256
using namespace std;

map<char, string> codes;
map<char, int> freq;

struct MinHeapNode{
    char data;     // Символ ввода
    int freq;      // Частота
    MinHeapNode* left, * right; // Левый и правый
    MinHeapNode(char data, int freq){
        left = right = NULL;

        this->data = data;
        this->freq = freq;
    }
};
// Функция для очереди приоритетов

struct compare{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};
// утилита для печати символов вместе с
// есть значение Хаффмана
void printCodes(struct MinHeapNode* root, string str){
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
// утилита для хранения символов вместе с
// есть значение Хаффмана в хеш-таблице
void storeCodes(struct MinHeapNode* root, string str){
    if (root == NULL)
        return;
    if (root->data != '$')
        codes[root->data] = str;
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}

// Очередь приоритетов STL для хранения дерева кучи  к значению корневого узла кучи
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

// функция для построения дерева Хаффмана и его сохранения в minHeap
void HuffmanCodes(int size){
    struct MinHeapNode* left, * right, * top;
    for (map<char, int>::iterator v = freq.begin(); v != freq.end(); v++)
        minHeap.push(new MinHeapNode(v->first, v->second));
    while (minHeap.size() != 1){
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    storeCodes(minHeap.top(), "");
}
// утилита для сохранения карты каждого символа с его частота во входной строке
void calcFreq(string str, int n){
    for (int i = 0; i < str.size(); i++)
        freq[str[i]]++;
}
/** функция перебирает кодированную строку s
    если s [i] == '1', то перейти к узлу-> вправо
    если s [i] == '0', то перейти в узел-> влево
    если конечный узел добавляет узел-> данные к нашей выходной строке **/
string decode_file(struct MinHeapNode* root, string s){
    setlocale(LC_ALL, "Rus");
    string ans = "";
    struct MinHeapNode* curr = root;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;
        // достиг конечного узла
        if (curr->left == NULL and curr->right == NULL)
        {
            ans += curr->data;
            curr = root;
        }
    }
    return ans + '\0';
}

int main(){
    setlocale(LC_ALL, "Rus");

    string str ;

    cout << "Введите вашу строку: ";
    cin >> str;

    string encodedString, decodedString;
    calcFreq(str, str.length());
    HuffmanCodes(str.length());

    cout << "encodedChar: \n";

    for (auto v = codes.begin(); v != codes.end(); v++)
        cout << v->first << ' ' << v->second << endl;
    for (auto i : str)
        encodedString += codes[i];

    cout << "\nencodedString:\n" << encodedString << endl;

    decodedString = decode_file(minHeap.top(), encodedString);

    cout << "\ndecodedString:\n" << decodedString << endl;

    return 0;
}