#include <bits/stdc++.h>
using namespace std;

//@TODO: Fazer os outros casos listados na página do problema
class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> finalArr;
    for (int i = 0; i < nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        if (nums1[i] == nums2[j] && (nums1[i] != -1)) {
          finalArr.push_back(nums1[i]);
          nums1[i] = nums2[j] = -1;
        }
      }
    }
    return finalArr;
  }
};

void printVector(vector<int> arr) {
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  vector<int> arr1 = {4, 9, 5};
  vector<int> arr2 = {9, 4, 9, 8, 4};
  Solution *sol = new Solution();
  printVector(sol->intersect(arr1, arr2));
  return 0;
}
