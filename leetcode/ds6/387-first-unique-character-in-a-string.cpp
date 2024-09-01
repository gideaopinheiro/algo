#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    unordered_map<char, int> result;
    for (auto i : s) {
      if (result.find(i) == result.end()) {
        result.insert(pair<char, int>(i, 1));
      } else {
        result[i]++;
      }
    }
    for (int i = 0; i < s.size(); i++) {
      if (result[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};

int main(int argc, char const *argv[]) {
  string s = "aabb";
  Solution *sol = new Solution();
  cout << sol->firstUniqChar(s) << endl;
  return 0;
}
