// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
//

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

int search(vector<int>& nums, int target) {
  for (int left = 0, right = nums.size() - 1; left <= right;) {  // 区间左闭右闭，left==right也是合法条件
    int mid = left + (right - left) / 2;
    if (left == mid) {
      if (nums[left] == target) return left;
      return nums[right] == target ? right : -1;
    }
    if (nums[mid] < target)
      left = mid + 1;
    else if (nums[mid] > target)
      right = mid - 1;
    else
      return mid;
  }
  return -1;
}

int main() {
  vector<int> nums{-1,0,3,5,9,12};
  const auto idx = search(nums, -1);

  cout << "idx:" << idx;
}
