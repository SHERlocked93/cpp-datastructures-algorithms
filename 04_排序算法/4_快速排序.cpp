// 快速排序
//
//

#include <iostream>
#include <vector>

#include "../common.h"

using namespace std;

void mergeSort(vector<int>& arr, int left, int right) {
  if (right <= left) return;

  int i = left, j = right;
  while (i < j) {
    while (i < j && arr[j] >= arr[left]) j--;  // 先从右往左说明i=j时汇合点数小于基准数
    while (i < j && arr[i] <= arr[left]) i++;
    swap(arr[i], arr[j]);
  }
  swap(arr[left], arr[i]);

  mergeSort(arr, left, i - 1);
  mergeSort(arr, i + 1, right);
}

vector<int> quickSort(const vector<int>& vec) {
  vector<int> res(vec.begin(), vec.end());

  mergeSort(res, 0, res.size() - 1);

  return res;
}

int main() {
  const auto res = quickSort({10, 5, 3, 21, 14, 24, 12, 15, 4, 9, 20, 16, 22, 6, 1, 23, 17, 2, 19, 7, 8, 11, 13, 18});

  cout << int2str(res);
}
