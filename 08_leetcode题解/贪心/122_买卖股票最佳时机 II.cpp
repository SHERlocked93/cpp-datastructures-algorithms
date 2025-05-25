// 思路：差额的正数累加

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

  int sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] < 0)
      continue;
    sum += nums[i];
  }

  return sum;
}

int main() {
  vector<int> nums{7, 1, 5, 3, 6, 4};
  const auto res = maxProfit(nums);
  cout << res;
}
