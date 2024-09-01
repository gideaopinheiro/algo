#include <iostream>
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
  vector<int> result;
  vector<int> postorderTraversal(TreeNode *root) {
    if (root == NULL) {
      return {};
    }

    solve(root);
    return result;
  }

  void solve(TreeNode *root) {
    if (root == NULL) {
      return;
    }

    solve(root->left);
    solve(root->right);
    result.push_back(root->val);
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
