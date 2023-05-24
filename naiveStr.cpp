//2.	String Matching: 
//Naïve approach 
//Among all the pattern finding algorithms, naive pattern searching is the most straightforward. It looks for every character in the primary string that matches the pattern.


#include <iostream>
#include <string>
using namespace std;

void naiveStringMatch(string str, string pattern) {
  int n = str.length();
  int m = pattern.length();

  for (int i = 0; i <= n - m; i++) {
    int j;
    for (j = 0; j < m; j++) {
      if (str[i + j] != pattern[j]) {
        break;
      }
    }
    if (j == m) {
      cout << "Pattern found at index " << i << "\n";
    }
  }
}

int main() {
  string str = "ABAAABCDBBABCDDEBCABC";
  string pattern = "ABC";

  naiveStringMatch(str, pattern);

  return 0;
}
