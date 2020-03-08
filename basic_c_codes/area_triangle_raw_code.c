#include <cmath>
using namespace std;

struct Point
{
    double x;
    double y;
}

double
cross_product(Point a, Point b)
{
    return a.x * b.y - a.y * b.x; // When one co-ordinate of a triange lies at origin.
}

double area(Point a, Point b)
{
    return abs(cross_product(a, b) / 2.0);
}

// When origin lies inside of triangle , then we make three smaller triangles and add them.
double area_2(Point a, Point b, Point c)
{
    return abs(
               cross_product(a, b) +
               cross_product(b, c) +
               cross_product(c, a)) /
           2.0;
}

// TO calculate area of a polygon with n sides
double area_polygon(Point[] vertices, int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += cross_product(vertices[i], vertices[i + 1] % n);
    }
    return abs(sum) / 2.0;
}

// We have used modulo operator to pair last vertex with first vertex.