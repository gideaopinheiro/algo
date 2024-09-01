#include <string>
#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
  int solution(vector<int>&k) {
    int maxVal = INT_MIN;
    int secondMaxVal = INT_MIN;
    int minVal = INT_MAX;
    int secondMinVal = INT_MAX;

    // Find maximum and minimum values from the array
    for (int i = 0; i < k.size(); ++i) {
        if (k[i] > maxVal) {
            secondMaxVal = maxVal;
            maxVal = k[i];
        } else if (k[i] > secondMaxVal && k[i] != maxVal) {
            secondMaxVal = k[i];
        }

        if (k[i] < minVal) {
            secondMinVal = minVal;
            minVal = k[i];
        } else if (k[i] < secondMinVal && k[i] != minVal) {
            secondMinVal = k[i];
        }
    }

    int maxDiff = (maxVal * secondMaxVal) - (minVal * secondMinVal);
    return maxDiff;
  }
};

int main() {
  vector<int> k = {3,2,1,4,5,6};
  Solution solution;
  cout << solution.solution(k) << endl;
  return 0;
}