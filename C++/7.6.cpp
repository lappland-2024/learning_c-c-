#include <iostream>
#include <string>
using namespace std;

class Account {
public:
    Account(string own, double am) : owner(own), amount(am) { init_interestRate(); };//调用静态成员函数设置利率
    void calculate() { amount += amount * interestRate; };
    double get_rate() { return interestRate;};
    void set_rate(double newrate) { interestRate = newrate;}; 
    double show_amount() { return amount;}
private:
    string owner;
    double amount;
    static double interestRate;
    static void init_interestRate();
};
//类外定义并初始化 静态成员
double Account::interestRate = 0.0;
//类外定义 静态成员函数
void Account::init_interestRate() {
    interestRate = 0.1;
};

int main() {
    double myaccountamount = 100.5;
    Account myaccount("hzw", myaccountamount);
    cout << myaccount.get_rate() << endl;
    cout << myaccount.show_amount() << endl;
    myaccount.set_rate(0.2);
    myaccount.calculate();
    cout << myaccount.show_amount() << endl;
    return 0;
}