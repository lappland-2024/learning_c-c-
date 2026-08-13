//9.43
#include <iostream>
#include <string>

// void replace_all(std::string &s, const std::string &oldVal, const std::string &newVal) {
//     if (oldVal.empty()) return;
    
//     auto it = s.begin();
//     while (it != s.end()) {
//         // 手动查找oldVal的起始位置
//         auto match_it = it;
//         auto old_it = oldVal.begin();
//         bool found = true;
        
//         // 逐个字符比较，检查是否匹配oldVal
//         while (match_it != s.end() && old_it != oldVal.end()) {
//             if (*match_it != *old_it) {
//                 found = false;
//                 break;
//             }
//             ++match_it;
//             ++old_it;
//         }
        
//         // 如果完全匹配oldVal
//         if (found && old_it == oldVal.end()) {
//             // 计算匹配的长度
//             size_t match_len = oldVal.size();
            
//             // 1. 删除找到的旧值
//             it = s.erase(it, it + match_len);
            
//             // 2. 在删除的位置插入新值
//             it = s.insert(it, newVal.begin(), newVal.end());
            
//             // 3. 更新迭代器，跳过刚插入的新值，继续向后查找
//             it += newVal.size();
//         } else {
//             // 不匹配，移动到下一个字符继续查找
//             ++it;
//         }
//     }
// }

// // int main() {
//     std::string test = "I tho tho tho in the through.";
//     std::cout << "Original: " << test << std::endl;
    
//     replace_all(test, "tho", "though");
//     std::cout << "Replaced: " << test << std::endl;
    
//     // 测试更多情况
//     std::string test2 = "aaaa";
//     replace_all(test2, "aa", "b");
//     std::cout << "Test2: " << test2 << std::endl;  // 应输出 "bb"
    
//     std::string test3 = "abcabcabc";
//     replace_all(test3, "abc", "x");
//     std::cout << "Test3: " << test3 << std::endl;  // 应输出 "xxx"
    
//     return 0;
// }

//9.44
// void replace_all (std::string &s, const std::string &oldval, const std::string &newval) {
//     if (oldval.empty()) return;

//     size_t spos = 0;
//     size_t opos = 0;
//     size_t npos = 0;
//     size_t leftspos = (s.size() - spos);
//     while (leftspos) {
//         while (s[spos] == oldval[opos]) {
//             ++spos; ++opos;
//             if (opos == (oldval.size()-1)) {
//                 // s.erase(spos - oldval.size(), oldval.size());//erase (n,t) 从下标n删去t个
//                 // spos -= oldval.size();//校准当前位置
//                 // s.insert(spos, newval);
//                 // spos += newval.size(); //插入后再次校准
//                 s.replace(spos - oldval.size(), oldval.size(), newval);
//                 spos = (spos - oldval.size() + newval.size());
//             }
//         }
//         opos = 0;//重置oldval下标
//         ++spos;
//     }
// }

// void replace_all(std::string &s, const std::string &oldval, const std::string &newval) {
//     if (oldval.empty()) return;
    
//     size_t pos = 0;
//     while ((pos = s.find(oldval, pos)) != std::string::npos) {
//         s.replace(pos, oldval.length(), newval);
//         pos += newval.length();  // 移动到替换后的位置
//     }
// }

// int main() {
//     std::string test = "I tho tho tho in the through.";
//     std::cout << "Original: " << test << std::endl;
//     replace_all(test, "tho", "though");
//     std::cout << "Replaced: " << test << std::endl;
//     return 0;
// }

//9.45
// std::string plus_prefixandsuffix (std::string name, const std::string& prefix, const std::string& suffix) {
//     name.insert(name.begin(), prefix.begin(), prefix.end());
//     name.append(suffix);
//     return name;
// }

// int main() {
//     auto plused_name = plus_prefixandsuffix ("jack", "Mr.", " baron");
//     std::cout << plused_name << std::endl;
//     return 0;
// }

//9.46
std::string plus_prefixandsuffix (std::string name, const std::string& prefix, const std::string& suffix) {
    name.insert(0, prefix);
    name.insert(name.length(), suffix);
    return name;
}
int main() {
    auto plused_name = plus_prefixandsuffix ("jack", "Mr.", " baron");
    std::cout << plused_name << std::endl;
    return 0;
}