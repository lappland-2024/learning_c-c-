#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int main() {
    map<string, size_t> word_count;
    string word;
    while(cin >> word){
        string cleaned_word;
        string lower_word;
        //清楚标点符号并转换为小写
        for (const auto &n : word)
            if(!ispunct(n))
                cleaned_word += n;
        for (const auto &n : cleaned_word)
            lower_word += tolower(n);
        if(!lower_word.empty())//不统计空字符串
            ++word_count[lower_word];
    }
    for(const auto &w : word_count)
        cout << w.first << " has occoured " << w.second << ((w.second > 1) ? " times." : " time.") << endl;
    return 0;
}