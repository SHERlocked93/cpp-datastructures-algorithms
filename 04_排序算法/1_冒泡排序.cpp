// 冒泡排序
//
// ## 逻辑
// 1. 依次对比相邻元素，如果左边大于右边就对调
// 2. 对每一对相邻元素执行步骤1，执行完最后一个元素为最大元素
// 3. 对除最后一个元素外的元素重复执行步骤1-2
//
// ## 复杂度分析
// - 时间复杂度：O(n^2) 第一次需要对比n-1次，第二次需要n-2次....最后一次对比1次，一共 n(n-1)/2 次，忽略低次项，为n^2

// 选择排序
// 相当于确定顺序的冒泡，时间复杂度 O(n^2)  空间复杂度 O(1)

// 1. 遍历数组，找出最小的元素放到最前面
// 3. 对剩余元素执行步骤1
// 4. 重复步骤2-3

// ## 复杂度分析
// - 时间复杂度：O(n^2) 第一次需要对比n-1次，第二次需要n-2次....最后一次对比1次，一共 n(n-1)/2 次，忽略低次项，为n^2

#include <iostream>
#include <vector>

#include "../Common.h"

using namespace std;

vector<int> bubbleSort(const vector<int>& vec) {
  vector<int> res(vec.begin(), vec.end());

  for (int i = 0; i < vec.size() - 1; i++) {
    int left = i;
    int right = i + 1;

    while (right < vec.size()) {
      if (res[left] > res[right]) swap(res[left], res[right]);
      right++;
    }
  }

  return res;
}

int main() {
  const auto res = bubbleSort({10, 5, 3, 21, 14, 24, 12, 15, 4, 9, 20, 16, 22, 6, 1, 23, 17, 2, 19, 7, 8, 11, 13, 18});

  cout << int2str(res);
}
