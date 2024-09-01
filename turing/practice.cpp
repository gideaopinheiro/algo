#include <string>
#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
  public:
  int calPoints(vector<string> ops) {
    int totalSum = 0;
    int sOpt = ops.size();
    vector<int> scores;
    for (int i = 0; i < sOpt; i++) {
       if (ops[i].compare("+") == 0) {
        int s = scores.size();
        scores.push_back(scores[s-1] + scores[s-2]);
      } else if (ops[i].compare("D") == 0) {
        scores.push_back(2 * scores.back());
      } else if (ops[i].compare("C") == 0) {
        scores.pop_back();
      } else  {
        int temp;
        std:istringstream iss(ops[i]);
        iss >> temp;
        scores.push_back(temp);
      }
    }

    for (auto c : scores) {
      totalSum += c;
    }
    return totalSum;
  }
};

int main() {
  vector<string> items = {"5", "2", "C", "D", "+"};
  Solution solution;
  cout << solution.calPoints(items) << endl;
  return 0;
}