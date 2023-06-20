#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/convex_hull_2.h>
#include <iostream>
#include <sstream>

void test_1() {
  typedef CGAL::Simple_cartesian<double> Kernel;
  typedef Kernel::Point_2 Point_2;
  {

    Point_2 p(0, 0.3), q(1, 0.6), r(2, 0.9);
    std::cout << (CGAL::collinear(p, q, r) ? "is collinear"
                                           : "is not collinear")
              << std::endl;
  }
  {

    Point_2 p(0, 1.f / 3), q(1, 2.f / 3), r(2, 1);
    std::cout << (CGAL::collinear(p, q, r) ? "is collinear"
                                           : "is not collinear")
              << std::endl;
  }
  {

    Point_2 p(0, 0), q(1, 1), r(2, 2);
    std::cout << (CGAL::collinear(p, q, r) ? "is collinear"
                                           : "is not collinear")
              << std::endl;
  }
}

void test_2() {
  typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
  typedef Kernel::Point_2 Point_2;
  Point_2 p(0, 0.3), q, r(2, 0.9);
  {
    q = Point_2(1, 0.6);
    std::cout << (CGAL::collinear(p, q, r) ? "collinear\n" : "not collinear\n");
  }
  {
    std::istringstream input("0 0.3   1 0.6   2 0.9");
    input >> p >> q >> r;
    std::cout << (CGAL::collinear(p, q, r) ? "collinear\n" : "not collinear\n");
  }
  {
    q = CGAL::midpoint(p, r);
    std::cout << (CGAL::collinear(p, q, r) ? "collinear\n" : "not collinear\n");
    std::cout << "mid pr q=" << q << std::endl;
  }
}

/*
 * TEST for
 * exact geometric constructions or not
 *
 * */
void test_array_convex_hull() {
  typedef CGAL::Exact_predicates_exact_constructions_kernel K;
  typedef K::Point_2 Point_2;
  Point_2 points[5] = {
      Point_2(0, 0), Point_2(10, 0), Point_2(10, 10),
      Point_2(6, 5), Point_2(4, 1),
  };
  Point_2 result[5];
  Point_2 *ptr = CGAL::convex_hull_2(points, points + 5, result);
  std::cout << ptr - result << " points on the convex hull:" << std::endl;
  for (int i = 0; i < ptr - result; i++) {
    std::cout << result[i] << std::endl;
  }
}

void test_array_convex_hull_1() {
  typedef CGAL::Exact_predicates_exact_constructions_kernel K;
  typedef K::Point_2 Point_2;
  typedef std::vector<Point_2> Points;

  Points points, result;

  points.push_back(Point_2(0, 0));
  points.push_back(Point_2(10, 0));
  points.push_back(Point_2(10, 10));
  points.push_back(Point_2(6, 5));
  points.push_back(Point_2(4, 1));

  CGAL::convex_hull_2(points.begin(), points.end(), std::back_inserter(result));
  std::cout << result.size() << " points on the convex hull" << std::endl;
  for (auto &r : result)
    std::cout << "(" << r.x() << " ," << r.y() << ")" << std::endl;
}

int main() {
  test_array_convex_hull_1();
  return 0;
}
