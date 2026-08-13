//13.13
#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct X {
    X() {cout << "X()" << endl;}
    X(const X&) {cout << "X(const X&)" << endl;}
    X &operator=(const X &rhs) {cout << "operator=(const rhs&)" << endl; return *this;}
    ~X() {cout << "~X()" << endl;}
};

int main() {
X myx;
// X otherx(myx);
// X another;
// another = myx;
// X *p = new X(myx);
// delete p; 
vector<X>vecX{myx};
vecX.push_back(myx);
cout << vecX.size() << endl;
cout << "end of main" << endl;
return 0;
}