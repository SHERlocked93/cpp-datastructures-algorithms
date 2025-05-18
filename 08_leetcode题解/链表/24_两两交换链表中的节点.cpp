// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
//
// 思路： 如果要操作第N个节点，要找到第N-1个节点

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../../common.h"

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
  auto vhead = new ListNode(0, head);
  auto curr = vhead;  // 交换的是cur的下个和下下个
  while (curr->next && curr->next->next) {
    auto p0 = curr->next;
    auto p1 = p0->next;
    auto p2 = p1->next;
    curr->next = p1;
    p1->next = p0;
    p0->next = p2;

    curr = p0;
  }
  return vhead->next;
}

int main() {
  auto h7 = ListNode(7);
  auto h6 = ListNode(6, &h7);
  auto h5 = ListNode(5, &h6);
  auto h4 = ListNode(4, &h5);
  auto h3 = ListNode(3, &h4);
  auto h2 = ListNode(2, &h3);
  auto head = ListNode(1, &h2);
  const auto res = swapPairs(&head);

  cout << res->val;
}
