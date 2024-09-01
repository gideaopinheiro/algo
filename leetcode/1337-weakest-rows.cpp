/*
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's
(representing civilians). The soldiers are positioned in front of the civilians.
That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to
strongest.

Input: mat =
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]],
k = 3
Output: [2,0,3]
Explanation:
The number of soldiers in each row is:
- Row 0: 2
- Row 1: 4
- Row 2: 1
- Row 3: 2
- Row 4: 5
The rows ordered from weakest to strongest are [2,0,3,1,4].
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  static bool sortByVal(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.second > b.second);
  }

  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    vector<pair<int, int>> weakestVec;
    for (int i = 0; i < mat.size(); i++) {
      int civilianCounter = 0;
      for (int j = 0; j < mat[i].size(); j++) {
        if (mat[i][j] == 0)
          civilianCounter++;
      }
      weakestVec.push_back(make_pair(i, civilianCounter));
    }
    sort(weakestVec.begin(), weakestVec.end(), sortByVal);
    vector<int> result;
    for (int i = 0; i < k; i++) {
      result.push_back(weakestVec[i].first);
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  vector<vector<int>> mat = {{1, 1, 0, 0, 0},
                             {1, 1, 1, 1, 0},
                             {1, 0, 0, 0, 0},
                             {1, 1, 0, 0, 0},
                             {1, 1, 1, 1, 1}};
  vector<vector<int>> mat2 = {
      {1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}};

  Solution *sol = new Solution();
  vector<int> result = sol->kWeakestRows(mat2, 2);
  cout << "[";
  for (int i = 0; i < result.size() - 1; i++) {
    cout << result[i] << ",";
  }
  cout << result[result.size() - 1] << "]" << endl;
  return 0;
}
