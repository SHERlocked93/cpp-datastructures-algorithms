// 思路：只要把每一步能跳的最远距离记录下来，在第i个点之前，找到能跳到的最远距离，然后从最远距离的i开始算下一次能跳的最远距离，步数+1

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

int jump(vector<int>& nums) {
  vector<int> numAble{};
  for (int i = 0; i < nums.size(); i++) {
    numAble.push_back(i + nums[i]);
  }
  int minstep = 0;
  for (int i = 0; i < numAble.size() - 1; i++) {
    if (numAble[i] >= nums.size() - 1)
      return minstep + 1;
    vector<int> iable{};
    int minus = 0, max = numAble[i], maxidx = i;
    for (int j = numAble[i]; j > i; j--) {
      if (numAble[j] > max) {
        max = numAble[j];
        maxidx = j;
      }
      minus++;
    }
    i = maxidx - 1;
    minstep++;
  }
  return minstep;
}

int main() {
  // vector<int> nums{3, 2, 1,1, 4};
  vector<int> nums{2, 3, 1};
  const auto res = jump(nums);
  cout << res;
}
