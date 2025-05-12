// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
// 输入：n = 3
// 输出：[[ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ]]
// 思路：处理边界条件，注意区间确定，比如左开右闭，然后单独处理圈数为奇数的情况

#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

vector<vector<int>> generateMatrix(int n) {
  int roundAll = n / 2, count = 0;
  vector<vector<int>> res(n);

  for (int i = 0; i < n; i++) {
    res[i] = vector<int>(n);
  }

  for (int round = 0; round < roundAll; round++) {
    for (int k = round; k < n - 1 - round; k++) {
      res[round][k] = ++count;
    }
    for (int k = round; k < n - 1 - round; k++) {
      res[k][n - 1 - round] = ++count;
    }
    for (int k = n - 1 - round; k > round; k--) {
      res[n - 1 - round][k] = ++count;
    }
    for (int k = n - 1 - round; k > round; k--) {
      res[k][round] = ++count;
    }
  }

  if (n % 2 == 1) {
    res[n / 2][n / 2] = ++count;
  }
  return res;
}

int main() {
  vector<int> nums{};
  const auto len = generateMatrix(4);
}
