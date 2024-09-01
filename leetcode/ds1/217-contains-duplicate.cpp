#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      if (map.find(nums[i]) == map.end()) {
        map[nums[i]] = 1;
      } else {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  vector<int> arr = {1, 2, 3, 3, 4};
  cout << sol->containsDuplicate(arr) << endl;
  return 0;
}
