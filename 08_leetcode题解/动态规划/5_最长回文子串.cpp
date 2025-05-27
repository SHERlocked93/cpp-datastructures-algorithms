// 思路：dp[左][右]是回文子串的条件是 s[左]==s[右] 且s[左+1][右-1] 也是回文子串，注意初始条件左==右时是，右-左==1时需要左==右

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
  int len = s.size(), longest = 0, lleft = 0, lright = 0;

  vector<vector<int>> dp(len);
  for (int i = 0; i < len; ++i) {
    dp[i].resize(len);
  }

  for (int i = len - 1; i >= 0; --i) {
    for (int j = len - 1; j >= i; --j) {
      int isPa = 0;
      if (i == j) {
        isPa = 1;
      } else if (j == i + 1) {
        isPa = s[i] == s[j];
      } else {
        isPa = s[i] == s[j] && dp[i + 1][j - 1];
      }
      if (isPa && j - i > longest) {
        longest = j - i;
        lleft = i;
        lright = j;
      }
      dp[i][j] = isPa;
    }
  }

  return s.substr(lleft, lright - lleft + 1);
}

int main() {
  cout << longestPalindrome("babad");
}
