// 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
//
// 思路：虚拟头节点

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

ListNode* removeElements(ListNode* head, int val) {
  auto vhead = ListNode(0, head);
  auto curr = &vhead;

  while (curr->next != nullptr) {
    if (curr->next->val == val) {
      auto oldNode = curr->next;
      curr->next = curr->next->next;
      delete oldNode;
    } else
      curr = curr->next;
  }

  return vhead.next;
}

int main() {
  auto h7 = ListNode(6);
  auto h6 = ListNode(5, &h7);
  auto h5 = ListNode(4, &h6);
  auto h4 = ListNode(3, &h5);
  auto h3 = ListNode(6, &h4);
  auto h2 = ListNode(2, &h3);
  auto head = ListNode(1, &h2);
  const auto res = removeElements(&head, 6);

  cout << res->val;
}
