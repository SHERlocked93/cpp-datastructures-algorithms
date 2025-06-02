// 思路：在若干个物品中选出一些物品，每个物品只能使用一次，这些物品恰好能够填满容量为sum/2的背包 ，0-1背包问题

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool canPartition(vector<int>& nums) {
  const auto sum = accumulate(nums.begin(), nums.end(), 0);
  if (sum & 1)
    return false;
  const auto tar = sum / 2;
  const auto len = nums.size();

  // i为元素范围，j为能不能在i个元素中获得和为j的结果
  vector<vector<int>> dp(len + 1);
  for (int i = 0; i <= len; ++i) {
    dp[i].resize(tar + 1);
  }
  for (int i = 0; i <= tar; ++i) {
    dp[0][i] = nums[0] == i;
  }
  for (int i = 1; i < len; ++i) {
    for (int j = 0; j <= tar; ++j) {
      dp[i][j] = (nums[i] == j) || dp[i - 1][j] || (nums[i] > j ? dp[i - 1][j - nums[i]] : false);
    }
  }
  return dp[len - 1][tar];
}

int main() {
  vector<int> nums{1, 5, 11, 5};
  cout << canPartition(nums);
}
