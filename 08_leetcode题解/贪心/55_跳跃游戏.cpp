// 思路：只要把每一步能跳的最远距离记录下来，在第i个点之前，最远距离不能小于等于i，否则意思就是在i之前都跳不过i

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

int jump(vector<int>& nums) {
  if (nums.size() == 1) return true;
  vector<int> numAble{};
  for (int i = 0; i < nums.size(); i++) {
    numAble.push_back(i + nums[i]);
  }
  int max = numAble[0];
  for (int i = 0; i < nums.size() - 1; i++) {
    max = numAble[i] > max ? numAble[i] : max;
    if (max <= i) return false;
  }
  return true;
}

int main() {
  // vector<int> nums{7, 1, 5, 3, 6, 4};
  // vector<int> nums{3, 2, 1, 0, 4};
  vector<int> nums{2, 3, 1, 1, 4};
  const auto res = jump(nums);
  cout << res;
}
