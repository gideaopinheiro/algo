#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<set<int>> conj(27);
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') {
          continue;
        }
        if (conj[i].count(board[i][j]) || conj[j + 9].count(board[i][j]) ||
            conj[((i / 3) * 3) + (j / 3) + 18].count(board[i][j])) {
          return false;
        }

        conj[i].insert(board[i][j]);
        conj[j + 9].insert(board[i][j]);
        conj[((i / 3) * 3) + (j / 3) + 18].insert(board[i][j]);
      }
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> arr(9, 0);
  cout << arr.size() << endl;
  cout << arr[0] << endl;
  return 0;
}
