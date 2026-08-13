#include <iostream>
#include <string>
#include <set>
class Message {
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
public:
    //folders被隐式初始化为空集合
    explicit Message(const std::string &str = "") 
    : contents(str) {}
    //拷贝控制成员，用来管理指向本Message的指针
    Message(const Message &m) : contents(m.contents), folders(m.folders) {
        add_to_Folders(m);//将本信息添加到指向m的Folder中
    };
    Message &operator=(const Message &rhs) {
        remove_from_Folders();
        contents = rhs.contents;
        folders = rhs.folders;
        add_to_Folders(rhs);
        return *this;
    };
    ~Message() {
        remove_from_Folders();
    }
    //从给定Folders集合中添加/删除本Message
    void save(Folder&);
    void remove(Folder&);
    
private:
    std::string contents;
    std::set<Folder*> folders;
    //拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
    //将本Message添加到指向参数的Folder中
    void add_to_Folders(const Message&);
    //从folders中的每个Folder中删除本Message
    void remove_from_Folders();
};

void Message::save(Folder &f){
    folders.insert(&f);
    f.addMsg(this);
}
void Message::remove(Folder &f){
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m){
    for(auto f : m.folders)
        f->addMsg(this);
}
void Message::remove_from_Folders() {
    for(auto f : folders)
        f->remMsg(this);
}

//专用swap函数
void swap(Message &lhs, Message &rhs){
    using std::swap;//在本例中严格来说并不需要，但这是一个好习惯
    //将每个信息的指针从它（原来）所在的Folder中删除
    for(auto f : lhs.folders)
        f->remMsg(&lhs);
    for(auto f : rhs.folders)
        f->remMsg(&rhs);
    //交换contents和Folder指针set
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    //将每个Message的指针添加到它的（新）Folder中
    for(auto f : lhs.folders)
        f->addMsg(&lhs);
    for(auto f : rhs.folders)
        f->addMsg(&rhs);
}

class Folder {
public:
    addMsg(){}
    remMsg(){}
private:
    std::set<Message*> messages;
};