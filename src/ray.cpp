#include "../ray.h"
#include "../line.h"
#include "../segment.h"
#include <memory>
#include <cstdint>

namespace geometry {
Ray::Ray(Point a, Point b) {
  start_point_ = a;
  second_point_ = b;
  direction_vector_ = second_point_ - start_point_;
}

Vector Ray::GetDirection() const {
  return direction_vector_;
}

IShape& Ray::Move(const Vector& vector) {
  start_point_.Move(vector);
  second_point_.Move(vector);
  return *this;
}

bool Ray::ContainsPoint(const Point& point) const {
  Vector vector_op = point - start_point_;
  return vector_op.ScalarMultiplication(direction_vector_) >= 0 &&
         vector_op.VectorMultiplication(direction_vector_) == 0;
}

bool Ray::CrossesSegment(const Segment& segment) const {
  Line line_with_ray = Line(start_point_, second_point_);
  bool check_alpha = line_with_ray.CrossesSegment(segment);
  int64_t first_vector_multiplication =
      (start_point_ - segment.GetStart()).VectorMultiplication(segment.GetFinish() - segment.GetStart());
  int64_t second_vector_multiplication =
      direction_vector_.VectorMultiplication(segment.GetFinish() - segment.GetStart());
  bool second_check = first_vector_multiplication >= 0 && second_vector_multiplication <= 0;
  bool third_check = first_vector_multiplication <= 0 && second_vector_multiplication >= 0;
  bool check_vector_multiplication = second_check || third_check;
  return check_alpha && check_vector_multiplication;
}

std::unique_ptr<IShape> Ray::Clone() const {
  return std::make_unique<Ray>(start_point_, second_point_);
}

std::string Ray::ToString() const {
  return "Ray(" + start_point_.ToString() + ", " + direction_vector_.ToString() + ")";
}

}  // namespace geometry