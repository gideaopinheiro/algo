#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    unordered_map<char, char> bracketsClose = {
        {')', '('}, {']', '['}, {'}', '{'}};
    stack<char> parentheses;
    for (auto c : s) {
      if (c == '(' || c == '[' || c == '{') {
        parentheses.push(c);
      } else {
        char temp = parentheses.top();
        if (bracketsClose[c] == temp) {
          parentheses.pop();
          cout << parentheses.size() << endl;
        } else {
          return false;
        }
      }
    }
    return (parentheses.size() == 0);
  }
};

int main(int argc, char *argv[]) {
  string s = "(}";
  Solution *sol = new Solution();
  cout << sol->isValid(s) << endl;
  return 0;
}
