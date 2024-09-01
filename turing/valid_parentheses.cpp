/*
Given a string s containing just the caracteres '(', ')', '[', ']', '{', '}'
determine if the input string is valid. An input string is valid if Open
brackets must be closed by the same type of brackets Open brackets must be
closed in the correct order


constraints:
  1 <= s.length <= 104
  s consists of parentheses only '()[]{}'

  ex 1:
  s = '()'
  valid


  ex 2:
  s = '() [] {}'
  valid

  ex 3:
  s = '(]'
  invalid
*/

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> valid_brackets;
    unordered_map<char, char> brackets;
    brackets.insert(pair<char, char>(')', '('));
    brackets.insert(pair<char, char>(']', '['));
    brackets.insert(pair<char, char>('}', '{'));

    for (auto c : s) {
      if (c == '(' || c == '[' || c == '{') {
        valid_brackets.push(c);
        continue;
      }
      if (valid_brackets.empty() || (valid_brackets.top() != brackets.at(c))) {
        return false;
      }

      valid_brackets.pop();
    }
    return valid_brackets.empty();
  }
};

int main(int argc, char *argv[]) {
  Solution *sol = new Solution();
  cout << sol->isValid("([{()}]){}") << endl;
  return 0;
}
