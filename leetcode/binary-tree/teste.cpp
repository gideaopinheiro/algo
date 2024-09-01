#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  string a = "abc";
  reverse(a.begin(), a.end());
  cout << a << endl;
  return 0;
}
