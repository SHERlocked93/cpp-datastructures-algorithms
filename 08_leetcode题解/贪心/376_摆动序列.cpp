// 思路：对比前后值差额的正负性，是0就跳过

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

int wiggleMaxLength(vector<int>& nums) {
  vector<int> arr{};
  if (nums.size() == 0)
    return 0;
  if (nums.size() == 1)
    return 1;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] - nums[i - 1]) {
      arr.push_back(nums[i] - nums[i - 1]);
    }
  }
  if (arr.empty())
    return 1;
  int sum = 2;
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] * arr[i - 1] > 0)
      continue;
    sum++;
  }
  return sum;
}

int main() {
  // vector<int> g{1, 7, 4, 9, 2, 5};
  vector<int> g{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
  const auto res = wiggleMaxLength(g);

  cout << res;
}
