#include <iostream>
#include <queue>
#include <stack>
#include <vector>

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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> inorder;
    queue<TreeNode *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
      TreeNode *current = nodes.back();

      if (current->left == NULL) {
        inorder.push_back(current->val);
      }

      if (current->right != NULL) {
        nodes.push(current->right);
      }
      if (current->left != NULL) {
        nodes.push(current->left);
      }
      nodes.pop();
    }

    return inorder;
  }
};

// vector<int> retorna() { return {}; }

int main(int argc, char const *argv[]) { return 0; }
