// 思路：dp[i][j] = dp[i - 1][j] + dp[i][j - 1] 这个格子[i][j]要么由上面下来，要么由左边过来

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  vector<vector<int>> dp(obstacleGrid.size());
  int getObs = 0;
  for (int i = 0; i < obstacleGrid.size(); ++i) {
    if (obstacleGrid[0][i] == 1) {
      getObs = 1;
    }
    if (getObs == 0) {
      dp[0][i] = 1;
    }
    dp[i].resize(obstacleGrid[0].size());
  }
}

int main() {
  const auto res = uniquePaths(3, 7);
  cout << res;
}
