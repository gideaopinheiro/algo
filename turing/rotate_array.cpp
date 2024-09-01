#include <iostream>
#include <vector>
using namespace std;

vector<int> rotate() {
  vector<int> arr = {-1, -100, 3, 99};
  int k = 2;

  string a = "açslkdjfaljf";
  a.length()

  vector<int> temp;
  int size = arr.size();

  for (int i = k + 1; i < size; i++) {
    temp.push_back(arr[i]);
  }

  for (int i = 0; i <= k; i++) {
    temp.push_back(arr[i]);
  }

  for (auto c : temp) {
    cout << c << " ";
  }
  cout << endl;

  return temp;
}

int main(int argc, char const *argv[]) {
  rotate();
  return 0;
}
