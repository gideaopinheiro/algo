/*

Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.


Example 1:

Input: n = 3
Output: ["1","2","Fizz"]

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> response;
    for (int i = 1; i <= n; i++) {
      string partial;
      if (i % 3 == 0) {
        partial.append("Fizz");
      }
      if (i % 5 == 0) {
        partial.append("Buzz");
      }
      if (!(i % 3 == 0) && !(i % 5 == 0)) {
        partial.append(to_string(i));
      }
      response.push_back(partial);
    }
    return response;
  }
};

int main(int argc, char const *argv[]) {
  Solution *sl;
  vector<string> response = sl->fizzBuzz(15);
  cout << "[ ";
  for (auto s : response) {
    cout << s << ", ";
  }
  cout << " ]" << endl;
  return 0;
}
