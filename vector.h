#pragma once
#include <string>
#include <cstdint>

namespace geometry {
class Vector {
 private:
  int64_t x_ = 0;
  int64_t y_ = 0;

 public:
  Vector(int64_t, int64_t);
  int64_t GetXCoordinate() const;
  int64_t GetYCoordinate() const;
  int64_t VectorMultiplication(const Vector&) const;
  int64_t ScalarMultiplication(const Vector&) const;
  Vector operator+() const;
  Vector operator-() const;
  Vector operator+(const Vector&) const;
  Vector operator-(const Vector&) const;
  Vector operator*(const int64_t&)const;
  Vector operator/(const int64_t&) const;
  Vector& operator+=(const Vector&);
  Vector& operator-=(const Vector&);
  Vector& operator*=(const int64_t&);
  Vector& operator/=(const int64_t&);
  bool operator==(const Vector&) const;
  std::string ToString() const;
};
}  // namespace geometry
