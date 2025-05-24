// 思路：先从小到大消耗完负数，然后排序后对最小值重复取反

#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());
  int minNum = 0;
  for_each(nums.begin(), nums.end(), [&minNum](int i) {
    if (i < 0) minNum++;
  });
  const int last = k - minNum;
  for (int i = 0; i < min(k, minNum); i++) {
    nums[i] = -nums[i];
  }
  sort(nums.begin(), nums.end());
  if (last < 0 || !(last & 1) || nums[0] == 0) {
    return accumulate(nums.begin(), nums.end(), 0);
  }
  return accumulate(nums.begin(), nums.end(), -2 * nums[0]);
}

int main() {
  vector<int> nums{-2, 9, 9, 8, 4};
  const auto res = largestSumAfterKNegations(nums, 5);
  cout << res;
}
