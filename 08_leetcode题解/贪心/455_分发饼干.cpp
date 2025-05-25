// 思路： 排序后双指针，拿最大的小孩跟最大的饼干比，不满足就次大的小孩和最大的饼干比

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
  int res = 0, j = s.size() - 1;
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());
  for (int i = g.size() - 1; i >= 0 && j >= 0; i--) {
    if (g[i] > s[j])
      continue;
    res++;
    j--;
  }
  return res;
}

int main() {
  vector<int> g{1, 2, 3};  // child greed
  vector<int> s{3};        // size of cookie
  const auto res = findContentChildren(g, s);

  cout << res;
}
