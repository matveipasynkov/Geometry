#pragma once
#include "ishape.h"
#include "point.h"
#include <memory>
#include <cstdint>

namespace geometry {
class Circle : public IShape {
 private:
  Point center_ = Point(0, 0);
  int64_t radius_ = 0;

 public:
  Circle(Point, int64_t);
  IShape& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry
