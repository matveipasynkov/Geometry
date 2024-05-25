#include "../circle.h"
#include "../ray.h"
#include "../segment.h"
#include <memory>
#include <cstdint>

namespace geometry {
Circle::Circle(Point a, int64_t r) {
  center_ = a;
  radius_ = r;
}

IShape& Circle::Move(const Vector& vector) {
  center_.Move(vector);
  return *this;
}

bool Circle::ContainsPoint(const Point& point) const {
  Vector vector = point - center_;
  int64_t x_value = vector.GetXCoordinate();
  int64_t y_value = vector.GetYCoordinate();
  return radius_ * radius_ >= x_value * x_value + y_value * y_value;
}

bool Circle::CrossesSegment(const Segment& segment) const {
  Vector first_directional = segment.GetFinish() - segment.GetStart();
  Vector second_directional = segment.GetStart() - segment.GetFinish();
  Vector center_start = center_ - segment.GetStart();
  Vector center_finish = center_ - segment.GetFinish();
  int64_t first_multiplication = first_directional.VectorMultiplication(center_start);
  int64_t second_multiplication = second_directional.VectorMultiplication(center_finish);
  int64_t square_radius = radius_ * radius_;
  int64_t square_first = first_directional.GetXCoordinate() * first_directional.GetXCoordinate() +
                         first_directional.GetYCoordinate() * first_directional.GetYCoordinate();
  int64_t square_second = second_directional.GetXCoordinate() * second_directional.GetXCoordinate() +
                          second_directional.GetYCoordinate() * second_directional.GetYCoordinate();
  bool first_check = first_multiplication * first_multiplication <= square_radius * square_first;
  bool second_check = second_multiplication * second_multiplication <= square_radius * square_second;
  int64_t first_point_x = segment.GetStart().GetXValue();
  int64_t first_point_y = segment.GetStart().GetYValue();
  int64_t second_point_x = segment.GetFinish().GetXValue();
  int64_t second_point_y = segment.GetFinish().GetYValue();
  bool third_check = radius_ * radius_ <= first_point_x * first_point_x + first_point_y * first_point_y ||
                     radius_ * radius_ <= second_point_x * second_point_x + second_point_y * second_point_y;
  return first_check && second_check && third_check;
}

std::unique_ptr<IShape> Circle::Clone() const {
  return std::make_unique<Circle>(center_, radius_);
}

std::string Circle::ToString() const {
  return "Circle(" + center_.ToString() + ", " + std::to_string(radius_) + ")";
}

}  // namespace geometry