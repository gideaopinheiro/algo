#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int size = nums.size();
    if (size <= 1)
      return;
    int left = 0, right = left + 1;
    while (right < size) {
      if ((nums[left] == 0) && (nums[right] != 0)) {
        nums[left] = nums[right];
        nums[right] = 0;
        left++;
        right++;
      } else if ((nums[left] == 0) && nums[right] == 0) {
        right++;
      } else {
        left++;
        right++;
      }
    }

    for (auto i : nums) {
      cout << i << " ";
    }
    cout << endl;
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  vector<int> arr = {0, 1, 0, 3, 12};
  sol->moveZeroes(arr);
  return 0;
}
