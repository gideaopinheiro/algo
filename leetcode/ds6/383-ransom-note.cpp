#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.length() > magazine.length())
      return false;
    map<char, int> ransomMap;
    map<char, int> magazineMap;
    for (auto c : ransomNote)
      ransomMap[c] += 1;
    for (auto c : magazine)
      magazineMap[c] += 1;

    for (auto c : ransomNote) {
      if (ransomMap[c] > magazineMap[c]) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  string a = "aa";
  string b = "bb";
  cout << sol->canConstruct(a, b) << endl;
  return 0;
}
