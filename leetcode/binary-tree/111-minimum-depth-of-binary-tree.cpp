#include <iostream>
#include <limits>
#include <queue>
using namespace std;

// A SOLUÇÃO RECURSIVA ESTÁ CORRETA
// A ITERATIVA ESTÁ INCOMPLETA

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// RECURSIVA
// class Solution {
// public:
//   int minDepth(TreeNode *root) {
//     if (root == NULL) {
//       return 0;
//     }
//     return calculate(root);
//   }

//   int calculate(TreeNode *node) {
//     if (node == NULL) {
//       return numeric_limits<int>::max();
//     }
//     if (node->left == NULL && node->right == NULL) {
//       return 1;
//     }
//     return 1 + min(calculate(node->left), calculate(node->right));
//   }
// };

// ITERATIVA
class Solution {
public:
  int minDepth(TreeNode *root) {

    if (root == NULL) {
      return 0;
    }
    queue<TreeNode *> nodes;
    nodes.push(root);
    int depth = 1;

    while (!nodes.empty()) {
      TreeNode *current = nodes.front();

      if (current->right != NULL) {
        nodes.push(current->right);
      } else {
        break;
      }

      if (current->left != NULL) {
        nodes.push(current->left);
      } else {
        break;
      }
      depth++;
    }
    return depth;
  }
};

int main(int argc, char const *argv[]) {
  TreeNode *e = new TreeNode(4);
  TreeNode *f = new TreeNode(4);
  TreeNode *g = new TreeNode(3);
  TreeNode *d = new TreeNode(3, NULL, e);
  TreeNode *c = new TreeNode(2, NULL, d);
  TreeNode *b = new TreeNode(2, NULL, c);
  TreeNode *a = new TreeNode(1, NULL, b);

  Solution *solution = new Solution();
  cout << solution->minDepth(a) << endl;

  return 0;
}
