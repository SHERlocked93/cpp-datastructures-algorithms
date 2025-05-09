// 归并排序

#include <iostream>
#include <vector>

#include "../Common.h"

using namespace std;

void mergeSort(vector<int>& arr, int left, int right) {
  if (right <= left) return;
  int mid = left + (right - left) / 2;

  mergeSort(arr, left, mid);       // 左数组返回时此区间是有序数组
  mergeSort(arr, mid + 1, right);  // 右数组

  vector<int> temp(right);
  // 下面进行两个有序区间的合并
  int i = left;     // 左数组指针
  int j = mid + 1;  // 右数组指针
  int k = left;     // temp指针，把左右数组合并到temp

  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }
  while (j <= right) {
    temp[k++] = arr[j++];
  }
  while (i <= mid) {
    temp[k++] = arr[i++];
  }
  copy_n(temp.data() + left, right - left + 1, arr.data() + left);
}

int main() {
  auto arr = vector<int>{10, 5, 3, 21, 14, 24, 12, 15, 4, 9, 20, 16, 22, 6, 1, 23, 17, 2, 19, 7, 8, 11, 13, 18};
  mergeSort(arr, 0, arr.size() - 1);

  cout << int2str(arr);
}
