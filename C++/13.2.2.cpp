#include <iostream>
#include <string>
using namespace std;
/*13.27
class HasPtr {
public:
    // 构造函数 分配新的 string 和新的计数器，计数器初始化为 1
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
    // 拷贝构造函数 拷贝所有成员，并将计数器递增
    HasPtr(const HasPtr &p) 
        : ps(p.ps), i(p.i), use(p.use) { 
        ++*use; 
    }
    // 拷贝赋值运算符
    HasPtr& operator=(const HasPtr &rhs) {
        // 关键技巧：先递增 rhs 的计数器，这样可以处理自赋值情况（rhs 和 this 是同一个对象）递增后
        // 即使后面 delete 了左侧的旧资源，rhs 的计数依然是安全的
        ++*rhs.use; 
        // 然后递减左侧对象（this）的计数器
        if (--*use == 0) {
            delete ps;   // 如果没有人再用旧的 string 了，释放它
            delete use;  // 释放旧计数器
        }
        // 最后，将数据从 rhs 拷贝到本对象
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }
    // 析构函数
    ~HasPtr() {
        // 递减引用计数
        if (--*use == 0) {
            delete ps;   // 如果计数器归零，说明没人用这个 string 了，释放内存
            delete use;  // 同时释放计数器本身占用的内存
        }
    }
private:
    std::string *ps;
    int i;
    std::size_t *use; // 引用计数指针
};*/

//13.28(a)
class TreeNode {
public:
    //默认构造函数
    TreeNode() : value(""), count(0), left(nullptr), right(nullptr) {}
    //拷贝构造函数
    TreeNode(const TreeNode &orig)
            : value(orig.value), count(orig.count), 
            //递归调用构造函数，复制全部子树
            left(orig.left ? new TreeNode(*orig.left) : nullptr), 
            right(orig.right ? new TreeNode(*orig.right) : nullptr) {}
    //拷贝赋值运算符
    TreeNode &operator=(const TreeNode &rhs) {
        if(this != &rhs){//自赋值检查
            //分配新资源
            auto new_left = (rhs.left ? new TreeNode(*rhs.left) : nullptr);
            auto new_right = (rhs.right ? new TreeNode(*rhs.right) : nullptr);
            //释放旧资源
            delete left;
            delete right;
            
            left = new_left;
            right = new_right;
            value = rhs.value;
            count = rhs.count;
        }
        return *this;
    }
    //析构函数
    ~TreeNode() {
        delete left;//delete后跟指针，调用指针所指对象的析构函数，这里形成递归直到清空所有子树
        delete right;
    }

private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};
//13.28(b)
class BinStrTree {
public:
    BinStrTree() : root(nullptr) {}
    BinStrTree(const BinStrTree &orig) : root(orig.root) {}
    BinStrTree &operator=(const BinStrTree &rhs) {
        if(this != &rhs)
            root = rhs.root;
        return *this;
    }
    ~BinStrTree(){}//析构函数留空仅做示意，需要确定仅有一个BinStrTree指向root时，才能delete
private:
    TreeNode *root;//定义为std::shared_ptr<TreeNode>自动处理生命周期，避免手动delete导致重复释放
};