// 思路：如果总油量减去总消耗大于等于零那么一定可以跑完一圈，类似于求最大子序和，如果子序和为负就从下个开始取

#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int curSum = 0;
  int totalSum = 0;
  int start = 0;
  for (int i = 0; i < gas.size(); i++) {
    curSum += gas[i] - cost[i];
    totalSum += gas[i] - cost[i];
    if (curSum < 0) {  // 当前累加rest[i]和 curSum一旦小于0
      start = i + 1;   // 起始位置更新为i+1，如果这个点后面差额累加为正，在totalSum>0的情况下，循环回头一定可以跑完前面的
      curSum = 0;      // curSum从0开始
    }
  }
  if (totalSum < 0)
    return -1;  // 说明怎么走都不可能跑一圈了
  return start;
}

int main() {
  vector<int> gas{1, 2, 3, 4, 5};
  vector<int> cost{3, 4, 5, 1, 2};
  // vector<int> gas{2, 2};
  // vector<int> cost{2, 2};
  const auto res = canCompleteCircuit(gas, cost);
  cout << res;
}
