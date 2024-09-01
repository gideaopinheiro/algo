#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    if ((mat.size() * mat[0].size()) != (r * c)) {
      return mat;
    }

    vector<vector<int>> newMatrix(r, vector<int>(c));
    int k = 0, l = 0;
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[0].size(); j++) {
        newMatrix[k][l] = mat[i][j];
        if (l == c - 1) {
          l = 0;
          k++;
        } else {
          l++;
        }
      }
    }
    return newMatrix;
  }
};

void print_matrix(vector<vector<int>> &mat) {
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  vector<vector<int>> matrix = {{1, 2, 3, 4}};
  vector<vector<int>> result = sol->matrixReshape(matrix, 2, 2);
  print_matrix(result);
  return 0;
}
