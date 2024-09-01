#include <iostream>
using namespace std;

void solve(int left, int right) {
  int qtdCustomers = 0;
  int customer = 1;
  while (true) {
    if (right > left) {
      if (right < customer) {
        break;
      }
      right -= customer;
      qtdCustomers++;
    } else {
      if (left < customer) {
        break;
      }
      left -= customer;
      qtdCustomers++;
    }
    customer++;
  }
  cout << qtdCustomers << " " << left << " " << right << endl;
}

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int l, r;
    cin >> l >> r;
    cout << "Case #" << i << ": ";
    solve(l, r);
  }
  return 0;
}
