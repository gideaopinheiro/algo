#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int middle, begin = 0, end = nums.size() - 1;
    while (begin <= end) {
      middle = (begin + end) / 2;
      if (nums[middle] == target) {
        return middle;
      } else if (nums[middle] < target) {
        begin = middle + 1;
      } else {
        end = middle - 1;
      }
    }
    return begin;
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  vector<int> arr = {1, 3, 5, 6};
  cout << sol->searchInsert(arr, 7) << endl;
  return 0;
}
