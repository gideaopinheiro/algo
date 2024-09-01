#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int maxDigit;
  cin >> maxDigit;
  int i = 1111;
  if (maxDigit < 6) {
    cout << "null" << endl;
  }
  for (int i = 1111; i < 9921; i++) {
    int fourthDigit = (i % 10);
    int restFourth = (i / 10);

    int thirdDigit = (restFourth % 10);
    int restThird = (restFourth / 10);

    int secondDigit = (restThird % 10);

    int firstDigit = (restThird / 10);

    int sumDigits = firstDigit + secondDigit + thirdDigit + fourthDigit;
    if (((fourthDigit <= maxDigit) && (thirdDigit <= maxDigit) &&
         (secondDigit <= maxDigit) && (firstDigit <= maxDigit)) &&
        (sumDigits == 21)) {
      cout << i << endl;
    }
  }
  return 0;
}
