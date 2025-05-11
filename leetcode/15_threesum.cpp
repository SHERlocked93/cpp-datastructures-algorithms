#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> map_;
  for (int i = 0; i < nums.size(); i++) {
    int resl = target - nums[i];

    if (map_.find(resl) == map_.end()) {
      map_[nums[i]] = i;
      continue;
    }

    return {i, map_[resl]};
  }
  return {};
}

int main() {
  vector<int> nums{3, 2, 4};
  auto vec = twoSum(nums, 6);
}
