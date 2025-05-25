// 思路： 从前往后检查一遍，从后往前再检查一遍

#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

int candy(vector<int>& ratings) {
  vector<int> candies(ratings.size(), 1);
  for (int i = 0; i < ratings.size() - 1; i++) {
    if (ratings[i] < ratings[i + 1] && candies[i] >= candies[i + 1]) {
      candies[i + 1] = candies[i] + 1;
    }
  }
  for (int i = ratings.size() - 1; i > 0; i--) {
    if (ratings[i] < ratings[i - 1] && candies[i] >= candies[i - 1]) {
      candies[i - 1] = candies[i] + 1;
    }
  }
  return accumulate(candies.cbegin(), candies.cend(), 0);
}

int main() {
  vector<int> ratings{1, 2, 3, 4, 5};
  const auto res = candy(ratings);
  cout << res;
}
