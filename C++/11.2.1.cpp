//11.7
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// int main() {
//     map<string, vector<string>> family;
//     family["huang"] = {"huang1", "huang2", "huang3"};
//     family["huang"].push_back("huang4");
//     family["li"] = {"li1", "li2", "li3"};
//     for (const auto &f : family) {
//         cout << f.first << " has " << f.second.size() << " members." << endl;
//             for (const auto &m : f.second)
//                 cout << m << " ";
//         cout << endl;
//     }
//     return 0;
// }
//11.8
int main() {
    vector<string> unmutied_words;
    string word;
    while(cin >> word)
        if (find(unmutied_words.begin(), unmutied_words.end(), word) == unmutied_words.end())
            unmutied_words.push_back(word);
    for (const auto &w : unmutied_words)
        cout << w << " ";
    cout << endl;
    return 0;
}
