#include "../polygon.h"
#include "../ray.h"
#include "../segment.h"
#include <memory>
#include <cstdint>

namespace geometry {
Polygon::Polygon(std::vector<Point> points) {
  points_ = points;
  size_ = points_.size();
}

IShape& Polygon::Move(const Vector& vector) {
  for (size_t i = 0; i < points_.size(); ++i) {
    points_[i].Move(vector);
  }
  return *this;
}

bool Polygon::ContainsPoint(const Point& point) const {
  int64_t counter = 0;
  Ray ray = Ray(point, Point(point.GetXValue() + 1, point.GetYValue() + 1));
  for (size_t i = 0; i < size_; ++i) {
    if (i == 0) {
      Segment side = Segment(points_[0], points_[size_ - 1]);
      if (point.CrossesSegment(side)) {
        counter = 1;
        break;
      }
      if (ray.CrossesSegment(side)) {
        if (ray.GetDirection().VectorMultiplication(points_[size_ - 1] - points_[0]) != 0) {
          if (points_[0].GetYValue() == points_[size_ - 1].GetYValue()) {
            if (!ray.ContainsPoint(points_[0]) && !ray.ContainsPoint(points_[size_ - 1])) {
              ++counter;
            }
          } else {
            Point point_with_min_y =
                points_[0].GetYValue() < points_[size_ - 1].GetYValue() ? points_[0] : points_[size_ - 1];
            if (!ray.ContainsPoint(point_with_min_y) && points_[0].GetYValue() != points_[size_ - 1].GetYValue()) {
              ++counter;
            }
          }
        }
      }
    } else {
      Segment side = Segment(points_[i], points_[i - 1]);
      if (point.CrossesSegment(side)) {
        counter = 1;
        break;
      }
      if (ray.CrossesSegment(Segment(points_[i], points_[i - 1]))) {
        if (ray.GetDirection().VectorMultiplication(points_[i - 1] - points_[i]) != 0) {
          if (points_[i].GetYValue() == points_[i - 1].GetYValue()) {
            if (!ray.ContainsPoint(points_[i]) && !ray.ContainsPoint(points_[i - 1])) {
              ++counter;
            }
          } else {
            Point point_with_min_y = points_[i].GetYValue() < points_[i - 1].GetYValue() ? points_[i] : points_[i - 1];
            if (!ray.ContainsPoint(point_with_min_y) && points_[i].GetYValue() != points_[i - 1].GetYValue()) {
              ++counter;
            }
          }
        }
      }
    }
  }
  return counter % 2 == 1;
}

bool Polygon::CrossesSegment(const Segment& segment) const {
  int64_t counter = 0;
  for (size_t i = 0; i < points_.size(); ++i) {
    if (i == 0) {
      counter += segment.CrossesSegment(Segment(points_[0], points_[points_.size() - 1]));
    } else {
      counter += segment.CrossesSegment(Segment(points_[i], points_[i - 1]));
    }
  }
  return counter > 0;
}

std::unique_ptr<IShape> Polygon::Clone() const {
  return std::make_unique<Polygon>(points_);
}

std::string Polygon::ToString() const {
  std::string result = "Polygon(";
  if (!points_.empty()) {
    result += points_[0].ToString();
    for (size_t i = 1; i < points_.size(); ++i) {
      result += ", " + points_[i].ToString();
    }
  }
  result += ")";
  return result;
}
}  // namespace geometry
