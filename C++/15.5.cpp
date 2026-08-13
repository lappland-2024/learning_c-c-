//15.20
/*
#include <iostream>

class Base {
public:
    Base() = default;
    void pub_mem();
    void memfcn(Base &b) { b = *this; }
protected:
    int prot_mem;

private:
    char priv_mem;
};

struct Pub_Derv : public Base { void memfcn(Base &b) { b = *this; } };

struct Priv_Derv : private Base { void memfcn(Base &b) { b = *this; } };

struct Prot_Derv : protected Base { void memfcn(Base &b) { b = *this; } };

struct Derived_from_Public : public Pub_Derv { void memfcn(Base &b) { b = *this; } };

struct Derived_from_Private : public Priv_Derv { 
// void memfcn(Base &b) { b = *this; } 
};

struct Derived_from_Protected : public Prot_Derv { void memfcn(Base &b) { b = *this; } };

int main() {
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

//15.18
    std::cout << "--- Ex 15.18 ---" << std::endl;
    Base *p = nullptr;

    p = &d1; // 合法
    std::cout << "p = &d1; is legal." << std::endl;

    // p = &d2; // 取消注释会编译报错
    std::cout << "p = &d2; is illegal." << std::endl;

    // p = &d3; // 取消注释会编译报错
    std::cout << "p = &d3; is illegal." << std::endl;

    p = &dd1; // 合法
    std::cout << "p = &dd1; is legal." << std::endl;

    // p = &dd2; // 取消注释会编译报错
    std::cout << "p = &dd2; is illegal." << std::endl;

    // p = &dd3; // 取消注释会编译报错
    std::cout << "p = &dd3; is illegal." << std::endl;


//15.19
    Base b;
    d1.memfcn(b);
    d2.memfcn(b);
    d3.memfcn(b);
    dd1.memfcn(b);
    // dd2.memfcn(b); //成员函数中的b = *this; 中含有隐式类型转换（从Derived_from_Private到Base），
                    // 但因为Priv_Derv是私有继承，所以Derived_from_Private类型的用户没有权限访问Base
    dd3.memfcn(b);

    return 0;
}
*/
//15.22
#include <iostream>
#include <string>

using namespace std;

class GraphicBase {//抽象基类
public:
    GraphicBase() = default;
    GraphicBase(size_t dime) : dimension(dime) { }

    virtual size_t showdime() = 0;//+ =0 变纯虚函数

    virtual ~GraphicBase() = default;//继承关系中的根节点类记得+虚析构函数即使虚析构函数不做任何实际动作

protected:
    void prot_mem() { cout << "GraphicBase::prot_mem()" << endl; }
    size_t dimension;
};

class Circle : public GraphicBase {//圆形
public:
    Circle() = default;
    Circle(size_t dime, size_t r) : GraphicBase(dime), radius(r) { }

    size_t showdime() override { return dimension; }
    size_t showr() { return radius; }

protected:
    void prot_mem() { cout << "Circle::prot_mem()" << endl; }

private:
    size_t radius;
};

class Ball : public Circle {
public:
    Ball() = default;
    Ball(size_t dime, size_t r, bool fill) : Circle(dime, r), fillstate(fill) { };

    bool is_fill() { return fillstate; }

private:
    bool fillstate;
};

int main() {
    Ball myballs(3, 1, 1);
    cout << myballs.showdime() << endl;
    GraphicBase *basep;
    basep = &myballs;
    cout << basep -> showdime() << endl;
    return 0;
}