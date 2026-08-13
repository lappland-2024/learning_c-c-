//9.27
#include <iostream>
#include <forward_list>

using namespace std;

// int main() {
//     forward_list<int> fli = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
//     auto cur = fli.begin();
//     auto pre = fli.before_begin();
//     while(cur != fli.end()) {
//         if(*cur%2) {
//             cur = fli.erase_after(pre);
//             continue;
//         }
//     pre = cur;
//     ++cur;
//     }
//     for(const auto &temp : fli) {
//         cout << temp << " ";
//     }
//     cout << endl;
//     return 0;
// }

//9.28

int main() {
    void find_insert(forward_list<string> fli, string str1, string str2);
    forward_list<string> fdli = {"find", "a", "place", "to", "insert."};
    forward_list<string> fdli1 = {" a", "place", "to", "insert."};
    string stra {"find"};
    string strb {"insert"};
    find_insert(fdli1, stra, strb);
    
    return 0;
}

void find_insert(forward_list<string> fli, string str1, string str2) {
    auto cur = fli.begin();
    auto prev = fli.before_begin();
    while(cur != fli.end()) {
        if(*cur == str1) {
            fli.insert_after(prev, str2);
            break;
        }
    prev = cur;
    ++cur;
    }
    cout << "Result after insert: " ;
    for(const auto &temp : fli) {
        cout << temp << " ";
    }
    cout << endl;
}