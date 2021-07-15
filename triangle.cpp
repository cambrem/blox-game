#include "triangle.h"
#include "graphics.h"
#include <iostream>
using namespace std;

/********************* Points Struct ********************/

points::points() : leftX(0), leftY(0), rightX(0), rightY(0), topX(0), topY(0){}

points::points(double leftX, double leftY, double rightX, double rightY, double topX, double topY) : leftX(leftX), leftY(leftY), rightX(rightX), rightY(rightY), topX(topX), topY(topY){}

ostream& operator << (ostream& outs, const points &d) {
    outs << "Left: [" << d.leftX << ", " << d.leftY << "]" << endl;
//    outs << "Right: [" << d.rightX << ", " << d.rightY << "]" << endl;
//    outs << "Top: [" << d.topX << ", " << d.topY << "]" << endl;
    return outs;
}

/********************* Dimensions Struct ********************/

dimensions2::dimensions2() : base(0), height(0) {}

dimensions2::dimensions2(double b, double h) : base(b), height(h) {}

ostream& operator << (ostream& outs, const dimensions2 &d) {
    outs << "[" << d.base << ", " << d.height << "]";
    return outs;
}

Triangle::Triangle() : Shape(), size({0, 0}) {
}

Triangle::Triangle(dimensions2 size) : Shape() {
    setSize(size);
}

Triangle::Triangle(color fill) : Shape(fill), size({0, 0}) {
}

Triangle::Triangle(point2D center) : Shape(center), size({0, 0}) {
}

Triangle::Triangle(color fill, point2D center) : Shape(fill, center), size({0, 0}) {
}

Triangle::Triangle(double red, double green, double blue, double alpha) : Shape(red, green, blue, alpha), size({0, 0}) {
}

Triangle::Triangle(double x, double y) : Shape(x, y), size({0, 0}) {
}

Triangle::Triangle(double red, double green, double blue, double alpha, double x, double y) : Shape(red, green, blue, alpha, x, y), size({0, 0}) {
}

Triangle::Triangle(color fill, double x, double y) : Shape(fill, x, y), size({0, 0}) {
}

Triangle::Triangle(double red, double green, double blue, double alpha, point2D center) : Shape(red, green, blue, alpha, center), size({0, 0}) {
}

Triangle::Triangle(color fill, dimensions2 size) : Shape(fill) {
    setSize(size);
}

Triangle::Triangle(point2D center, dimensions2 size) : Shape(center) {
    setSize(size);
}

Triangle::Triangle(color fill, point2D center, dimensions2 size) : Shape(fill, center) {
    setSize(size);
}

Triangle::Triangle(double red, double green, double blue, double alpha, dimensions2 size) : Shape(red, green, blue, alpha) {
    setSize(size);
}

Triangle::Triangle(double x, double y, dimensions2 size) : Shape(x, y) {
    setSize(size);
}

Triangle::Triangle(double red, double green, double blue, double alpha, double x, double y, dimensions2 size) : Shape(red, green, blue, alpha, x, y) {
    setSize(size);
}

Triangle::Triangle(color fill, double x, double y, dimensions2 size) : Shape(fill, x, y) {
    setSize(size);
}

Triangle::Triangle(double red, double green, double blue, double alpha, point2D center, dimensions2 size) : Shape(red, green, blue, alpha, center) {
    setSize(size);
}

Triangle::Triangle(points corners, point2D center) : Shape(center) {
    setCorners(corners);
}

dimensions2 Triangle::getSize() const {
    return size;
}

double Triangle::getBase() const {
    return size.base;
}

double Triangle::getHeight() const {
    return size.height;
}

double Triangle::getLeftX() const {
    return center.x - (size.base / 2.0);
}

double Triangle::getRightX() const {
    return center.x + (size.base / 2.0);
}

double Triangle::getTopY() const {
    return center.y - (size.height / 2.0);
}

double Triangle::getBottomY() const {
    return center.y + (size.height / 2.0);
}

void Triangle::setSize(dimensions2 size) {
    if (size.base >= 0 && size.height >= 0) {
        this->size = size;
    }
}

void Triangle::setSize(double base, double height) {
    setSize({base, height});
}

void Triangle::setCorners(points corners) {
    if (size.base >= 0 && size.height >= 0) {
        this->corners = corners;
    }
}

void Triangle::setCorners(double leftX, double leftY, double rightX, double rightY, double topX, double topY) {
    setCorners({leftX, leftY, rightX, rightY, topX, topY});
}

void Triangle::setBase(double base) {
    setSize({base, size.height});
}

void Triangle::setHeight(double height) {
    setSize({size.base, height});
}

void Triangle::changeSize(double deltaBase, double deltaHeight) {
    setSize({size.base + deltaBase, size.height + deltaHeight});
}

void Triangle::changeBase(double delta) {
    setSize({size.base + delta, size.height});
}

void Triangle::changeHeight(double delta) {
    setSize({size.base, size.height + delta});
}

// Implement this method not entirely sure if correct
bool Triangle::isOverlapping(const Triangle &t) const {
    // There are only two cases when rectangles are *not* overlapping:
    // 1. when one is to the left of the other
    // 2. when one is above the other
    if (this->getRightX() < t.getLeftX() ||
        this->getBottomY() < t.getTopY() ||
        t.getRightX() < this->getLeftX() ||
        t.getBottomY() < this->getTopY()) {
        return false;
    }
    else {
        return true; // placeholder value for compilation
    }
}

// Implement this method
void Triangle::draw() const {
    // Don't forget to set the color to the fill field
    glColor3f(fill.red, fill.green, fill.blue);

    glBegin(GL_TRIANGLES);
    //bottom left
    glVertex2i(getLeftX(), getBottomY());
    //bottom right
    glVertex2i(getRightX(), getBottomY());
    //top center
    glVertex2i((getLeftX() + getRightX()) / 2, getTopY());
    glEnd();
}

// attempted to rotate the triangles, did not complete though.  This function is not implemented once, but does not change triangle functionality
void Triangle::rotate(double theta_x, double theta_y, double theta_z) {
    double old_x = 0, old_y = 0, old_z = 0;
    double center_x = center.x, center_y = center.y, center_z = center.z;

    // only do this one below, compute old x nd old y, use to computer new x and y coordinates,

    old_y = corners.leftY;
    old_x = corners.leftX;
    corners.leftY = old_y * cos(theta_z) - old_x * sin(theta_z);
    corners.leftX = old_y * sin(theta_z) + old_x * cos(theta_z);

    old_y = corners.rightY;
    old_x = corners.rightX;
    corners.rightY = old_y * cos(theta_z) - old_x * sin(theta_z);
    corners.rightX = old_y * sin(theta_z) + old_x * cos(theta_z);

    old_y = corners.topY;
    old_x = corners.topX;
    corners.topY = old_y * cos(theta_z) - old_x * sin(theta_z);
    corners.topX = old_y * sin(theta_z) + old_x * cos(theta_z);

    // Fix this, triangles flicker for a bit then disappear fdsjkdsf
    //Triangle::move(center_x, center_y);
}

// not sure if this is correct or not, implemented from cube.cpp
//void Triangle::move(double theta_x, double theta_y) {
//    center.x += theta_x;
//    corners.leftX += theta_x;
//
//    center.y += theta_y;
//    corners.leftY += theta_y;
//}