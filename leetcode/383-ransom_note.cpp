#include <iostream>
#include <map>
using namespace std;

/*

Given two strings ransomNote and magazine,
return true if ransomNote can be constructed
from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

*/

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
  Solution *sl;
  cout << (sl->canConstruct("a", "a") ? "Sim" : "Não") << endl;
  return 0;
}
