// 思路：找装满 sum/2 最大的重量

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int lastStoneWeightII(vector<int>& stones) {
  const auto len = stones.size();
  if (len == 1)
    return stones[0];
  const auto sum = accumulate(stones.begin(), stones.end(), 0) ;
  const auto tar = sum / 2;

  vector<vector<int>> dp(len , vector<int>(tar + 1, 0));
  for (int i = 0; i <= tar; ++i) {
    dp[0][i] = i < stones[0] ? 0 : stones[0];
  }
  for (int i = 1; i < len; ++i) {
    for (int j = 0; j <= tar; ++j) {
      if (j < stones[i])
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = std::max({dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]});
    }
  }

  return sum - 2 * dp[len-1][tar];
}

int main() {
  vector<int> nums{31,26,33,21,40};
  cout << lastStoneWeightII(nums);
}
