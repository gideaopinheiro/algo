#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int hackerlandRadioTransmitters(vector<int> houses, int k) {
  sort(houses.begin(), houses.end());
  int transmitters = 0, coverage = 0;

  for (int i = 0, j = i + 1; j < houses.size();) {
    if (houses[i] <= coverage) {
      i++;
      j++;
      continue;
    }
    int distance = abs(houses[i] - houses[j]);
    if (distance > k) {
      // tag houses[i]
      coverage = houses[i] + k;
      i = j;
      j++;
      transmitters++;
    } else if (distance == k) {
      // tag houses[j]
      i = j;
      j++;
      coverage = houses[i] + k;
      transmitters++;
    } else {
      j++;
    }
  }
  if (houses[(houses.size() - 1)] > coverage)
    transmitters++;
  return transmitters;
}

int main(int argc, char const *argv[]) {
  vector<int> arr = {7, 2, 4, 6, 5, 9, 12, 11};
  // vector<int> arr = {1, 2, 3, 4, 5};
  int qtd = hackerlandRadioTransmitters(arr, 2);
  cout << qtd << endl;
  return 0;
}
