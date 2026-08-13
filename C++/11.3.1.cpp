#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    map<string, int> word_count;
    word_count["yuansu"] = 1;
    auto map_it = word_count.find("yuansu");
    if (map_it != word_count.end()) {
        map_it->second = 100;
        cout << "修改后的值为：" << map_it->second << endl;
    }
    return 0;
}
