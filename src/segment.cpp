#include "../segment.h"
#include "../line.h"
#include <memory>

namespace geometry {
Segment::Segment(Point x, Point y) {
  start_ = x;
  finish_ = y;
}

Point Segment::GetStart() const {
  return start_;
}

Point Segment::GetFinish() const {
  return finish_;
}

IShape& Segment::Move(const Vector& vector) {
  start_.Move(vector);
  finish_.Move(vector);
  return *this;
}

bool Segment::ContainsPoint(const Point& point) const {
  return point.CrossesSegment(*this);
}

bool Segment::CrossesSegment(const Segment& other) const {
  Line line_this = Line(start_, finish_);
  Line line_other = Line(other.GetStart(), other.GetFinish());
  if (line_other.ContainsPoint(start_) && line_other.ContainsPoint(finish_)) {
    return this->ContainsPoint(other.GetStart()) || this->ContainsPoint(other.GetFinish()) ||
           other.ContainsPoint(start_) || other.ContainsPoint(finish_);
  }
  return line_this.CrossesSegment(other) && line_other.CrossesSegment(*this);
}

std::unique_ptr<IShape> Segment::Clone() const {
  return std::make_unique<Segment>(start_, finish_);
}

std::string Segment::ToString() const {
  return "Segment(" + start_.ToString() + ", " + finish_.ToString() + ")";
}
}  // namespace geometry