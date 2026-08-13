//9.31
// #include <iostream>
// #include <vector>
// #include <string>
// #include <list>
// #include <forward_list>
// using namespace std;

// int main() {
//     list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     auto cur = fli.begin();
//     auto prev = fli.before_begin();
//     while(cur != fli.end()) {
//         if(*cur%2) {//奇数
//             cur = fli.insert_after(prev, *cur);
//             ++cur; ++cur;
//             ++prev;++prev;
//             continue;
//         }
//         else {
//             cur = fli.erase_after(prev);
//         }
//     }
//     for (const auto &temp : fli) {
//         cout << temp << " ";
//     }
//     cout << endl;
//     return 0;
// }

//9.34
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vec.begin();
    while (iter != vec.end()){
        if (*iter % 2)
            iter = vec.insert(iter, *iter);
            cout << *iter << endl;
        ++iter;//死循环，应该+2
    }

    return 0;
}