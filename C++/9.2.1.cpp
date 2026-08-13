//9.4
#include <iostream>
#include <vector>
using namespace std;
// int main() {
//     bool find(vector<int>::iterator iter1, vector<int>::iterator iter2, int value);
//     vector<int> vec{1,2,3,4,54,5,6,6,90,67,8,9,10};
//     bool funreturn = find(vec.begin(), vec.end(), 999);
//     cout << funreturn << endl;
//     return 0;
// }
// bool find(vector<int>::iterator iter1, vector<int>::iterator iter2, int value) {
//     while(iter1 != iter2) {
//         if(*iter1 == value) {
//             cout << "Value found" << endl;
//             return true;
//         }
//         else
//             ++iter1;
//     }
//     cout << "Value not found" << endl;
//     return false;
// }

//9.5
int main() {
    vector<int>::iterator find(vector<int>::iterator iter1, vector<int>::iterator iter2, int value);
    vector<int> vec{1,2,3,4,54,5,6,6,90,67,8,9,10};
    auto funreturn = find(vec.begin(), vec.end(), 9);
    cout << "Return value: " << *funreturn << endl;
    return 0;
}
//找到返回迭代器，没找到返回尾迭代器
vector<int>::iterator find(vector<int>::iterator iter1, vector<int>::iterator iter2, int value) {
    while(iter1 != iter2) {
        if(*iter1 == value) {
            cout << "Value found" << endl;
            return iter1;
        }
        else
            ++iter1;
    }
    cout << "Value not found" << endl;
    return iter2;
}