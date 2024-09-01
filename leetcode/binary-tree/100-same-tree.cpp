#include <iostream>
#include <stack>

/*
Given the roots of two binary trees p and q, write a function to check if they
are the same or not.

Two binary trees are considered the same if they are structurally identical, and
the nodes have the same value.
*/

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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    string first = preOrderTraversal(p);
    string second = preOrderTraversal(q);
    return !first.compare(second);
  }

  string preOrderTraversal(TreeNode *root) {
    if (root == NULL)
      return "";
    stack<TreeNode *> nodes;
    nodes.push(root);
    string result = "";

    while (!nodes.empty()) {
      TreeNode *current = nodes.top();
      nodes.pop();

      result += to_string(current->val);

      if (current->left != NULL) {
        nodes.push(current->left);
      } else {
        result += "$";
      }

      if (current->right != NULL) {
        nodes.push(current->right);
      } else {
        result += "#";
      }
    }
    return result;
  }
};