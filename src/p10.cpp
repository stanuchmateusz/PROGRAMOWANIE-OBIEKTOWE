#include <iostream>
#include <math.h>

class Point2D
{
private:
    double x, y;

public:
    double getX() { return x; }
    double getY() { return y; }
    void setX(double new_x) { x = new_x; }
    void setY(double new_y) { x = new_y; }
    Point2D(double new_x, double new_y) : x(new_x), y(new_y) {}
    ~Point2D(){};
};
class Circle
{
    Point2D o;
    double radius;
    friend double distance(Circle &c1, Circle &c2)
    {
        Point2D p1 = c1.o;
        Point2D p2 = c2.o;
        double d = std::sqrt(std::pow((p2.getX() - p1.getX()), 2) + std::pow((p2.getY() - p1.getY()), 2));
        return d - (c1.get_radius() + c2.get_radius());
    };

public:
    //getters
    Point2D get_o() { return o; }
    double get_radius() { return radius; }
    //setters
    void set_o(Point2D new_o) { o = new_o; }
    void set_radius(double new_radius) { radius = new_radius; }

    Circle(Point2D &new_o, double new_radius) : o(new_o), radius(new_radius) {}
    Circle(Circle &cir) : radius(cir.get_radius()), o(cir.get_o()) {}
};

int main()
{
    Point2D p1(21, 37);
    Point2D p2(-211, -5);
    Circle grzyb(p1, 5);
    Circle maszrum(p1, 5);
    std::cout << distance(grzyb, maszrum) << std::endl;

    return 0;
}