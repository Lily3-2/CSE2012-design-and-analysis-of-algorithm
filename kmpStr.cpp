//K M P algorithm
//The KMP algorithm is an abbreviated form of the Knuth Morris Algorithm. Using text's degenerating property to increase programme complexity is the fundamental principle underlying the KMP method.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void computeLPS(string pattern, vector<int> &lps) {
  int len = 0;
  int i = 1;

  lps[0] = 0;

  while (i < pattern.length()) {
    if (pattern[i] == pattern[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
}

void KMP(string text, string pattern) {
  int n = text.length();
  int m = pattern.length();

  vector<int> lps(m);

  computeLPS(pattern, lps);

  int i = 0;
  int j = 0;

  while (i < n) {
    if (pattern[j] == text[i]) {
      j++;
      i++;
    }

    if (j == m) {
      cout << "Pattern found at index " << i - j << "\n";
      j = lps[j - 1];
    } else if (i < n && pattern[j] != text[i]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }
}

int main() {
  string text = "ABAAABCDBBABCDDEBCABC";
  string pattern = "ABC";

  KMP(text, pattern);

  return 0;
}
