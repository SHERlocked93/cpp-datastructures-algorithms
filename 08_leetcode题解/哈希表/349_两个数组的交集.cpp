// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。
//
// 思路：用哈希表记住字母出现的次数是否一样

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../../common.h"

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  std::unordered_map<int, bool> numMap;
  std::for_each(nums1.cbegin(), nums1.cend(), [&numMap](int c) { numMap[c] = true; });
  unordered_set<int> res;
  std::for_each(nums2.cbegin(), nums2.cend(), [&numMap, &res](int c) {
    if (numMap[c])
      res.insert(c);
  });
  return {res.cbegin(), res.cend()};
}

int main() {
  vector<int> a{1, 2, 2, 1, 8};
  vector<int> b{2, 2, 3, 1, 7, 8};
  const auto res = intersection(a, b);

  cout << res.size();
}
