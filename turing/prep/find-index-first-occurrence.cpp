#include <iostream>
#include <string>
using namespace std;

// leetcode problem 28

class Solution {
public:
  int strStr(string haystack, string needle) {
    // sadbutsad    sad
    // abpratoui    prato
    if (needle.size() > haystack.size()) {
      return -1;
    }

    int hSize = haystack.size();
    int nSize = needle.size();
    int counter = 0;
    for (int i = 0, j = 0; i < hSize; i++) {
      if(!haystack.substr(i, nSize).compare(needle)) {
        return i;
      };
    }
    return -1;
  }
};

int main(int argc, char *argv[]) { 
  Solution *sol = new Solution();
  string s1 = "gideao";
  string s2 = "gid";
  cout << sol->strStr("gideao", "gid") << endl;
  return 0; }
