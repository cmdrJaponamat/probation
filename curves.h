#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>


struct Point
{
    double x;
    double y;
    double z;
    Point();
    Point(double x, double y, double z);
    operator std::string() const;
};

class Models3D
{
    std::string name;
public:
    virtual Point GetPoint(const double t) const = 0;
    virtual Point GetVector(const double t) const = 0;
    virtual std::string GetName() const = 0;
    virtual double GetRadius() const = 0;
};

class Circles: public Models3D
{
    // x = sin (term) * r
    // y = cos (term) * r
    // x^2 + y^2 = r^2
    double r;
    Point center; // because at difinition you says to define circle whith radius only
    std::string name{"circles"};
public:
    Circles();
    Circles(double r);
    Circles(double r, Point center); // if needed
    ~Circles();
    Point GetPoint(const double t) const;
    Point GetVector(const double t) const;
    std::string GetName() const;
    double GetRadius() const;
};

class Elipses: public Models3D
{
    // 1 = x^2/rX^2 + y^2/rY^2
    // x = rX cos t
    // y = rY sin t
    // 0 <= t < 2pi
    double rX;
    double rY;
    Point center;
    std::string name{"elipses"};
public:
    Elipses();
    Elipses(double rX, double rY);
    Elipses(double rX, double rY, Point center);
    ~Elipses();
    Point GetPoint(const double t) const;
    Point GetVector(const double t) const;
    std::string GetName() const;
    double GetRadius() const;
};

class Helixes: public Models3D
{
    // x = r * cos(t)
    // y = r * sin(t)
    // z = step * t
    double r;
    double step;
    std::string name{"helixes"};
public:
    Helixes();
    Helixes(double r, double step);
    ~Helixes();
    Point GetPoint(const double t) const;
    Point GetVector(const double t) const;
    std::string GetName() const;
    double GetRadius() const;
};

class GetRand
{
    double resDouble;
    int resInt;
public:
    double getRand(double min, double max);
    int getRand(int min, int max);
};