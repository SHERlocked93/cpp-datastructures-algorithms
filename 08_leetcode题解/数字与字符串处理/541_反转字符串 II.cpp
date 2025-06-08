// 思路：用倒叙迭代器，或前后指针交换

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

string reverseStr(string s, int k) {
  auto reverse = [&s](int begin, int end) {
    if (end >= s.size() - 1)
      end = s.size() - 1;

    for (int i = begin; i <= (end + begin) / 2; ++i) {
      swap(s[i], s[end - i + begin]);
    }
  };
  int curr = 0;
  while (curr < s.length()) {
    reverse(curr, curr + k - 1);
    curr += 2 * k;
  }

  return s;
}

int main() {
  cout << " : " << reverseStr("theskyisblue", 2) << endl;
}
