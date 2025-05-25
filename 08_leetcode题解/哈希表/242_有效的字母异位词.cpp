// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。
//
// 思路：用哈希表记住字母出现的次数是否一样

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

bool isAnagram(string s, string t) {
  std::vector<int> charTimes(26, 0);
  std::for_each(s.cbegin(), s.cend(), [&charTimes](char c) { charTimes[c - 'a']++; });
  std::for_each(t.cbegin(), t.cend(), [&charTimes](char c) { charTimes[c - 'a']--; });

  for (int val : charTimes) {
    if (val)
      return false;
  }
  return true;
}

int main() {
  const auto res = isAnagram("anagram", "nagaram");

  cout << res;
}
