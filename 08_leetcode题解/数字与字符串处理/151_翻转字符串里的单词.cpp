// 思路： 注意开头可能存在的空格，和连续出现的空格
// 或者双指针法，然后把找到的单词放在结果的前面

#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

string reverseWords(string s) {
  string res;

  int i = 0;
  while (i < s.size()) {
    while (i < s.size() && s[i] == ' ') ++i;
    if (i >= s.size())
      break;

    int j = i + 1;
    while (j <= s.size() && s[j] != ' ') ++j;

    auto word = s.substr(i, j - i);

    res = res.empty() ? word : word + " " + res;
    i = j;
  }
  return res;
}

int main() {
  cout << " :>" << reverseWords("  hello world  ") << "<";
  string s;
  cin >> s;
  return 0;
}
