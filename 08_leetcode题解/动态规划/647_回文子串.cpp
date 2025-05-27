// 思路：dp[左][右]是回文子串的条件是 s[左]==s[右] 且s[左+1][右-1] 也是回文子串，注意初始条件左==右时是，右-左==1时需要左==右

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int countSubstrings(string s) {
  int len = s.size(), sum = 0;
  vector<vector<int>> dp(len);  // dp[左][右] 左闭右闭区间
  for (int i = 0; i < len; ++i) {
    dp[i].resize(len);
  }
  for (int i = len - 1; i >= 0; i--) {
    for (int j = len - 1; j >= i; j--) {
      auto isPalin = 0;
      if (i == j) {
        isPalin = 1;
      } else if (j == i + 1) {
        isPalin = s[i] == s[j];
      } else {
        isPalin = s[i] == s[j] && dp[i + 1][j - 1];
      }
      dp[i][j] = isPalin;
      if (isPalin)
        sum++;
    }
  }
  return sum;
}

int main() {
  cout << countSubstrings("aaa");
}
