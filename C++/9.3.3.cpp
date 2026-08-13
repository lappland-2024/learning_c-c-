//9.26
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int ia [] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vec;
    list<int> li;
    for(const auto &temp : ia) {
        vec.push_back(temp);
        li.push_back(temp);
    }
    //显示初始状态
    for (const auto &temp : vec) {
        cout << temp << " ";
    }
    cout << endl;
    for (const auto &temp : li) {
        cout << temp << " ";
    }
    cout << endl;

    auto iter1 = vec.begin();
    auto iter2 = li.begin();
    while(iter1 != vec.end()) {
        if((*iter1)%2 == 0){
            iter1 = vec.erase(iter1);
            continue;
        }    
    ++iter1;
    }
    while(iter2 != li.end()) {
        if((*iter2)%2 != 0) {
            iter2 = li.erase(iter2);
            continue;
        }
    ++iter2;
    }
    //显示结果
    cout << "删除后vector中还有以下元素： ";  
    for (const auto &temp : vec) {
        cout << temp << " ";
    }
    cout << endl;
    cout << "删除后li中还有以下元素： ";  
    for (const auto &temp : li) {
        cout << temp << " ";
    }
    cout << endl;
    return 0;
}