// 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足
// 思路：用哈希表记住字母出现的次数是否一样

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
  unordered_map<int, int> map12_;
  unordered_map<int, int> map34_;

  for (int i : nums1) {
    for (int j : nums2) {
      map12_[i + j]++;
    }
  }

  for (int i : nums3) {
    for (int j : nums4) {
      map34_[i + j]++;
    }
  }

  int resTimes = 0;
  for (auto& [key, times] : map12_) {
    if (map34_.find(-key) != map34_.end()) {
      resTimes += times * map34_[-key];
    }
  }
  return resTimes;
}

int main() {
  vector<int> nums1{1, 2};
  vector<int> nums2{-2, -1};
  vector<int> nums3{-1, 2};
  vector<int> nums4{0, 2};
  auto vec = fourSumCount(nums1, nums2, nums3, nums4);

  cout << vec;
}
