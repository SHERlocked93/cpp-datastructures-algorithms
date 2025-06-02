// 思路：左中右

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
  traverse(node->left, vec);
  vec.push_back(node->val);
  traverse(node->right, vec);
}

// 迭代方式
vector<int> inorderTraversal(TreeNode *root) {
  vector<int> res;
  traverse(root, res);
  return res;
}

// 非迭代方式，构建中右左然后反转结果
vector<int> inorderTraversal2(TreeNode *root) {
  vector<int> res;
  stack<TreeNode *> sta_;

  while (root != nullptr || !sta_.empty()) {
    while (root != nullptr) {
      root = root->left;
      sta_.push(root);
    }
    root = sta_.top();
    sta_.pop();
    res.push_back(root->val);
    root = root->right;
  }

  return res;
}

int main() {}
