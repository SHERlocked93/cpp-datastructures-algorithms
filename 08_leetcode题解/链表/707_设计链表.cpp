// 你可以选择使用单链表或者双链表，设计并实现自己的链表。
// 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
// 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

#include <iostream>
#include <memory>
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

class MyLinkedList {
 public:
  MyLinkedList() {}

  int get(int index) {
    if (index > size - 1) return -1;
    ListNode* curr = vhead;
    while (index-- && curr->next) {
      curr = curr->next;
    }
    return curr->next->val;
  }

  void addAtHead(int val) {
    if (!vhead) vhead = new ListNode(0);
    const auto oldNext = vhead->next;
    vhead->next = new ListNode(val, oldNext);
    size++;
  }

  void addAtTail(int val) {
    if (!vhead) vhead = new ListNode(0);
    ListNode* curr = vhead;
    while (curr->next) {
      curr = curr->next;
    }
    size++;
    const auto newNode = new ListNode(val);
    curr->next = newNode;
  }

  void addAtIndex(int index, int val) {
    if (!vhead) {
      vhead = new ListNode(0);
      if (index == 0) return addAtHead(val);
      return;
    }

    ListNode* curr = vhead;
    while (index-- && curr->next) {
      curr = curr->next;
    }
    if (index >= 0) return;
    size++;
    const auto newNode = new ListNode(val, curr->next);
    curr->next = newNode;
  }

  void deleteAtIndex(int index) {
    if (index > size - 1) return;
    ListNode* curr = vhead;
    while (index-- && curr->next) {
      curr = curr->next;
    }
    if (index >= 0) return;
    size--;
    auto temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
  }

 private:
  int size = 0;
  ListNode* vhead = nullptr;
};

int main() {
  const auto mll = make_shared<MyLinkedList>();
  int ret = 0;

  mll->addAtHead(4);
  ret = mll->get(1);
  mll->addAtTail(3);
  // mll->addAtIndex(1, 2);
  ret = mll->get(0);
  mll->deleteAtIndex(1);
  ret = mll->get(1);
}
