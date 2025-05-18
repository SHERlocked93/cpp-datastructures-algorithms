// 给出一个有n个整数的数组S，在S中找到三个整数a, b, c，找到所有使得a + b + c = 0的三元组。
//   思路：先排序，然后每次先选定中间的数从左右遍历求和跟0比较，注意特殊情况去重处理

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> res;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); i++) {
    if (i > 0 && nums[i - 1] == nums[i]) {  // 注意这里判断的是i-1，要判断已经判断过的i，如果是i+1就是判断未判过的i了
      continue;
    }
    int left = i + 1, right = nums.size() - 1;
    while (left < right) {
      int sum = nums[left] + nums[i] + nums[right];
      if (sum > 0)
        right--;
      else if (sum < 0) {
        left++;
      } else {
        res.push_back({nums[i], nums[left], nums[right]});

        // 注意这里对left有个边界，而且判断的是left+1，即未判断过的元素
        while (left < nums.size() - 1 && nums[left] == nums[left + 1]) left++;
        left++;
        while (right > 1 && nums[right] == nums[right - 1]) right--;
        right--;
      }
    }
  }

  return res;
}

int main() {
  // vector<int> nums{-1, 0, 1, 2, -1, -1, -1, 1, 1, 1, 1, 1, -4};
  vector<int> nums{0, 0, 0};
  auto vec = threeSum(nums);
}
