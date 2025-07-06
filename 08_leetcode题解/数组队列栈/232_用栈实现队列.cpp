// 用两个栈实现一个队列，正序栈用来加入元素，就是从队列头入，倒序栈用来出元素，就是从队列底出，来回倒

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;
stack<int> sta_{};
stack<int> rev_{};
bool isSeq_ = true;
bool empty() {
  return isSeq_ ? sta_.empty() : rev_.empty();
}

void restore() {
  if (isSeq_)
    return;
  while (!rev_.empty()) {
    auto top = rev_.top();
    rev_.pop();
    sta_.push(top);
  }
  isSeq_ = true;
}

void revert() {
  if (!isSeq_)
    return;
  while (!sta_.empty()) {
    auto top = sta_.top();
    sta_.pop();
    rev_.push(top);
  }
  isSeq_ = false;
}

void push(int x) {
  restore();
  sta_.push(x);
}

int pop() {
  revert();
  auto top = rev_.top();
  rev_.pop();
  return top;
}

int peek() {
  revert();
  return rev_.top();
}

int main() {}
