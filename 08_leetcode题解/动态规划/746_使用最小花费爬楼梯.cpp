// 思路：dp数组依赖于前两个值，往上跳才会花费cost[i]，因此dp[i]花费是 dp[i - 1] + cost[i - 1] 和 dp[i - 2] + cost[i - 2] 中小的一个

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
  vector<int> dp(cost.size() + 1);
  dp[0] = 0;
  dp[1] = 0;
  for (int i = 2; i <= cost.size(); i++) {
    dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
  }
  return dp[cost.size()];
}

int main() {
  // vector<int> cost{10, 15, 20};
  vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  const auto res = minCostClimbingStairs(cost);
  cout << res;
}
