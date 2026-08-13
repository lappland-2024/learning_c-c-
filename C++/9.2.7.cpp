// //9.15
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     vector<int> vec{1,2,3,4,54,5,6,6,90,67,8,9,10};
//     vector<int> vec1{1,2,3,4,54,5,6,6,91,67,8,9,10};
//     if(vec == vec1) {
//         cout << "vec and vec1 are equal" << endl;
//     } 
//     else 
//         cout << "vec and vec1 are not equal" << endl;
//     return 0;
// }

//9.16
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    vector<int> vec{1,2,3,4,54,5,6,6,90,67,8,9,10};
    list<int> list{1,2,3,4,54,5,6,6,91,67,8,9,10};
    vector<int> vec1(list.begin(), list.end());
    if(vec == vec1) {
        cout << "vec and vec1 are equal" << endl;
    } 
    else 
        cout << "vec and vec1 are not equal" << endl;
    return 0;
}