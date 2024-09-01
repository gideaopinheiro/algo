#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool buddyStrings(string s, string goal) {
    if (s.size() != goal.size())
      return false;
    if (s.compare(goal) == 0) {
      int count[26] = {0};
      for (int i = 0; i < s.size(); i++) {
        count[s.at(i) - 'a']++;
      }

      for (auto i : count) {
        if (i > 1)
          return true;
      }
      return false;
    } else {
      int first = -1, second = -1;
      for (int i = 0; i < s.size(); i++) {
        if (s.at(i) != goal.at(i)) {
          if (first < 0) {
            first = i;
          } else if (second < 0) {
            second = i;
          } else {
            return false;
          }
        }
      }
      return (second != -1 && s.at(first) == goal.at(second) &&
              s.at(second) == goal.at(first));
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  cout << sol->buddyStrings("ab", "ba") << endl;
  return 0;
}
