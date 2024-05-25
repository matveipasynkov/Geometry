#pragma once
#include "ishape.h"
#include "point.h"
#include <memory>

namespace geometry {
class Ray : public IShape {
 private:
  Point start_point_ = Point(0, 0);
  Point second_point_ = Point(1, 0);
  Vector direction_vector_ = second_point_ - start_point_;

 public:
  Ray(Point, Point);
  Vector GetDirection() const;
  IShape& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry
