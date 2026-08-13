#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

int main() {
    list <const char*> L = {"hello", "world", "this", "is", "a", "test"};
    vector <string> V;
    V.assign(L.begin(), L.end());
    for (const auto& s : V) {
        cout << s << " ";
    }
    return 0;
}