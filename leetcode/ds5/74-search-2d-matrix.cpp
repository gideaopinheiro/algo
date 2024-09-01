#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int len = matrix[0].size();
    for (int i = 0; i < matrix.size(); i++) {
      if (matrix[i][len - 1] >= target) {
        int init = 0, end = len;
        int middle;
        while (init <= end) {
          middle = (init + end) / 2;
          if (matrix[i][middle] > target) {
            end = middle - 1;
          } else if (matrix[i][middle] < target) {
            init = middle + 1;
          } else {
            return true;
          }
        }
        return false;
      }
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  Solution *sol = new Solution();
  bool result = sol->searchMatrix(matrix, 13);
  cout << result << endl;
  return 0;
}
