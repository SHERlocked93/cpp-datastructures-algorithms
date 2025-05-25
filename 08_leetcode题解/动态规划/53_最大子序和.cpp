// 思路：用贪心可以做，用动态规划也可以，这里使用动态规划

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

int maxSubArray(vector<int>& nums) {}

int main() {
  vector<int> g{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  const auto res = maxSubArray(g);

  cout << res;
}
