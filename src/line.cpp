#include "../line.h"
#include "../segment.h"
#include <memory>
#include <cstdint>

namespace geometry {
Line::Line(Point a, Point b) {
  first_point_ = a;
  second_point_ = b;
  direction_vector_ = second_point_ - first_point_;
  normal_vector_ = Vector(-direction_vector_.GetYCoordinate(), direction_vector_.GetXCoordinate());
}

IShape& Line::Move(const Vector& vector) {
  first_point_.Move(vector);
  second_point_.Move(vector);
  return *this;
}

bool Line::ContainsPoint(const Point& point) const {
  return (point - first_point_).ScalarMultiplication(normal_vector_) == 0;
}

bool Line::CrossesSegment(const Segment& segment) const {
  Point point_a = segment.GetStart();
  Point point_b = segment.GetFinish();
  int64_t first_value = (point_a - first_point_).ScalarMultiplication(normal_vector_);
  int64_t second_value = (point_b - first_point_).ScalarMultiplication(normal_vector_);
  bool first_check = first_value <= 0 && second_value >= 0;
  bool second_check = first_value >= 0 && second_value <= 0;
  return first_check || second_check;
}

std::unique_ptr<IShape> Line::Clone() const {
  return std::make_unique<Line>(first_point_, second_point_);
}

std::string Line::ToString() const {
  return "Line(" + std::to_string(normal_vector_.GetXCoordinate()) + ", " +
         std::to_string(normal_vector_.GetYCoordinate()) + ", " +
         std::to_string(-normal_vector_.ScalarMultiplication(first_point_ - Point(0, 0))) + ")";
}

}  // namespace geometry