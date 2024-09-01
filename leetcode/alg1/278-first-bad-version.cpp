#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int firstBadVersion(int n) {
    long int middle;
    long int first = 1, last = n;
    while (first <= last) {
      middle = (last + first) / 2;
      if (isBadVersion(middle)) {
        last = middle - 1;
      } else {
        first = middle + 1;
      }
    }
    return first;
  }

  int isBadVersion(int version) {}
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
