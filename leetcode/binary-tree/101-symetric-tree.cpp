#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

// IMCOMPLETO

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
  string result = "";
  string leftString = "";
  string rightString = "";

  bool isSymmetric(TreeNode *root) {
    preOrderTraversal(root->left, &leftString);
    posOrderTraversal(root->right, &rightString);

    cout << leftString << endl;
    cout << rightString << endl;

    reverse(rightString.begin(), rightString.end());

    return !leftString.compare(rightString);
  }

  void preOrderTraversal(TreeNode *root, string *resultString) {
    if (root == NULL) {
      return;
    }

    *resultString += to_string(root->val);
    if (root->left == NULL && root->right != NULL) {
      *resultString += "$";
    }
    if (root->right == NULL && root->left != NULL) {
      *resultString += "$";
    }
    preOrderTraversal(root->left, resultString);
    preOrderTraversal(root->right, resultString);
  }

  void posOrderTraversal(TreeNode *root, string *resultString) {
    if (root == NULL) {
      return;
    }

    if (root->left == NULL && root->right != NULL) {
      *resultString += "$";
    }

    posOrderTraversal(root->left, resultString);

    if (root->right == NULL && root->left != NULL) {
      *resultString += "$";
    }

    posOrderTraversal(root->right, resultString);

    *resultString += to_string(root->val);
  }
};

int main(int argc, char const *argv[]) {

  // TreeNode *d = new TreeNode(3);
  // TreeNode *e = new TreeNode(4);
  // TreeNode *f = new TreeNode(4);
  // TreeNode *g = new TreeNode(3);
  // TreeNode *b = new TreeNode(2, d, e);
  // TreeNode *c = new TreeNode(2, f, g);
  // TreeNode *a = new TreeNode(1, b, c);

  // TreeNode *e = new TreeNode(2);
  // TreeNode *f = new TreeNode(2);
  // TreeNode *b = new TreeNode(2, NULL, e);
  // TreeNode *c = new TreeNode(2, f, NULL);
  // TreeNode *a = new TreeNode(1, b, c);

  // TreeNode *e = new TreeNode(3);
  // TreeNode *g = new TreeNode(3);
  // TreeNode *b = new TreeNode(2, NULL, e);
  // TreeNode *c = new TreeNode(2, NULL, g);
  // TreeNode *a = new TreeNode(1, b, c);

  TreeNode *d = new TreeNode(2);
  TreeNode *f = new TreeNode(2);
  TreeNode *b = new TreeNode(2, d, NULL);
  TreeNode *c = new TreeNode(2, f, NULL);
  TreeNode *a = new TreeNode(1, b, c);

  Solution *sol = new Solution();
  cout << sol->isSymmetric(a) << endl;
  return 0;
}
