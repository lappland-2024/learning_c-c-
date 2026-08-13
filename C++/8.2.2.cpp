//8.7
#include <iostream>
#include <fstream>
#include <string>
struct Sales_data {
    std::string bookNo;       // 书籍 ISBN
    unsigned units_sold = 0;  // 售出数量
    double revenue = 0.0;     // 销售收入

    std::string isbn() const { return bookNo; }
    
    Sales_data& combine(const Sales_data& rhs) {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }
};

// 输入运算符重载：用于从流中读取数据
std::istream& operator>>(std::istream& is, Sales_data& item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is) {
        item.revenue = price * item.units_sold;
    } 
    else {
        item = Sales_data(); // 输入失败则重置对象，确保输入失败产生的“脏”数据不会影响后续操作，防御性编程
    }
    return is;
}

// 输出运算符重载：用于打印结果
std::ostream& operator<<(std::ostream& os, const Sales_data& item) {
    os << item.isbn() << " 共售出：" << item.units_sold << "本。 总价：" << item.revenue;
    return os;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {//共两个命令行参数，一个是程序名，一个是文件名，最后是输出文件名
        std::cerr << "Usage: " << argv[0] << " <filename> <output_filename>" << std::endl;
        return -1;
    }

    // 打开文件
    std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return -1;
    }

    // 打开输出文件 8.8使用app模式打开
    std::ofstream output(argv[2], std::ios::app);
    if (!output) {
        std::cerr << "Error: Could not open output file " << argv[2] << std::endl;
        return -1;
    }

    Sales_data total;      // 保存当前求和结果的变量
    Sales_data trans;      // 保存下一条交易数据的变量
    //注意：数据有一个前提是相同的isbn号的交易记录是连续的，如果不连续，可以使用sort算法对数据进行排序，或者使用map容器来存储每个isbn号的交易记录。
    // 1. 读取第一笔交易
    if (input >> total) {
        // 2. 读取剩余交易
        while (input >> trans) {
            // 检查 ISBN 是否相同
            if (total.isbn() == trans.isbn()) {
                total.combine(trans); // 更新求和结果
            }
            else {
                // 输出上一本书的结果
                std::cout << total << std::endl; 
                output << total << std::endl; // 将结果写入输出文件
                total = trans; // 处理下一本书
            }
        }
        // 3. 输出最后一条交易记录
        std::cout << total << std::endl;
        output << total << std::endl; // 将结果写入输出文件
    } 
    else {
        // 没有输入任何信息
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}