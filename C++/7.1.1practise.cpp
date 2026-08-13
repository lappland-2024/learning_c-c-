#include <iostream>
#include <string>
#include <vector>
#include <cctype>

// 练习 7.2：定义 Sales_data 类
struct Sales_data {
    std::string bookNo;          // 书籍ISBN
    unsigned units_sold = 0;     // 售出数量
    double revenue = 0.0;        // 销售收入

    // 返回 ISBN 号
    std::string isbn() const { return bookNo; }

    // 将另一个 Sales_data 对象合并到当前对象
    Sales_data& combine(const Sales_data& rhs) {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this; 
    }
};

int main() {
    // 练习 7.3：交易处理程序
    Sales_data total;
    double totalPrice;

    // 读取第一笔交易
    if (std::cin >> total.bookNo >> total.units_sold >> totalPrice) {
        total.revenue = total.units_sold * totalPrice;

        Sales_data trans;
        double transPrice;

        // 循环读取剩余交易
        while (std::cin >> trans.bookNo >> trans.units_sold >> transPrice) {
            trans.revenue = trans.units_sold * transPrice;

            // 使用 isbn 成员进行比较
            if (total.isbn() == trans.isbn()) {
                total.combine(trans); // 使用 combine 成员进行合并
            } else {
                std::cout << total.bookNo << " " << total.units_sold << " " 
                          << total.revenue << std::endl;
                total = trans; // 处理下一本书
            }
        }
        // 输出最后一本书的统计信息
        std::cout << total.bookNo << " " << total.units_sold << " " 
                  << total.revenue << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
    }

    return 0;
}