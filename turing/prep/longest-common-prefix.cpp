#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string currentPrefix = "";
    char currentChar = strs[0][0];
    int amountStrings = strs.size();
    for (int i = 0; i < 200; i++) {
      currentChar = strs[0][i];
      for (int j = 0; j < amountStrings; j++) {
        if ((i >= strs[j].size()) || (strs[j][i] != currentChar)) {
          return currentPrefix;
        }
      }
      currentPrefix.append(string(1, currentChar));
    }
    cout << currentPrefix << endl;
    return currentPrefix;
  }
};

int main(int argc, char *argv[]) {
  Solution *sol = new Solution();
  vector<string> arr = {"flower", "flow", "flight"};
  string result = sol->longestCommonPrefix(arr);
  cout << result << endl;

  return 0;
}
