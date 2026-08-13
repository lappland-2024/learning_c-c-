#include <iostream>
#include <stack>
#include <string>
#include <cctype> // 用于 isdigit
#include <sstream> // 用于将字符串转为整数
#include <deque>

using namespace std;

int main() {
    string expr = "( 2 + 3 ) * ( 4 + 5 - 6 )"; // 示例表达式
    stack <string> sta;
    istringstream iss(expr);
    string str;
    deque <string> result;
    while (iss >> str) {
        if (str == "(") {
            sta.push(str);
        }
        else if (str == ")") {
            int temp;
            string value;
            string topitem;
            string ritem;
            string litem;
            string op;
            while (sta.top() != "(") {
                topitem = sta.top();
                sta.pop();
                if (topitem != "+" && topitem != "-" && ritem.empty()) {//可以用isdigit()代替前面的部分
                    ritem = topitem;
                }
                else if (topitem == "+" || topitem == "-") {
                    op = topitem;
                }
                else if (topitem != "+" && topitem != "-" && !ritem.empty()) {
                    litem = topitem;
                    if (op == "+") {
                        temp = stoi(litem) + stoi(ritem);
                        ritem = to_string(temp);//!!!注意ritem是string格式的
                        litem.clear();
                    }
                    else if (op == "-") {
                        temp = stoi(litem) - stoi(ritem);
                        ritem = to_string(temp);
                        litem.clear();
                    }
                }
            }
            value = ritem;
            ritem.clear();
            sta.pop();//弹出左括号
            sta.push(value);//压入替换后的数字字符
        }
        else {
            sta.push(str);//压入普通字符
        }
    }
    //输出结果
    while (!sta.empty()) {
        result.push_front(sta.top());
        sta.pop();
    }
    for (const auto &p : result) {
        cout << p;
    }
    cout << endl;

    // cout << "栈中剩余内容: ";
    // stack<string> tmp = sta;
    // while (!tmp.empty()) {
    //     cout << tmp.top();
    //     tmp.pop();
    // }
    // cout << endl;
    return 0;
}