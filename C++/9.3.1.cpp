//9.18
#include <iostream>
#include <string>
#include <deque>
#include <list>
using namespace std;

// int main() {
//     string words;    
//     deque<string> deq;
//     while (cin >> words) {
//         deq.push_front(words);
//     }
//     for (deque<string>::iterator iter = deq.begin(); iter != deq.end(); ++iter) {
//         cout << *iter << " ";
//     }
//     cout << endl;
//     return 0;
// }

//9.19
// int main() {
//     string words;    
//     list<string> li;
//     while (cin >> words) {
//         li.push_front(words);
//     }
//     for (list<string>::iterator iter = li.begin(); iter != li.end(); ++iter) {
//         cout << *iter << " ";
//     }
//     cout << endl;
//     return 0;
// }

//9.20
int main() {
    list<int> li = {1,23,412,54,15,135,1};
    deque<int> deq1;
    deque<int> deq2;
    for (const auto &deq : li) {
        if (deq % 2 == 0) {
            deq1.push_back(deq);
        }
        else    
            deq2.push_back(deq);
    }
    cout << "list中的偶数为：" << " ";
    for (const auto &deq : deq1) {
        cout << deq << " ";
    }
    cout << endl;
    cout << "list中的奇数为：" << " ";
    for (const auto &deq : deq2) {
        cout << deq << " ";
    }
    return 0;
}