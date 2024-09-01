#include <iostream>
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

// class Solution {
// public:
//   vector<int> result;
//   vector<int> preorderTraversal(TreeNode *root) {
//     if (root == NULL) {
//       return {};
//     }

//     stack<TreeNode *> nodes;
//     nodes.push(root);

//     while (!nodes.empty()) {
//       TreeNode *current = nodes.top();
//       nodes.pop();

//       result.push_back(current->val);

//       if (current->right != NULL) {
//         nodes.push(current->right);
//       }
//       if (current->left != NULL) {
//         nodes.push(current->left);
//       }
//     }

//     return result;
//   }
// };

class Solution {
public:
  vector<int> result;
  vector<int> preorderTraversal(TreeNode *root) {
    if (root == NULL) {
      return {};
    }
    solve(root);
    return result;
  }

  void solve(TreeNode *node) {
    if (node == NULL) {
      return;
    }
    result.push_back(node->val);
    solve(node->left);
    solve(node->right);
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
