#include "../point.h"
#include "../ishape.h"
#include "../segment.h"
#include "../vector.h"
#include <memory>

namespace geometry {
Point::Point(int64_t x, int64_t y) {
  x_ = x;
  y_ = y;
}

int64_t Point::GetXValue() const {
  return x_;
}

int64_t Point::GetYValue() const {
  return y_;
}

IShape& Point::Move(const Vector& vector) {
  x_ += vector.GetXCoordinate();
  y_ += vector.GetYCoordinate();
  return *this;
}

bool Point::ContainsPoint(const Point& other) const {
  return x_ == other.x_ && y_ == other.y_;
}

Vector Point::operator-(const Point& other) const {
  return {x_ - other.x_, y_ - other.y_};
}

bool Point::CrossesSegment(const Segment& segment) const {
  Vector vector_ap = *this - segment.GetStart();
  Vector vector_pb = segment.GetFinish() - *this;
  return vector_ap.VectorMultiplication(vector_pb) == 0 && vector_ap.ScalarMultiplication(vector_pb) >= 0;
}

std::unique_ptr<IShape> Point::Clone() const {
  return std::make_unique<Point>(x_, y_);
}

std::string Point::ToString() const {
  return "Point(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
}
}  // namespace geometry
