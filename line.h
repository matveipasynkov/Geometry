#pragma once
#include "ishape.h"
#include "point.h"
#include <memory>

namespace geometry {
class Line : public IShape {
 private:
  Point first_point_ = Point(0, 0);
  Point second_point_ = Point(1, 1);
  Vector direction_vector_ = second_point_ - first_point_;
  Vector normal_vector_ = Vector(-direction_vector_.GetYCoordinate(), direction_vector_.GetXCoordinate());

 public:
  Line(Point, Point);
  IShape& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry
