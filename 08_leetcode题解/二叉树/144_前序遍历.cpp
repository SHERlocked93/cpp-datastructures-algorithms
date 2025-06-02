// 思路：中左右

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverse(TreeNode *node, vector<int> &vec) {
  if (node == nullptr)
    return;
  vec.push_back(node->val);
  traverse(node->left, vec);
  traverse(node->right, vec);
}

// 迭代方式
vector<int> preorderTraversal(TreeNode *root) {
  vector<int> res;
  traverse(root, res);
  return res;
}

// 非迭代方式
vector<int> preorderTraversal2(TreeNode *root) {
  vector<int> res;

  stack<TreeNode *> sta_;
  if (root == nullptr)
    return res;
  res.push_back(root->val);
  sta_.push(root->right);
  sta_.push(root->left);

  while (!sta_.empty()) {
    auto node = sta_.top();
    sta_.pop();
    if (node == nullptr)
      continue;
    res.push_back(node->val);
    sta_.push(node->right);
    sta_.push(node->left);
  }

  return res;
}

int main() {}
