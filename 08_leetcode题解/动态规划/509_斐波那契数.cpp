// 思路：dp数组依赖于前两个值，可以不用数组存值，只维护前两个值

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int fib(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int main() {
  cout << fib(6);
}
