// 给一个包含n个数的整数数组S，在S中找到所有使得和为给定整数target的四元组(a, b, c, d)。
//   思路：先排序，然后每次先选定中间的数从左右遍历求和跟0比较，注意特殊情况去重处理

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  vector<vector<int>> res;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); i++) {
    if (i > 0 && nums[i - 1] == nums[i]) {  // 注意这里判断的是i-1，要判断已经判断过的i，如果是i+1就是判断未判过的i了
      continue;
    }
    if (nums[i] > target && nums[i] >= 0)  // 注意这里
      break;
    for (int j = i + 1; j < nums.size(); j++) {
      if (j > i + 1 && nums[j - 1] == nums[j]) {
        continue;
      }
      if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)  // 注意这里
        break;
      int left = j + 1, right = nums.size() - 1;
      while (left < right) {
        if ((long)nums[i] + nums[j] + nums[left] > target && nums[i] + nums[j] + nums[left] >= 0)  // 注意这里
          break;
        long sum = (long)nums[left] + nums[i] + nums[j] + nums[right]; // 转long，否则-1000000000测试用例溢出
        if (sum > target)
          right--;
        else if (sum < target) {
          left++;
        } else {
          res.push_back({nums[i], nums[j], nums[left], nums[right]});

          // 注意这里对left有个边界，而且判断的是left+1，即未判断过的元素
          while (left < nums.size() - 1 && nums[left] == nums[left + 1]) left++;
          left++;
          while (right > 1 && nums[right] == nums[right - 1]) right--;
          right--;
        }
      }
    }
  }

  return res;
}

int main() {
  // vector<int> nums{-1, 0, 1, 2, -1, -1, -1, 1, 1, 1, 1, 1, -2, -4};
  vector<int> nums{1, 0, -1, 0, -2, 2};
  auto vec = fourSum(nums, 0);
}
