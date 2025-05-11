// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
// 假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
//  更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
//  返回 k。
//
// 思路：快慢指针

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

int removeElement(vector<int>& nums, int val) {
  int n = 0;  // 快指针与慢指针的偏移

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != val) {
      nums[i - n] = nums[i];
      continue;
    }
    n++;
  }

  return nums.size() - n;
}

int main() {
  vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
  const auto len = removeElement(nums, 2);
  cout << "len:" << len << " : " << int2str(nums, len);
}
