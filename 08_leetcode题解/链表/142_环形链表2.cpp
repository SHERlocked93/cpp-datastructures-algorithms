// 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//
// 思路：快慢指针，快指针会在圈里追上慢指针

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

ListNode* detectCycle(ListNode* head) {
  bool hasCycl = false;
  ListNode *fast = head, *slow = head;
  while (fast && fast->next && fast->next->next) {
    fast = fast->next->next;
    slow = slow->next;

    if (fast == slow) {
      hasCycl = true;
      break;
    }
  }
  if (!hasCycl)
    return NULL;
  fast = head;
  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }
  return fast;
}

int main() {
  auto h6 = ListNode(6);
  auto h5 = ListNode(5, &h6);
  auto h4 = ListNode(4, &h5);
  auto h3 = ListNode(3, &h4);
  h6.next = &h3;
  auto h2 = ListNode(2, &h3);
  auto head = ListNode(1, &h2);
  const auto res = detectCycle(&head);

  cout << res->val;
}
