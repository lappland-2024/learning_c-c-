#include <iostream>
#include <string>
using namespace std;

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    
    // 拷贝构造函数
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) {
        cout << "Calling Copy Constructor." << endl;
    }
    
    // 析构函数
    ~HasPtr() {
        delete ps;
    }

private:
    string *ps;
    int i;
};

// 自定义 swap 函数
inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    // 打印提示信息
    cout << "Custom swap function is executing!" << endl;
    
    swap(lhs.ps, rhs.ps); // 交换指针
    swap(lhs.i, rhs.i);   // 交换 int
}

int main() {
    HasPtr s1("Hello");
    HasPtr s2("World");
    
    cout << "Before swap:" << endl;
    // 这里无法直接看私有成员，但可以通过其他方式验证
    
    swap(s1, s2); // 调用自定义 swap
    
    cout << "After swap:" << endl;
    return 0;
}