// 选择排序
// 时间复杂度 O(n^2)  空间复杂度 O(1)

#include <iostream>
#include <vector>

#include "../Common.h"

using namespace std;

vector<int> selection_sort(const vector<int>& vec) {
  vector<int> res(vec.begin(), vec.end());

  for (int i = 0; i < vec.size() - 1; i++) {
    int left = i;
    int right = i + 1;

    while (right < vec.size()) {
      if (res[left] > res[right]) {
        swap(res[left], res[right]);
      }
      right++;
    }
  }

  return res;
}

int main() {
  auto res = selection_sort({10, 5, 3, 21, 14, 24, 12, 15, 4, 9, 20, 16, 22, 6, 1, 23, 17, 2, 19, 7, 8, 11, 13, 18});

  cout << int2str(res);
}
