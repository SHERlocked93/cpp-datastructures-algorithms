// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
//
// 思路：双指针，记录前一个指针和当前指针

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

ListNode* reverseList(ListNode* head) {
  ListNode* pre = nullptr;
  ListNode* curr = head;

  while (curr != nullptr) {
    auto temp = curr->next;
    curr->next = pre;

    pre = curr;
    curr = temp;
  }
  return pre;
}

int main() {
  auto h7 = ListNode(7);
  auto h6 = ListNode(6, &h7);
  auto h5 = ListNode(5, &h6);
  auto h4 = ListNode(4, &h5);
  auto h3 = ListNode(3, &h4);
  auto h2 = ListNode(2, &h3);
  auto head = ListNode(1, &h2);
  const auto res = reverseList(&head);

  cout << res->val;
}
