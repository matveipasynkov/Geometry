## Geometry
## Vector
Implemented Vector class for vector on the plane with necessary arithmetic operations (unary and binary +/-, multiplication/division by scalar, assignment versions of operations, equality comparison).

## Shape
We created a set of shape classes that inherit from the abstract base class IShape to work with two-dimensional geometric primitives:
1) Point;
2) Segment;
3) Line;
4) Ray;
5) Polygon (simple polygon - a part of the plane bounded by a closed polyline without self-intersections);
6) Circle.

#### The IShape base class provides purely virtual methods:
1) Move(const Vector&) - shift by a given vector, the method changes the state of the object and returns a reference to the object itself;
2) ContainsPoint(const Point&) - check (true/false) whether the shape (interior of the shape) contains a point;
3) CrossesSegment(const Segment&) - check (true/false) whether the figure (the boundary of the figure) intersects with a segment;
4) Clone() - copying of the object;
5) ToString() - string representation of the figure.
