// 思路：dp[i]为最大子数积，问题分解为i*(n-i)和i*dp[n-i]求最大的问题

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int integerBreak(int n) {
  if (n == 2)
    return 1;
  vector<int> dp(n + 1);
  dp[2] = 1;
  dp[1] = 0;

  for (int i = 3; i <= n; i++) {
    for (int j = 1; j <= i / 2; j++) {
      dp[i] = std::max({j * (i - j), j * dp[i - j], dp[i]});
    }
  }
  return dp[n];
}

int main() {
  cout << integerBreak(10);
}
