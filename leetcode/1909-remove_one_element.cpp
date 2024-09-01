/*
Given a 0-indexed integer array nums, return true if it can be made strictly
increasing after removing exactly one element, or false otherwise. If the array
is already strictly increasing, return true.

The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1
<= i < nums.length).



Example 1:

Input: nums = [1,2,10,5,7]
Output: true
Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
[1,2,5,7] is strictly increasing, so return true.


[2,3,1,2] -> false
[1,1,1] -> false
[9,2,3,4] -> true
*/

#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  bool canBeIncreasing(vector<int> &nums) {
    int count = 0;
    int j = 0;
    vector<int>::iterator it;
    for (j = 1, it = nums.begin(); it != nums.end(); it++, j++) {
      if (nums[j - 1] >= nums[j]) {
        nums.erase(it);
        return increasing(nums);
      }
    }
    return true;
  }

  bool increasing(vector<int> &nums) {
    for (int i = 0, j = 1; j < nums.size(); i++, j++) {
      if (nums[i] >= nums[j]) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  Solution sl;
  vector<int> arr = {1, 2};
  cout << sl.canBeIncreasing(arr) << endl;
  return 0;
}
