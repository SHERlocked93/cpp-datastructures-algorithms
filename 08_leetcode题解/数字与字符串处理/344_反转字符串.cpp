// 思路：用倒叙迭代器，或前后指针交换

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

void reverseString(vector<char>& s) {
  // vector<char> res;
  // for (auto i = s.rbegin(); i != s.rend(); i++) {
  //   res.push_back(*i);
  // }
  // for (char& i : std::ranges::reverse_view(s)) {
  //   res.push_back(i);
  // }
  // s = std::move(res);
  int len = s.size();
  for (int i = 0; i < s.size() / 2; ++i) {
    swap(s[i], s[len - 1 - i]);
  }
}

int main() {
  vector<char> s{'H', 'a', 'n', 'n', 'a', 'h'};
  cout << "befor : " << bytes2hexStr(s, s.size()) << endl;
  reverseString(s);
  cout << "after : " << bytes2hexStr(s, s.size());
}
