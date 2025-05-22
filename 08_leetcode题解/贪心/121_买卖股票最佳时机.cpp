// 思路：求差额的最大子序和

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

int maxProfit(vector<int>& prices) {
  vector<int> nums;
  for (int i = 1; i < prices.size(); i++) {
    nums.push_back(prices[i] - prices[i - 1]);
  }

  int sum = 0, max = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    if (sum < 0) sum = 0;
    max = sum > max ? sum : max;
  }

  return max < 0 ? 0 : max;
}

int main() {
  vector<int> nums{7, 1, 5, 3, 6, 4};
  const auto res = maxProfit(nums);
  cout << res;
}
