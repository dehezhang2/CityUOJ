#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define ERROR 1e-8
double d;
struct Point {
    double x, y;
};
inline double dot(const Point& p1, const Point& p2) {
    return p1.x * p2.x + p1.y * p2.y;
}
inline double cross(const Point& p1, const Point& p2) {
    return p1.x * p2.y - p2.x * p1.y;
}
Point v1, v2;
bool judge() {
    // todo: check whether the vector is parallel to the radius, then check the direction of the vector, finally check the distance
    if(fabs(cross(v1, v2)) > ERROR) return false;
    if(dot(v1, v2) >= 0) {
        double e = 2.0 - sqrt(v1.x * v1.x + v1.y * v1.y);
        if(e > d) return false;
    } else {
        if(sqrt(v1.x * v1.x + v1.y * v1.y) > d ) return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while(~scanf("%lf\n", &d) && d != 0.0) {
        scanf("%lf %lf %lf %lf\n", &v1.x, &v1.y, &v2.x, &v2.y);
        printf(judge() ? "possible\n" : "impossible\n");
    }

    return 0;
}