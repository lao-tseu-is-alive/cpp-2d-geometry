#include <iostream>
#include "Point.h"

int main() {
    Point p0 = Point();
    Point p1 = Point(1, 1);
    Point p2 = Point(1, 7);
    Point p3 = p1;
    std::cout << "Hello, World!" << std::endl;
    std::cout << "p0 :" << p0 << std::endl;
    std::cout << "p1 :" << p1 << std::endl;
    std::cout << "p2 :" << p2 << std::endl;
    std::cout << "p2.getX :" << p2.getX() << std::endl;
    std::cout << "p2.getY :" << p2.getY() << std::endl;
    p2.setX(2);
    std::cout << "p2.setX(2) :" << p2 << std::endl;
    p2.setY(3);
    std::cout << "p2.setY(3) :" << p2 << std::endl;

    std::cout << "p1 + p2 :" << p1 + p2 << std::endl;
    std::cout << "p1 - p2 :" << p1 - p2 << std::endl;
    std::cout << "p1 * 2 :" << p1 * 2 << std::endl;
    std::cout << "p1 / 2 :" << p1 / 2 << std::endl;
    std::cout << "p2.norm() :" << p2.norm() << std::endl;
    std::cout << "p3=p1 :" << p3 << std::endl;
    std::cout << "p3==p1 :" << (p3 == p1) << std::endl;
    std::cout << "Point(p2) :" << Point(p2) << std::endl;
    std::cout << "p2.norm() :" << p2.norm() << std::endl;
    std::cout << "p2.normalize() :" << p2.normalize() << std::endl;
    std::cout << "p2 :" << p2 << std::endl;
    std::cout << "p0.dist(p2) :" << p0.dist(p2) << std::endl;
    std::cout << "p0.dist(p2, p1) :" << p0.dist(p2, p1) << std::endl;
    std::cout << "p0.project(p2, p1) :" << p0.project(p2, p1) << std::endl;
    std::cout << "p0.reflect(p2, p1) :" << p0.reflect(p2, p1) << std::endl;
    std::cout << "p0.rotate(PI) :" << p1.rotate(M_PI) << std::endl;


    return 0;
}
