#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> mapT;
    unordered_map<char, int> mapS;

    if (s.size() != t.size()) {
      return false;
    }

    for (auto i : t) {
      mapT[i]++;
    }
    for (auto j : s) {
      mapS[j]++;
    }

    for (auto k : t) {
      if (mapT[k] != mapS[k]) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  string s = "anagram";
  string t = "nagaram";
  // sol->isAnagram(s, t);
  cout << sol->isAnagram(s, t) << endl;
  return 0;
}
