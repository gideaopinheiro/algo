#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
  int x, y;
  int closestCoin(Point yourPosition, vector<Point> coinPositions);
  Point();
  Point(int x, int y);
};

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) {
  this->x = x;
  this->y = y;
}

int Point::closestCoin(Point yourPosition, vector<Point> coinPositions) {
  int closestDistance = INT_MAX;
  for (auto pos : coinPositions) {
    int actualDistance =
        (abs(pos.x - yourPosition.x) + abs(pos.y - yourPosition.y));
    if (actualDistance < closestDistance) {
      closestDistance = actualDistance;
    }
  }
  return closestDistance;
}

int main(int argc, char const *argv[]) {
  vector<Point> coins = {Point(3, 5), Point(3, 4), Point(2, 8)};
  Point myPosition = Point(1, 1);
  cout << myPosition.closestCoin(myPosition, coins) << endl;
  return 0;
}
