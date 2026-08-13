#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    multimap<string, vector<string>> family;
    // family["huang"] = {"huang1", "huang2", "huang3"};[]只支持map和unordered_map
    // family["huang"].push_back("huang4");
    // family["li"] = {"li1", "li2", "li3"};
    family.insert({"huang", {"huang5", "huang6"}});
    family.insert({"li", {"li4", "li5"}});
    for (const auto &f : family) {
        cout << f.first << " has " << f.second.size() << " members." << endl;
            for (const auto &m : f.second)
                cout << m << " ";
        cout << endl;
    }
    return 0;
}