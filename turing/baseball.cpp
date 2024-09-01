#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 5 2 C D +

class Solution {
public:
  int calPoints(vector<string> ops) {
    int overall = 0;
    vector<int> scores;
    for (int i = 0; i < ops.size(); i++) {
      if (ops[i] == "+") {
        scores.push_back(
            (scores[scores.size() - 1] + scores[scores.size() - 2]));
      } else if (ops[i] == "C") {
        scores.pop_back();
      } else if (ops[i] == "D") {
        scores.push_back((scores.back() * 2));
      } else {
        scores.push_back(stoi(ops[i]));
      }
    }

    for (auto s : scores) {
      overall += s;
    }
    return overall;
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  vector<string> scores = {"5", "2", "C", "D", "+"};
  cout << sol->calPoints(scores) << endl;
  return 0;
}
