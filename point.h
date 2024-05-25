#pragma once
#include "ishape.h"
#include <memory>
#include <cstdint>

namespace geometry {
class Point : public IShape {
 private:
  int64_t x_ = 0;
  int64_t y_ = 0;

 public:
  Point(int64_t, int64_t);
  int64_t GetXValue() const;
  int64_t GetYValue() const;
  Vector operator-(const Point&) const;
  IShape& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry
