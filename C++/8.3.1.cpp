//8.9
// #include <iostream>
// #include <sstream>
// using namespace std;

// int main() {
//     istringstream iss("Hello World");
//     istream& func(istream& is);
//     func(iss);
//     return 0;
// }

// istream& func(istream& is) {
//     string word;
//     while(is >> word){
//         cout << word << endl;
//     }
//     is.clear();
//     return is;
// }

//8.10
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>
// #include <sstream>
// using namespace std;
// int main() {
//     vector<string> readfilebyline(const string &filename);
//     vector<string> lines = readfilebyline("example.txt");
//     for(const auto &line : lines) {
//         istringstream iss(line);
//         if(!iss) {
//             cout << "Error creating istringstream for line: " << line << endl;
//             continue;
//         }
//         cout << "Words in line: ";
//         string word;
//         while(iss >> word) {
//             cout << word << endl;
//         }
//         cout << endl;
//     }
//     return 0;
// }
// vector<string> readfilebyline(const string &filename){
//     ifstream ifs(filename);
//     vector<string> str_vec;
//     string line;
//     if(ifs.is_open()){
//         while(getline(ifs, line)){
//             str_vec.push_back(line);
//         }
//     }
//     else{
//         cout << "Error opening file" << endl;
//     }
//     return str_vec;
// }

//8.11
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct PersonInfo {
    string name;
    vector<string> phones;
};

int main() {
    string line, word;
    vector<PersonInfo> people;
    istringstream record(line);
    while (getline(cin, line)) {
        PersonInfo info;
        record.clear();//先清空istringstream的状态，恢复为goodbit
        record.str(line);//再将新的line赋值给istringstream
        record >> info.name;
        while(record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    for (const auto &entry : people) {
        cout << entry.name << " ";
        for (const auto &phone : entry.phones)
            cout << phone << " ";
        cout << endl;
    }
    return 0;
}