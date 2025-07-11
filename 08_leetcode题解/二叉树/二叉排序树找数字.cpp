// 在一个二叉搜索树中找一个数字，如果有大于等于这个数字的，返回其中的最小值，如果没有返回 nullptr

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 在 BST 中查找大于或等于目标值的最小节点
TreeNode* findSmallestGreaterOrEqual(TreeNode* root, int goal) {
  TreeNode* res = nullptr;

  while (root) {
    if (root->val == goal)
      return root;
    if (root->val > goal) {
      res = root;
      root = root->left;
    } else {
      root = root->right;
    }
  }

  return res;
}
