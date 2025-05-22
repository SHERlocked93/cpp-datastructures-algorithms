// 思路：用贪心可以做，用动态规划也可以，这里使用贪心，从头开始计算子序和，如果子序和小于0就从下个月元素开始重新计算子序和，否则向下累加

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

int maxSubArray(vector<int>& nums) {
  int sum = 0, max = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    max = sum > max ? sum : max;
    if (sum <= 0) sum = 0;
  }

  return max;
}

int main() {
  vector<int> g{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  const auto res = maxSubArray(g);

  cout << res;
}
