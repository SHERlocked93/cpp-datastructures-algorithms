// 在一串连续数字 vector 中，找出3个数字的索引x、y、z，其中 x<y<z，满足 vector[x] - vector[y] 最大，且在满足前者的情况下，满足 vector[z] >
// vector[x]且z最大，如果没有满足的 z，z返回 -1
#include <climits>
#include <iostream>
#include <tuple>
#include <vector>

std::tuple<int, int, int> findXYZ(const std::vector<int>& nums) {
  if (nums.size() < 3) {
    return {-1, -1, -1};  // vector 长度不足，无法找到 x, y, z
  }

  int diff_max = INT_MIN;  // 最大差值
  int suffix_max = 0;      // 最大值
  int x = 0, y = 0, z = -1;

  for (int i = 0; i < nums.size(); ++i) {
    int curr_diff = nums[suffix_max] - nums[i];
    if (nums[i] > nums[suffix_max])
      suffix_max = i;
    if (curr_diff > diff_max) {
      x = suffix_max;
      y = i;
      diff_max = curr_diff;
    }
  }

  for (int i = y; i < nums.size(); i++) {
    if (nums[i] > nums[x]) {
      if (z > 0 && nums[i] < nums[z])
        continue;
      z = i;
    }
  }

  return {x, y, z};
}

int main() {
  std::vector<int> vec{8, 2, 18, 8, 14, 16, 7, 12, 4, 6, 3, 8, 9, 4, 5, 7, 3, 12, 17, 11, 2, 1, 19};
  const auto [x, y, z] = findXYZ(vec);

  std::cout << x << ":" << vec[x] << "  " << y << ":" << vec[y] << "  " << z << ":" << vec[z];
}
