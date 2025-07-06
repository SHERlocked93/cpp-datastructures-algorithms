// 给定一个含有 n 个正整数的数组和一个正整数 target
// 找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0
//
// 思路：滑动窗口

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
  int minlen = INT_MAX, sum = 0, left = 0;

  for (int right = 0; right < nums.size(); right++) {
    sum += nums[right];

    while (sum >= target) {
      int currlen = right - left + 1;
      minlen = minlen < currlen ? minlen : currlen;
      sum -= nums[left++];
    }
  }

  return minlen == INT_MAX ? 0 : minlen;
}

int main() {
  vector<int> nums{2, 3, 1, 2, 4, 3};
  auto len = minSubArrayLen(7, nums);

  cout << "len:" << len << endl;  // 2

  nums = {1, 1, 1, 1, 1, 1};
  len = minSubArrayLen(11, nums);
  cout << "len:" << len << endl;  // 0
}
