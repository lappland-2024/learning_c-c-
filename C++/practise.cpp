#include <iostream>
using namespace std;

class abc {
    int a ;
    static int b ;
    const int c;
    int &d = b;
};
class abc :: int a = 10;
std :: cout << a;