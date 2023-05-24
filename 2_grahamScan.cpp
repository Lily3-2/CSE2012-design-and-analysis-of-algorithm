//Graham’s Scan - Convex Hull Finding Algorithms
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

// Helper function to find the next to top element in the stack
Point nextToTop(stack<Point> &S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

// Helper function to swap two points
void swapPoints(Point &p1, Point &p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// Helper function to calculate the square of distance between two points
int distSq(Point p1, Point p2) {
    return (p2.y - p1.y) * (p2.y - p1.y) + (p2.x - p1.x) * (p2.x - p1.x);
}

// Function to find orientation of three points
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// Comparator function used by the sort() function
Point p0;
int compare(const void *vp1, const void *vp2) {
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    int o = orientation(p0, *p1, *p2);
    if (o == 0) {
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;
    }
    return (o == 2) ? -1 : 1;
}

// Main function to implement the Graham scan algorithm
void grahamScan(Point points[], int n) {
  // Find the bottommost point
  int ymin = points[0].y, min = 0;
  for (int i = 1; i < n; i++) {
      int y = points[i].y;
      if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
          ymin = points[i].y;
          min = i;
      }
  }

  // Place the bottom-most point at first position
  swapPoints(points[0], points[min]);

  // Sort the remaining points in ascending order of polar angle w.r.t. p0
  p0 = points[0];
  qsort(&points[1], n - 1, sizeof(Point), compare);

  // Create an empty stack and push first three points into it
  stack<Point> S;
  S.push(points[0]);
  S.push(points[1]);
  S.push(points[2]);

  // Process remaining n-3 points
  for (int i = 3; i < n; i++) {
    // Keep removing top while the angle formed by points next-to-top,
    // top, and points[i] makes a non-left turn
    while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2) {
        S.pop();
    }

    // Push points[i] onto the stack
    S.push(points[i]);
  }

  // Print the points in the convex hull
  cout << "Points in the convex hull:\n";
  while (!S.empty()) {
        Point p = S.top();
        cout << "(" << p.x << ", " << p.y << ")\n";
        S.pop();
    }
}

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;
    Point points[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the x and y coordinates of point " << i+1 << ": ";
        cin >> points[i].x >> points[i].y;
    }
    grahamScan(points, n);
    return 0;
}
