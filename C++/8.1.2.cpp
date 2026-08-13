#include <iostream>
using namespace std;
int main() {
    istream& func(istream& is);
    func(cin);
    return 0;
}
istream& func(istream& is) {
    char ch;
    while(is >> ch){
        cout << ch << endl;
    }
    is.clear();
    return is;
}