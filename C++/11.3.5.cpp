//11.28
// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;
// int main() {
//     vector<int> vec = {1, 2};
//     map<string, vector<int>> mymap = {{"1", vec}};
//     auto findstr = mymap.find("1");
//     auto findstr2 = mymap.find("2");
//     cout << findstr->first << endl;
// }

//11.31
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    multimap<string, string> authors = {
        {"A", {"Book1"}},
        {"B", {"Book3"}},
        {"A", {"Book2"}}
    };
    string author;
    while(cin >> author){
        if (author == "q") {
            break;
        }
        if(authors.find(author) != authors.end()){
            cout << author << " has " << authors.erase(author) << " books been removed." << endl;
        }
        else
            cout << author << " not found." << endl;
        cout << "Current authors: " << endl;//11.32
        for (const auto& a : authors) {
            cout << a.first << " : " << a.second << endl;
        }
        cout << "-------------------------" << endl;
        cout << "Enter an author to remove (or type 'q' to quit): ";
    }
    return 0;
}