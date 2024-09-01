#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> s1, vector<int> s2) {
  int size1 = s1.size(), size2 = s2.size();
  int i = 0, j = 0;
  vector<int> result;
  while (i < size1 && j < size2) {
    if (s1[i] < s2[j]) {
      result.push_back(s1[i++]);
    } else {
      result.push_back(s2[j++]);
    }
  }

  while (i < size1) {
    result.push_back(s1[i++]);
  }

  while (j < size2) {
    result.push_back(s2[j++]);
  }

  return result;
}

vector<int> mergeSort(vector<int> v, int begin, int end) {
  if (begin >= end) {
    vector<int> cp = {v[begin]};
    return cp;
  }

  int mid = (begin + end) / 2;
  vector<int> left = mergeSort(v, begin, mid);
  vector<int> right = mergeSort(v, mid + 1, end);

  return merge(left, right);
}

int main(int argc, char *argv[]) {
  vector<int> arr = {2, 4, 1, 6, 8, 4, 3, 5, 9};
  auto result = mergeSort(arr, 0, (arr.size() - 1));
  for (auto c : result) {
    cout << c << " ";
  }
  cout << endl;
  return 0;
}
