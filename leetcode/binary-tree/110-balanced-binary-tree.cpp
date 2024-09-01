#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (root == NULL) {
      return true;
    }

    stack<TreeNode *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
      TreeNode *current = nodes.top();
      nodes.pop();

      bool notBalanced =
          abs((depthNode(current->left) - depthNode(current->right)) > 1);

      if (notBalanced) {
        return false;
      }

      if (current->right != NULL)
        nodes.push(current->right);
      if (current->left != NULL)
        nodes.push(current->left);
    }

    return true;
  }

  int depthNode(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    return 1 + max(depthNode(root->left), depthNode(root->right));
  }
};

int main(int argc, char const *argv[]) { return 0; }
