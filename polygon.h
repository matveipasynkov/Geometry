#pragma once
#include "ishape.h"
#include "point.h"
#include <vector>
#include <memory>

namespace geometry {
class Polygon : public IShape {
 private:
  std::vector<Point> points_ = {};
  size_t size_ = 0;

 public:
  explicit Polygon(std::vector<Point>);
  IShape& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry
