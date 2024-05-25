#include "../vector.h"
#include <cstdint>

namespace geometry {
Vector::Vector(int64_t x, int64_t y) {
  x_ = x;
  y_ = y;
}

Vector Vector::operator+() const {
  return {x_, y_};
}

Vector Vector::operator-() const {
  return {-x_, -y_};
}

Vector Vector::operator+(const Vector& other) const {
  return {x_ + other.x_, y_ + other.y_};
}

Vector Vector::operator*(const int64_t& lambda) const {
  return {x_ * lambda, y_ * lambda};
}

Vector Vector::operator/(const int64_t& lambda) const {
  if (lambda != 0) {
    return {x_ / lambda, y_ / lambda};
  }
  return {x_, y_};
}

Vector Vector::operator-(const Vector& other) const {
  return {x_ - other.x_, y_ - +other.y_};
}

Vector& Vector::operator*=(const int64_t& lambda) {
  x_ *= lambda;
  y_ *= lambda;
  return *this;
}

Vector& Vector::operator/=(const int64_t& lambda) {
  if (lambda != 0) {
    x_ /= lambda;
    y_ /= lambda;
  }
  return *this;
}

Vector& Vector::operator+=(const Vector& other) {
  x_ += other.x_;
  y_ += other.y_;
  return *this;
}

Vector& Vector::operator-=(const Vector& other) {
  x_ -= other.x_;
  y_ -= other.y_;
  return *this;
}

bool Vector::operator==(const Vector& other) const {
  return x_ == other.x_ && y_ == other.x_;
}

int64_t Vector::GetXCoordinate() const {
  return x_;
}

int64_t Vector::GetYCoordinate() const {
  return y_;
}

int64_t Vector::VectorMultiplication(const Vector& other) const {
  return x_ * other.y_ - y_ * other.x_;
}

int64_t Vector::ScalarMultiplication(const Vector& other) const {
  return x_ * other.x_ + y_ * other.y_;
}

std::string Vector::ToString() const {
  return "Vector(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
}

}  // namespace geometry
