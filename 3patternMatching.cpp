//Pattern matching - Brute Force Approach
#include <iostream>
#include <string>
using namespace std;

bool match(const std::string& text, const std::string& pattern) {
    for (int i = 0; i < text.size(); i++) {
        for (int j = 0; j < pattern.size(); j++) {
            if (text[i+j] != pattern[j]) {
                break;
            }
            if (j == pattern.size() - 1) {
                cout<<"At index " << i;
                return true;
            }
        }
    }
    return false;
}

int main() {
    string text = "abcdefg";
    string pattern = "cd";
    if (match(text, pattern)) {
        cout << " pattern is found in text" << endl;
    } else {
        cout << " pattern iis not found in text" << endl;
    }
    return 0;
}
