#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class person {
private:
    std::string name;
    std::string address;
public:
    std::string get_name(const person& p) {
        return p.name;
    }

    std::string get_address(const person& p) {
        return p.address;
    }
    
    person() = default;
    person(const std::string& n, const std::string& a) : name(n), address(a) {}

    istream& read(istream& is, person& p) {
        is >> p.name >> p.address;
        return is;
    }
};