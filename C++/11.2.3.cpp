// #include <iostream>
// #include <vector>    
// #include <string>
// #include <utility>
// using namespace std;

// int main() {
//     int v1 = 1, v2 = 2;
//     auto p = make_pair(v1, v2);
//     int v3 = 3, v4 = 4;
//     auto p2 = make_pair(v3, v4);
//     bool b = p > p2; // 使用 relop(<、>、<=、>=) 比较两个 pair 对象
//     pair<int, int> p3 = p; // 使用拷贝构造函数创建一个新的 pair 对象
// }
//11.12
/*int main () {
    vector<pair<string, int>> vec;
    string str;
    int i;
    cout << "输入字符串和整数，输入 q 结束：" << endl;
    while (cin >> str >> i) {
        if (str == "q") 
            break;
        // vec.push_back(make_pair(str, i));//第一种使用make_pair()
        // vec.push_back(pair<string, int>(str, i));//第二种使用pair构造函数
        vec.push_back({str, i});//第三种使用列表初始化，最简洁直观
    }
    for (const auto &p : vec){
        cout << p.first << " " << p.second << endl;
    }
}*/

//11.14
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    map<string, vector<pair<string, int>>> family;
    family["huang"] = {{"huang1", 326}, {"huang2", 212}, {"huang3", 313}};
    family["huang"].push_back({"huang4", 423});
    family["li"] = {{"li1", 111}, {"li2", 216}, {"li3", 308}};
    for (const auto &f : family) {
        cout << f.first << " has " << f.second.size() << " members." << endl;
            for (const auto &m : f.second)
                cout << m.first << " (" << m.second << ") ";
        cout << endl;
    }
    return 0;
}
