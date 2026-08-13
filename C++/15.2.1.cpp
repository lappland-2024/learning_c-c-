#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Quote {//基类
public:
    //构造函数
    Quote() = default;
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) { } 

    string isbn() const { return bookNo; }

    virtual double net_price (size_t n) const { return n * price; }

    virtual void debug(ostream &os) const {
        os << "bookNo: " << bookNo << " price: " << price << endl;
    }
    //基类一般都需要一个虚析构函数，以确保派生类对象被正确销毁，即使没有实际动作
    virtual ~Quote() = default;

    virtual double print_total(ostream &os, const Quote &item, size_t n) {
        double ret = item.net_price(n);
        os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
        return ret;
    }

private:
    string bookNo;

protected:
    double price;
};

// class Bulk_quote final : public Quote {//最终派生类
// public:
//     Bulk_quote() = default;
//     Bulk_quote(const string &book, double p, size_t qty, double disc)
//                  : Quote(book, p), max_qty(qty),  discount(disc) { }//先调用基类构造函数，再初始化派生类新的成员

//     double net_price (size_t n) const override {//折扣策略15.7，数量以下的商品享受折扣
//         if (n >= max_qty) {
//             return max_qty * discount * price + (n - max_qty) * price;
//         }else
//             return n * discount * price;
//     }

//     void debug(ostream &os) const override {
//         os << "bookNo: " << isbn() << " price: " << price << " max_qty: " << max_qty << " discount: " << discount << endl;
//     }

// private:
//     size_t max_qty = 0;//适用折扣政策的购买量
//     double discount = 0.0;//折扣系数
// };

// int main() {
//     ostringstream os;
//     Bulk_quote test("test", 10.0, 2, 0.5);
//     test.print_total(os, test, 10);
//     cout << os.str() << endl;
//     test.debug(cout);

//     return 0;
// }

//15.4
class  Disc_quote : public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double price, size_t qty, double disc) 
                : Quote(book, price), quantity(qty), discount(disc) { }

    double net_price(size_t n) const override = 0;//纯虚函数，在后续派生类中实现，这里仅声明，如需定义必须在类外

protected:
    size_t quantity;
    double discount;

};

class Bulk_quote final : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double price, size_t qty, double disc) : Disc_quote(book, price , qty, disc) { }

    double net_price(size_t n) const override {
        if (n >= quantity) {
            return (n-quantity) * discount * price + quantity * price;
        } else {
            return n * price;
        }
    }
};

int main() {
    Bulk_quote bulk("test", 10.0, 2, 0.5);
    cout << "Total price for 10 items: " << bulk.net_price(10) << endl;
    // Disc_quote test;
    return 0;
}