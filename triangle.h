#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

// structs for points and dimensions of triangle
struct points {
    double leftX;
    double leftY;
    double rightX;
    double rightY;
    double topX;
    double topY;

    points();
    points(double leftX, double leftY, double rightX, double rightY, double topX, double topY);

    friend std::ostream& operator << (std::ostream& outs, const points &d);
};

struct dimensions2 {
    double base;
    double height;

    /* Constructors */
    dimensions2();
    dimensions2(double b, double h);

    /* Overloaded Operator */
    friend std::ostream& operator << (std::ostream& outs, const dimensions2 &d);
};

class Triangle : public Shape{
private:
    dimensions2 size;
    points corners;
public:
    /* Constructors */
    Triangle();
    explicit Triangle(dimensions2 size);
    explicit Triangle(color fill);
    explicit Triangle(point2D center);
    Triangle(color fill, point2D center);
    Triangle(double red, double green, double blue, double alpha);
    Triangle(double x, double y);
    Triangle(double red, double green, double blue, double alpha, double x, double y);
    Triangle(color fill, double x, double y);
    Triangle(double red, double green, double blue, double alpha, point2D center);
    Triangle(color fill, dimensions2 size);
    Triangle(point2D center, dimensions2 size);
    Triangle(color fill, point2D center, dimensions2 size);
    Triangle(double red, double green, double blue, double alpha, dimensions2 size);
    Triangle(double x, double y, dimensions2 size);
    Triangle(double red, double green, double blue, double alpha, double x, double y, dimensions2 size);
    Triangle(color fill, double x, double y, dimensions2 size);
    Triangle(double red, double green, double blue, double alpha, point2D center, dimensions2 size);
    Triangle(points corners, point2D center);

    /* Destructor */
    virtual ~Triangle() = default;

    /* Getters */
    dimensions2 getSize() const;
    double getBase() const;
    double getHeight() const;
    double getLeftX() const override;
    double getRightX() const override;
    double getTopY() const override;
    double getBottomY() const override;

    /* Setters */
    void setSize(dimensions2 size);
    void setSize(double width, double height);
    void setCorners(points corners);
    void setCorners(double leftX, double leftY, double rightX, double rightY, double topX, double topY);
    void setBase(double width);
    void setHeight(double height);
    void changeSize(double deltaWidth, double deltaHeight);
    void changeBase(double delta);
    void changeHeight(double delta);

    bool isOverlapping(const Triangle &t) const;

    /* Draw */
    void draw() const override;
    // attempted to rotate the triangles, did not complete though.  This function is not implemented once, but does not change triangle functionality
    void rotate(double theta_x, double theta_y, double theta_z);
    // void move(double theta_x, double theta_y);
};





#endif //TRIANGLE_H
