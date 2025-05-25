// 思路：dp[i][j] = dp[i - 1][j] + dp[i][j - 1] 这个格子[i][j]要么由上面下来，要么由左边过来

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
  vector<vector<unsigned int>> dp(m);

  for (int i = 0; i < m; ++i) {
    dp[i].resize(n + 1);
    dp[i][0] = 1;
  }
  for (int i = 0; i < n; ++i) {
    dp[0][i] = 1;
  }
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  return dp[m - 1][n - 1];
}

int main() {
  const auto res = uniquePaths(3, 7);
  cout << res;
}
