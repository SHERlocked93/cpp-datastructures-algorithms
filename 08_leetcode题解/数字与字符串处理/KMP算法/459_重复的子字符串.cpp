// 思路：
// 1. 暴力解法是双层for循环
// 2. 双倍字符串法，如果两个s拼起来，去除最强一个和最后一个字符后的ss里包含了s，那么就是重复字符串
// 3. KMP算法，如果原字符串可以整除最长相等前后缀的长度，

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../../common.h"

using namespace std;

// 暴力
bool repeatedSubstringPattern(string s) {
  int len = s.length();

  for (int i = len - 1; i > 0; --i) {
    if (len % i)
      continue;

    string sub = s.substr(0, i);
    auto res = true;
    for (int j = 1; j < len / i; j++) {
      auto nxt = s.substr(j * i, i);
      if (nxt == sub)
        continue;
      res = false;
      break;
    }
    if (res)
      return true;
  }

  return false;
}

// 移动匹配
bool repeatedSubstringPattern1(string s) {
  string ss = s + s;
  ss.erase(ss.end() - 1);
  ss.erase(0, 1);
  return ss.find(s) != string::npos;
}

// KMP
bool repeatedSubstringPattern2(string s) {
  int j = 0;
  vector<int> next(s.size(), 0);
  for (int i = 1; i < s.size(); ++i) {
    while (j > 0 && s[i] != s[j]) {
      j = next[j - 1];
    }
    if (s[i] == s[j])
      j++;
    next[i] = j;
  }
  auto needle = s.substr(0, s.size() - next[s.size() - 1]);

  return s.size() % needle.size() == 0;
}

int main() {
  cout << " : " << (repeatedSubstringPattern2("abcabcabca") ? "true" : "false");
}
