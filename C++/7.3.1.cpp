#include <iostream>
#include <string>
using namespace std;

class Screen {
public:
//类型定义 屏幕位置
    using pos = string::size_type;
//默认构造函数
    Screen() = default;
//构造函数
    Screen(pos wd, pos hg) : width(wd), hight(hg), contents(wd*hg, ' ') {};
    Screen(pos wd, pos hg, char c) : width(wd), hight(hg), contents(wd*hg, c) {};
//成员函数声明
    char get() const {return contents[cursor];}
    inline char get(pos wd, pos hg) const;
    Screen& set(char c);
    Screen& set(pos row, pos col, char c);
    Screen& move(pos wd, pos hg) {cursor = wd*hg; return *this;}
    Screen& display(ostream& os) {do_display(os); return *this;}
    const Screen& display(ostream& os) const {do_display(os); return *this;};
private:
    pos cursor = 0;
    pos width = 0;
    pos hight = 0;
    string contents;
    void do_display(ostream& os) const {os << contents;};
};
//类外定义成员函数
inline Screen& Screen::set(char c){
    contents[cursor] = c;
    return *this;
}
inline Screen& Screen::set(pos row, pos col, char c){
    contents[row*width + col] = c;
    return *this;
}


int main() {
    return 0;
}