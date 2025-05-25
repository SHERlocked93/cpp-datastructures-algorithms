// 思路：dp数组依赖于前两个值，可以不用数组存值，只维护前两个值

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int climbStairs(int n) {
  if (n <= 3)
    return n;

  vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;

  for (int i = 4; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int main() {
  const auto res = climbStairs(4);
  cout << res;
}
