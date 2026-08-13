//8.13
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct PeopleInfo {
    string name;
    vector<string> phones;
};

bool valid(const string &s) {
    /*省略*/
    return true;
}

string format(const string &s) {
    /*省略*/
    return s;
}

int main() {
    ifstream input("8.3.2numbers.txt");
    if (!input) {
        cerr << "Error: Could not open file 8.3.2numbers.txt" << endl;
        return -1;
    }

    vector<PeopleInfo> people;
    string line;

    while(getline(input, line)) {
        PeopleInfo person;
        istringstream line_record(line);
        line_record >> person.name;
        string phone;
        while(line_record >> phone) {
            person.phones.push_back(phone);
        }
        people.push_back(person);
    }
    
    for (const auto &entry : people) {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            if (valid(nums)) {
                formatted << " " << format(nums);
            }
            else {
                badNums << " " << nums;
            }
        }
        if (badNums.str().empty()) {
            cout << entry.name << " has valid numbers:" << formatted.str() << endl;
        }
        else {
            cout << entry.name << " has invalid numbers:" << badNums.str() << endl;
        }
    }
    return 0;
}