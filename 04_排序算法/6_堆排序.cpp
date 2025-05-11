// 堆排序
// 1. 建堆:将无序数组调整为最大堆 O(n)
// 2. 排序:每次将堆顶元素与末尾元素交换，将堆的规模减一调整剩余元素为最大堆。重复该过程直到只剩一个元素 O(nlogn)

#include <iostream>
#include <vector>

#include "../Common.h"

using namespace std;

// \param maxidx 排序到这一位
// \param rooti 对此根节点的子树堆排序
void heapify(vector<int>& arr, int maxidx, int rooti) {
  if (rooti == maxidx) return;
  int left = 2 * rooti + 1;   // 左子节点
  int right = 2 * rooti + 2;  // 右子节点，注意可能不存在

  int max = rooti;
  if (left <= maxidx && arr[left] > arr[max]) max = left;
  if (right <= maxidx && arr[right] > arr[max]) max = right;

  if (max != rooti) {  // 如小于子节点
    swap(arr[rooti], arr[max]);
    heapify(arr, maxidx, max);  // 对动了的那个节点子树堆排序
  }
}

void heapSort(vector<int>& arr) {
  int maxidx = arr.size() - 1;

  // 初始建堆，从最后一个有度的节点开始，即最后节点的父节点
  for (int i = (maxidx - 1) / 2; i >= 0; i--) {
    heapify(arr, maxidx, i);
  }

  // 交换根节点即最大值和最后一个元素
  for (int i = maxidx; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i - 1, 0);
  }
}

int main() {
  auto arr = vector<int>{10, 5, 3, 21, 14, 24, 12, 15, 4, 9, 20, 16, 22, 6, 1, 23, 17, 2, 19, 7, 8, 11, 13, 18};
  heapSort(arr);

  cout << int2str(arr);
}
