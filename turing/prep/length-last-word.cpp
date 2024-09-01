#include <iostream>
#include <string>
#include <vector>
using namespace std;

// problem 58

class Solution {
public:
  int lengthOfLastWord(string s) {
    vector<string> strings;
    string temporary = "";
    for (char c : s) {
      if (c == ' ') {
        if (temporary.size() > 0) {
          strings.push_back(temporary);
        }
        temporary.clear();
      } else {
        temporary += c;
      }
    }
    if (temporary.size() > 0) {
      strings.push_back(temporary);
    }
    return strings[strings.size() - 1].size();
  }
};

int main(int argc, char *argv[]) { 
  string s = "   fly me   to   the moon  ";
  string s2 = "luffy is still joyboy";
  string s3 = "Hello World";
  Solution *sol = new Solution();
  cout << sol->lengthOfLastWord(s3) << endl;
  return 0; }
