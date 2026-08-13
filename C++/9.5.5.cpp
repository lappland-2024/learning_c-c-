//9.50
// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int main() {
//     int total;
//     double total1;
//     vector<string> numbers {"1.1","2","3","4","5","6","7","8","9","0","10","11","12","13","14","15","16","17","18","19","20"};
//     for (const auto &i : numbers) {
//         // total += stoi(i);
//         total1 += stof(i);
//     }
//     // cout << total << endl;
//     cout << total1 << endl;
//     return 0;
// }

//9.51
#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

map<string, unsigned long> months = {{"january", 1}, {"jan", 1}, {"februrary", 2}, {"feb", 2}, {"march", 3}, {"april", 4}, {"may", 5}, 
                                    {"june", 6}, {"july", 7}, {"august", 8}, {"aug", 8}, {"september", 9}, {"sep", 9}, {"october", 10}, 
                                    {"oct", 10}, {"november", 11}, {"nov", 11}, {"december", 12}, {"dec", 12}};
string numbers = "0123456789";

class calendar {
public:
    calendar (string aday) {
        size_t pos;
        string temp;
        for (char &p : aday) {
            p = tolower(p);
            cout << p;
        }
        cout << endl;
        for (const auto &p : months) {
            if ((pos = aday.find(p.first)) != string::npos) {
                calendar::month = p.second;
                pos = aday.find_first_of(numbers);
                temp = aday.substr(pos, 2);
                calendar::day = stoul(temp);
                temp = aday.substr(pos+2);
                pos = temp.find_first_of(numbers);
                temp = temp.substr(pos);
                calendar::year = stoul(temp);
                return;
            }
        }
        //默认数据格式有效
        
    }
    void show() {
        cout << "month: " << month << endl;
        cout << "day: " << day << endl;
        cout << "year: " << year << endl;
    }

private:
    unsigned long year;
    unsigned long month;
    unsigned long day;
};

int main() {
    calendar test("Feb 1 2000");
    test.show();
    return 0;
}