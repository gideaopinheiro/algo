#include <iostream>
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
  int maxDepth(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};

int main(int argc, char const *argv[]) {
  TreeNode *d = new TreeNode(3);
  TreeNode *e = new TreeNode(4);
  TreeNode *f = new TreeNode(4);
  TreeNode *g = new TreeNode(3);
  TreeNode *b = new TreeNode(2, d, e);
  TreeNode *c = new TreeNode(2, f, g);
  TreeNode *a = new TreeNode(1, b, c);

  Solution *solution = new Solution();
  cout << solution->maxDepth(a) << endl;

  return 0;
}
