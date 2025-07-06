// 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
//
// 思路：双指针，相向前进并判断

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
  vector<int> res(nums.size());
  int left = 0, right = nums.size() - 1;

  const auto getAbs = [](int tar) {
    return tar < 0 ? -tar : tar;
  };

  for (int i = right; i >= 0 && left <= right; i--) {
    if (getAbs(nums[left]) > getAbs(nums[right])) {
      res[i] = nums[left] * nums[left];
      left++;
      continue;
    }
    res[i] = nums[right] * nums[right];
    right--;
  }
  return res;
}

int main() {
  vector<int> nums{-7, -3, 2, 3, 11};
  const auto res = sortedSquares(nums);

  cout << int2str(res);
}
