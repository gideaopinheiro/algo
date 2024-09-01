#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  // vector<int> twoSum(vector<int> &nums, int target) {
  //   vector<int> positions;
  //   for (int i = 0; i < nums.size() - 2; i++) {
  //     for (int j = i + 1; j < nums.size() - 1; j++) {
  //       if (nums[i] + nums[j] == target) {
  //         positions.push_back(i);
  //         positions.push_back(j);
  //         break;
  //       }
  //     }
  //   }
  //   return positions;
  // }

  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> ans;
    for (int i = 0; i < nums.size(); i++) {
      if (ans.find((target - nums[i])) != ans.end()) {
        return {i, ans[target - nums[i]]};
      }
      ans.insert(pair<int, int>(nums[i], i));
    }
    return {-1, -1};
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  vector<int> arr = {3, 2, 4};
  vector<int> result = sol->twoSum(arr, 6);
  cout << "[" << result[0] << "," << result[1] << "]" << endl;
  return 0;
}
