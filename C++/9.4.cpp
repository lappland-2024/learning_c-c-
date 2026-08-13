//9.38
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> v(24, 1);
    cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;
    v.push_back(1);
    cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;
    for (int id = 0; id <= 23; ++id) {
        v.push_back(1);
    }
    cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;
    return 0;
}