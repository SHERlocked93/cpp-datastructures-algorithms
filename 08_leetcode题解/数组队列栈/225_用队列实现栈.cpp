// 用一个队列就可以实现栈，入队的时候一样，出队的时候，通过把前size-1个元素出队再入队的方式，找到栈底元素

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;
queue<int> qee_{};
bool empty() {
  return qee_.empty();
}

void push(int x) {
  qee_.push(x);
}

int pop() {
  int i = qee_.size();
  while (--i) {
    auto top = qee_.back();

    qee_.pop();
    qee_.push(top);
  }
  auto top = qee_.back();
  qee_.pop();
  return top;
}
int top() {
  return qee_.front();
}

int main() {
  qee_.push(1);
  qee_.push(2);
  auto a = top();
}
