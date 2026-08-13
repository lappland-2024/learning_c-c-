#include <iostream>
#include <string>
using namespace std;

class Debug{
public:
    constexpr Debug(bool t = true) : io(t), hw(t), other(t) { }
    constexpr Debug(bool a, bool b, bool c) : io(a), hw(b), other(c) { }

    constexpr bool any() const { return io || hw || other; }

    void set_io(bool s) { io = s; }
    void set_hw(bool s) { hw = s; }
    void set_other(bool s) { other = s; }

private:
    bool io;
    bool hw;
    bool other;
};

int main() {
    constexpr Debug allture (0,1,0);
    if (allture.any())
        cerr << "print appropriate error message." << endl;
    return 0;
}