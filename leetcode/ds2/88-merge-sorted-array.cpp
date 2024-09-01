#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int k = ((m + n) - 1);
    int posi = m - 1;
    int posj = n - 1;

    while (posi >= 0 && posj >= 0) {
      if (nums1[posi] >= nums2[posj]) {
        nums1[k--] = nums1[posi--];
      } else {
        nums1[k--] = nums2[posj--];
      }
    }
    while (posi >= 0) {
      nums1[k--] = nums1[posi--];
    }
    while (posj >= 0) {
      nums1[k--] = nums2[posj--];
    }

    for (auto i : nums1) {
      cout << i << " ";
    }
    cout << endl;
  }

  int smallestBetween(int a, int b) { return (a < b) ? a : b; }
};

int main(int argc, char const *argv[]) {
  Solution *sol = new Solution();
  vector<int> num1 = {2, 0};
  vector<int> num2 = {1};
  sol->merge(num1, 1, num2, 1);
  return 0;
}
