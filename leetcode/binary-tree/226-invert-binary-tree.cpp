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
  TreeNode *invertTree(TreeNode *root) {
    if (root == NULL) {
      return root;
    }

    stack<TreeNode *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
      TreeNode *current = nodes.top();
      nodes.pop();

      if (current->left != NULL) {
        nodes.push(current->left);
      }

      if (current->right != NULL) {
        nodes.push(current->right);
      }

      TreeNode *temp = current->left;
      current->left = current->right;
      current->right = temp;
      temp = NULL;
      delete temp;
    }
    return root;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
