// 插入排序
//
//
// ## 逻辑
// 逻辑和打牌时候抓牌一样，将一系列数组作为拿到的牌，按照大小插到手上排好的牌中
// 1. 将第一个元素作为已排序数组，将其余元素作为未排序数组
// 2. 从未排序元素取出一个，在已排序数组中进行一次冒泡
// 3. 重复步骤1-2
//
// ## 复杂度分析
// - 时间复杂度：O(n^2) 有两次循环

#include <iostream>
#include <vector>

#include "../Common.h"

using namespace std;

vector<int> insertSort(const vector<int>& vec) {
  if (vec.size() <= 1) return vec;
  vector<int> res(vec.begin(), vec.end());

  for (int i = 1; i < vec.size(); i++) {
    int j = i - 1;
    while (j >= 0 && res[j] > res[j + 1]) {
      swap(res[j], res[j + 1]);
      j--;
    }
  }

  return res;
}

int main() {
  const auto res = insertSort({10, 5, 3, 21, 14, 24, 12, 15, 4, 9, 20, 16, 22, 6, 1, 23, 17, 2, 19, 7, 8, 11, 13, 18});

  cout << int2str(res);
}
