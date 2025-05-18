// 删除链表倒数第N个节点
//
// 思路：双指针，慢指针比快指针慢N+1个节点，这样的话慢指针指向的下一个节点就是要删的节点

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

ListNode* removeNthFromEnd(ListNode* head, int n) {
  auto vhead = new ListNode(0, head);
  int pren = n ;
  auto fastPtr = vhead;

  while (fastPtr->next && pren--) {
    fastPtr = fastPtr->next;
  }
  auto slowPtr = vhead;
  while (fastPtr->next) {
    fastPtr = fastPtr->next;
    slowPtr = slowPtr->next;
  }

  if (slowPtr->next) {
    auto temp = slowPtr->next;
    slowPtr->next = temp->next;
    delete temp;
  }

  return vhead->next;
}

int main() {
  // auto h7 = ListNode(7);
  // auto h6 = ListNode(6, &h7);
  // auto h5 = ListNode(5, &h6);
  // auto h4 = ListNode(4, &h5);
  // auto h3 = ListNode(3, &h4);
  auto h2 = ListNode(2);
  auto head = ListNode(1, &h2);
  const auto res = removeNthFromEnd(&head, 2);

  cout << res->val;
}
