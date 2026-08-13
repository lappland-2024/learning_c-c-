#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<char> vec("a", "b");
    string save;
    for (const auto &temp : vec) {
        save.push_back(temp);
    }

    string str (save);
    for (const auto &t : str) {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}
