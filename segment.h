#pragma once
#include "ishape.h"
#include "point.h"
#include <memory>

namespace geometry {
class Segment : public IShape {
 private:
  Point start_ = Point(0, 0);
  Point finish_ = Point(0, 0);

 public:
  Segment(Point, Point);
  Point GetStart() const;
  Point GetFinish() const;
  IShape& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry
