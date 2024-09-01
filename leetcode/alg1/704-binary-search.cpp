#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /*utilizando recursão*/
  // int search(vector<int> &nums, int target) {
  //   return solucao(nums, 0, nums.size() - 1, target);
  // }

  // int solucao(vector<int> &nums, int b, int e, int target) {
  //   if (b > e) {
  //     return -1;
  //   }
  //   int middle = (b + e) / 2;
  //   if (nums[middle] < target) {
  //     return solucao(nums, middle + 1, e, target);
  //   } else if (nums[middle] > target) {
  //     return solucao(nums, b, middle - 1, target);
  //   } else {
  //     return middle;
  //   }
  // }

  int search(vector<int> &nums, int target) {
    int middle, left = 0, right = nums.size() - 1;
    while (left <= right) {
      middle = (left + right) / 2;
      if (nums[middle] == target) {
        return middle;
      } else if (nums[middle] < target) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
    return -1;
  }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  vector<int> arr = {-1, 0, 3, 5, 9, 12};
  cout << sol->search(arr, 9) << endl;
  return 0;
}
