#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascalTriangle(numRows);
    pascalTriangle[0].push_back(1);
    for (int i = 1; i < numRows; i++) {
      for (int j = 0; j <= i; j++) {
        if (j == 0) {
          pascalTriangle[i].push_back(1);
        } else if (j == i) {
          pascalTriangle[i].push_back(1);
        } else {
          pascalTriangle[i].push_back(
              (pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j]));
        }
      }
    }
    return pascalTriangle;
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  vector<vector<int>> pascalTriangle = sol->generate(1);
  return 0;
}
