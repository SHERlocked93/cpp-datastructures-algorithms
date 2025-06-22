// 思路：
// 1. KMP算法 https://www.bilibili.com/video/BV1234y1y7pm
// 2. https://www.bilibili.com/video/BV1AY4y157yL/
// 3. https://writings.sh/post/algorithm-repeated-string-pattern
// 难点是next数组的构建

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../../common.h"

using namespace std;

void getNext(vector<int>& next, const string& s) {
  int j = 0;  // j是前后缀相同长度
  next[0] = 0;
  for (int i = 1; i < s.size(); i++) {  // 注意next索引i从1开始
    while (j > 0 && s[i] != s[j]) {     // 前后缀不相同了
      j = next[j - 1];                  // 查表回退到最后一个[i]==s[j]处
    }
    if (s[i] == s[j]) {  // 找到相同的前后缀
      j++;
    }
    next[i] = j;  // 将j（前缀的长度）赋给next[i]
  }
}

int strStr(string haystack, string needle) {
  if (needle.size() == 0) {
    return 0;
  }
  vector<int> next(needle.size());
  getNext(next, needle);
  int j = 0;                                     // 因为next数组里记录的起始位置为-1
  for (int i = 0; i < haystack.size(); i++) {    // 注意i就从0开始
    while (j > 0 && haystack[i] != needle[j]) {  // 不匹配
      j = next[j - 1];                           // j寻找之前匹配的位置
    }
    if (haystack[i] == needle[j]) {  // 匹配，j和i同时向后移动
      j++;                           // i的增加在for循环里
    }
    if (j == needle.size()) {          // 文本串s里出现了模式串t
      return (i - needle.size() + 1);  // 此时i为最后一位
    }
  }
  return -1;
}

int main() {
  cout << " : " << strStr("afdbaaabacababaabaafa", "abacabab");
}
