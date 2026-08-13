//13.18
#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
//默认构造和输入姓名构造,名字默认为空字符串“”
Employee() : name(""), ID(++form_ID) { }
Employee(const string &na) : name(na), ID(++form_ID) { }
Employee(const Employee &em) : name(em.name), ID(++form_ID) { }
Employee& operator=(const Employee &rhs);
//成员类型决定这个类不需要手动设定析构函数，--form_ID会导致ID重复，应删除
// ~Employee() { --form_ID; }
//获取姓名和ID
string get_name() const { return name; }
int get_ID() const { return ID; }

private:
static int form_ID;
string name;
int ID;
};

int Employee::form_ID = 0;
Employee& Employee::operator=(const Employee &rhs){//注意避免自赋值导致ID自加，添加if语句
    if(this != &rhs){
    name = rhs.name;
    ID = ++form_ID;}
    return *this;
};

int main() {
Employee em1;
cout << em1.get_ID() << endl;
cout << em1.get_name() << endl;
Employee em2("em2");
cout << em2.get_ID() << endl;
cout << em2.get_name() << endl;
Employee em3(em2);
cout << em3.get_ID() << endl;
cout << em3.get_name() << endl;
Employee em4;
em4 = em2;
cout << em4.get_ID() << endl;
cout << em4.get_name() << endl;
return 0;
}

