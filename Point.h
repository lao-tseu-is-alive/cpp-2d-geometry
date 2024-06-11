//
// Created by cgil on 6/11/24.
//

#ifndef INC_2DGEOM_POINT_H
#define INC_2DGEOM_POINT_H

#include <cmath>
#include <iostream> // Include iostream for std::ostream

const double EPS = 0.000001; // Small epsilon value for floating-point comparisons

/**
 * @class Point
 * @brief A class representing a 2D point and providing various geometric operations.
 */
class Point {
private:
    double x, y; // The x and y coordinates of the point
public:
    /**
     * @brief Get the x-coordinate.
     * @return The x-coordinate.
     */
    [[nodiscard]] double getX() const {
        return x;
    }

    /**
     * @brief Set the x-coordinate.
     * @param newX The new x-coordinate.
     */
    void setX(double newX) {
        x = newX;
    }

    /**
     * @brief Get the y-coordinate.
     * @return The y-coordinate.
     */
    [[nodiscard]] double getY() const {
        return y;
    }

    /**
     * @brief Set the y-coordinate.
     * @param newY The new y-coordinate.
     */
    void setY(double newY) {
        y = newY;
    }

    /**
     * @brief Default constructor to initialize the point at the origin.
     */
    Point() : x(0), y(0) {}

    /**
     * @brief Constructor to initialize the point with given x and y coordinates.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     */
    Point(double x, double y) : x(x), y(y) {}

    /**
     * @brief Copy constructor to initialize the point with another point.
     * @param p The point to copy.
     */
    Point(const Point &p) = default;

    /**
     * @brief Operator overload for point assignment.
     * @param p The point to assign.
     * @return A reference to the assigned point.
     */
    Point& operator=(const Point &p) = default;

    /**
     * @brief Operator overload for point subtraction.
     * @param p The point to subtract.
     * @return A new point that is the result of the subtraction.
     */
    Point operator-(const Point &p) const {
        return {x - p.x, y - p.y};
    }

    /**
     * @brief Operator overload for point addition.
     * @param p The point to add.
     * @return A new point that is the result of the addition.
     */
    Point operator+(const Point &p) const {
        return {x + p.x, y + p.y};
    }

    /**
     * @brief Operator overload for scaling the point by a constant.
     * @param c The constant to multiply by.
     * @return A new point that is the result of the scaling.
     */
    Point operator*(double c) const {
        return {x * c, y * c};
    }

    /**
     * @brief Operator overload for dividing the point by a constant.
     * @param c The constant to divide by.
     * @return A new point that is the result of the division.
     */
    Point operator/(double c) const {
        return {x / c, y / c};
    }

    /**
     * @brief Calculate and return the Euclidean norm (magnitude) of the point.
     * @return The Euclidean norm of the point.
     */
    [[nodiscard]] double norm() const {
        return sqrt(x * x + y * y);
    }

    /**
     * @brief Normalize the point (convert to unit vector) and return the result.
     * @return A normalized (unit) vector point.
     */
    [[nodiscard]] Point normalize() const {
        return *this / norm();
    }

    /**
     * @brief Calculate and return the dot product with another point.
     * @param p The other point.
     * @return The dot product of the two points.
     */
    [[nodiscard]] double dot(const Point &p) const {
        return x * p.x + y * p.y;
    }

    /**
     * @brief Calculate and return the 2D cross product with another point.
     * @param p The other point.
     * @return The 2D cross product of the two points.
     */
    [[nodiscard]] double cross(const Point &p) const {
        return x * p.y - y * p.x;
    }

    /**
     * @brief Calculate and return the distance to another point.
     * @param p The other point.
     * @return The distance to the other point.
     */
    [[nodiscard]] double dist(const Point &p) const {
        return (*this - p).norm();
    }

    /**
     * @brief Calculate and return the distance from this point to the line defined by points p and q.
     * @param p The first point defining the line.
     * @param q The second point defining the line.
     * @return The perpendicular distance to the line.
     */
    [[nodiscard]] double dist(const Point &p, const Point &q) const {
        return fabs((p - q).cross(*this - q)) / (p - q).norm();
    }

    /**
     * @brief Rotate the point by theta radians around the origin and return the result.
     * @param theta The angle to rotate by, in radians.
     * @return The rotated point.
     */
    [[nodiscard]] Point rotate(double theta) const {
        return {x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)};
    }

    /**
     * @brief Project this point onto the line defined by points p and q and return the result.
     * @param p The first point defining the line.
     * @param q The second point defining the line.
     * @return The projection of the point onto the line.
     */
    [[nodiscard]] Point project(const Point &p, const Point &q) const {
        return p + (q - p) * ((*this - p).dot(q - p) / (q - p).dot(q - p));
    }

    /**
     * @brief Reflect this point across the line defined by points p and q and return the result.
     * @param p The first point defining the line.
     * @param q The second point defining the line.
     * @return The reflection of the point across the line.
     */
    [[nodiscard]] Point reflect(const Point &p, const Point &q) const {
        return *this + (project(p, q) - *this) * 2;
    }

    /**
     * @brief midPoint finds the midpoint between this point and another point.
     * @param p The other point.
     * @return The midpoint between this point and the other point.
     */
    [[nodiscard]] Point midPoint(const Point &p) const {
        return (*this + p) / 2;
    }

    /**
     * @brief Operator overload to check if two points are approximately equal.
     * @param p The other point to compare with.
     * @return True if the points are approximately equal, false otherwise.
     */
    bool operator==(const Point &p) const {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }

    /**
     * @brief Operator overload to compare points based on x-coordinate, then y-coordinate.
     * @param p The other point to compare with.
     * @return True if this point is less than the other point, false otherwise.
     */
    bool operator<(const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }

    /**
     * @brief Operator overload to compare points based on x-coordinate, then y-coordinate.
     * @param p The other point to compare with.
     * @return True if this point is greater than the other point, false otherwise.
     */
    bool operator>(const Point &p) const {
        return x != p.x ? x > p.x : y > p.y;
    }

    /**
     * @brief Operator overload to compare points based on x-coordinate, then y-coordinate.
     * @param p The other point to compare with.
     * @return True if this point is less than or equal to the other point, false otherwise.
     */
    bool operator<=(const Point &p) const {
        return x != p.x ? x < p.x : y <= p.y;
    }

    /**
     * @brief Friend function to overload the << operator for printing the point.
     * @param os The output stream.
     * @param p The point to print.
     * @return The output stream.
     */
    friend std::ostream& operator<<(std::ostream &os, const Point &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    /**
     * @brief Friend function to overload the >> operator for reading the point.
     * @param is The input stream.
     * @param p The point to read.
     * @return The input stream.
     */
    friend std::istream& operator>>(std::istream &is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }

};

#endif // INC_2DGEOM_POINT_H
