// 二分查找
// 要求有序列表
// 时间复杂度 O(logn)  空间复杂度 O(1)

#include <iostream>
#include <vector>

const std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int find_binary(const std::vector<int>& vec, int tar) {
  int low = 0;
  int high = vec.size() - 1;

  while (low <= high) {
    if (vec[low] == tar) return low;
    if (vec[high] == tar) return high;
    if (vec[low] > tar || vec[high] < tar) return -1;

    int sign = low + (high - low) / 2;
    int guess = vec[sign];
    if (guess > tar)
      high = sign;
    else if (guess < tar)
      low = sign;
    else
      return sign;
  }
  return -1;
}

int main() {
  const auto res = find_binary(vec, 8);
  std::cout << "idx:" << res;
}
