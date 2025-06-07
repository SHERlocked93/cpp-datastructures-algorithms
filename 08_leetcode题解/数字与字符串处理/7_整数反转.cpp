// 思路：这题的坑是超过最大和最小值怎么处理

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

int reverse(int x) {
  int res = 0;
  while (x) {
    auto re = x % 10;
    x = x / 10;
    if (res > INT_MAX / 10 || res < INT_MIN / 10)
      return 0;
    res = 10 * res + re;
  }

  return res;
}

int main() {
  cout << " : " << reverse(1534236469);
}
