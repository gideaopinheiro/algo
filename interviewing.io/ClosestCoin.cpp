#include <bits/stdc++.h>
#include <climits>
#include <cmath>
using namespace std;

class Point {
public:
  int x, y;
  Point(int x = 0, int y = 0);
};

Point::Point(int x, int y) {
  this->x = x;
  this->y = y;
};

Point closestCoin(Point myPosition, vector<Point> coinPositions) {
  Point closest = Point(0, 0);
  int shortestDistance = INT_MAX;
  for (auto coinPos : coinPositions) {
    int distance =
        abs(myPosition.x - coinPos.x) + abs(myPosition.y - coinPos.y);
    if (distance < shortestDistance) {
      shortestDistance = distance;
      closest = coinPos;
    }
  }
  return closest;
}

int main(int argc, char *argv[]) {
  Point me = Point(3, 4);
  vector<Point> coinPositions;
  coinPositions.push_back(Point(1, 2));
  coinPositions.push_back(Point(3, 5));
  Point result = closestCoin(me, coinPositions);
  cout << "Closest: Point(" << result.x << ", " << result.y << ")" << endl;

  return 0;
}

/*
   distance((2, 1) => (1, 2)) => 3 (1 left + 2 down)
   -------------------------
   | . | x | . | . | . | . |
   -------------------------
   | . | . | . | o | . | . |
   -------------------------
   | o | . | . | . | . | . |
   -------------------------
   | . | . | . | . | . | . |
   -------------------------
 */
