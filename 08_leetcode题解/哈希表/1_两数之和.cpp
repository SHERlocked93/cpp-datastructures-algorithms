// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。
//
// 思路：用哈希表记住出现过的数字序号

#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> map_;

  for (int i = 0; i < nums.size(); i++) {
    const auto resnum = target - nums[i];
    if (map_.find(resnum) != map_.end()) return {map_[resnum], i};
    map_[nums[i]] = i;
  }

  return {};
}

int main() {
  vector<int> nums{3, 2, 4};
  auto vec = twoSum(nums, 6);
}
