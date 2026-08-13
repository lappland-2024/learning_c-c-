//13.30
#include <iostream>
#include <string>

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    
    // 拷贝构造函数
    HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) {
        std::cout << "Calling Copy Constructor." << std::endl;
    }
    
    // 析构函数
    ~HasPtr() {
        delete ps;
    }

private:
    std::string *ps;
    int i;
};

// 自定义 swap 函数
inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    // 打印提示信息
    std::cout << "Custom swap function is executing!" << std::endl;
    
    swap(lhs.ps, rhs.ps); // 交换指针
    swap(lhs.i, rhs.i);   // 交换 int
}

int main() {
    HasPtr s1("Hello");
    HasPtr s2("World");
    
    std::cout << "Before swap:" << std::endl;
    // 这里无法直接看私有成员，但可以通过其他方式验证
    
    swap(s1, s2); // 调用自定义 swap
    
    std::cout << "After swap:" << std::endl;
    return 0;
}
//13.31
#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <string>

// 假设 HasPtr 定义如上题，且包含了 friend void swap...
class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr& lhs, const HasPtr& rhs); // 声明 < 运算符
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) {}
    ~HasPtr() { delete ps; }
    
    // 为了方便查看排序结果，重载 << （可选）
    friend std::ostream& operator<<(std::ostream& os, const HasPtr& hp) {
        os << *hp.ps;
        return os;
    }

private:
    std::string *ps;
    int i;
};

// 定义 < 运算符：按字符串字典序比较
bool operator<(const HasPtr& lhs, const HasPtr& rhs) {
    return *lhs.ps < *rhs.ps;
}

// 定义 swap
inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    std::cout << "Swapping: " << *lhs.ps << " and " << *rhs.ps << std::endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main() {
    std::vector<HasPtr> vec;
    vec.push_back(HasPtr("Banana"));
    vec.push_back(HasPtr("Apple"));
    vec.push_back(HasPtr("Cherry"));

    std::cout << "Before sorting:" << std::endl;
    for (const auto& s : vec) std::cout << s << " ";
    std::cout << std::endl;

    // sort 算法在排序过程中需要交换元素位置
    // 如果我们没有定义 HasPtr 的 swap，sort 会使用 std::swap，导致深拷贝
    // 因为我们定义了，所以 sort 会调用我们的自定义 swap
    std::sort(vec.begin(), vec.end());

    std::cout << "After sorting:" << std::endl;
    for (const auto& s : vec) std::cout << s << " ";
    std::cout << std::endl;

    return 0;
}