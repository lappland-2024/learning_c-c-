//9.47
// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
//     string str = "ab2c3d7R4E6";
//     string numbers = "0123456789";
//     string character = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     string::size_type pos = 0;
//     while ((pos = str.find_first_of(numbers, pos)) != string::npos) {
//         cout << "Find number " << str[pos] << " at index " << pos << endl;
//         ++pos;
//     }
//     pos = 0;
//     while ((pos = str.find_first_of(character, pos)) != string::npos) {
//         cout << "Find character " << str[pos] << " at index " << pos << endl;
//         ++pos;
//     }
//     cout << endl;
//     pos = 0;
//     while ((pos = str.find_first_not_of(numbers, pos)) != string::npos) {
//         cout << "Find character " << str[pos] << " at index " << pos << endl;
//         ++pos;
//     }
//     return 0;
// }

//9.48
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main() {
    std::string ifile = "9.5.3words.txt";
    std::string ascender = "bdfhijklt";
    std::string decender = "gjpquy";
    std::string current_word;
    std::string current_longest;
    std::ifstream input(ifile);

    if (!input) {
        std::cerr << "Error: Could not open file " << ifile << std::endl;
        return -1;
    }

    while(input >> current_word) {
        if ((current_word.find_first_of(ascender) == std::string::npos) && (current_word.find_first_of(decender) == std::string::npos)) {
            if (current_word.length() > current_longest.length()) {
                current_longest = current_word;
            }
        }
    }
    std::cout << "result is " << current_longest << std::endl;
    return 0;
}
