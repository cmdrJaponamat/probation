#pragma once
#include <ctime>
#include "curves.h"


// struct Point:
Point::Point(): x(0), y(0), z(0) {}
Point::Point(double x, double y, double z):x(x), y(y), z(z) {}
Point::operator std::string() const
{
    std::ostringstream strs;
    strs<<x<<" "<<y<<" "<<z;
    std::string str;
    str = strs.str();
    return str;
}

// class Circles:
Circles::Circles(){}
Circles::Circles(double r):r(r){}
Circles::Circles(double r, Point center):r(r), center(center){}
Circles::~Circles(){}
Point Circles::GetPoint(const double t) const
{
        Point point{(sin(t) * r), (cos(t) * r), 0};
        return point;
}
Point Circles::GetVector(const double t) const
{
    Point vec{(sin(M_PI/2 + t) * r), (cos(M_PI/2 + t) * r), 0};
    return vec;
}
std::string Circles::GetName() const {return name;}
double Circles::GetRadius() const {return r;}

// class Elipses:
Elipses::Elipses(){}
Elipses::Elipses(double rX, double rY):rX(rX), rY(rY) {}
Elipses::Elipses(double rX, double rY, Point center):rX(rX), rY(rY), center(center) {}
Elipses::~Elipses(){}
Point Elipses::GetPoint(const double t) const
{
    Point point{(rX * cos(t)), (rY * sin(t)), 0};
    return point;
}
Point Elipses::GetVector(const double t) const
{
    Point vec{(rX * cos(M_PI/2 + t)), (rY * sin(M_PI/2 + t)), 0};
    return vec;
}
std::string Elipses::GetName() const {return name;}
double Elipses::GetRadius() const {return rX;}

// class Helixes:
Helixes::Helixes(){}
Helixes::Helixes(double r, double step):r(r), step(step) {}
Helixes::~Helixes(){}
Point Helixes::GetPoint(const double t) const
{
    Point point{(r*cos(t)), (r * sin(t)), (step * t)};
    return point;
}
Point Helixes::GetVector(const double t) const
{
    Point point{(r*cos(M_PI/2 + t)), (r * sin(M_PI/2 + t)), step};
    return point;
}
std::string Helixes::GetName() const {return name;}
double Helixes::GetRadius() const {return r;}

// class GetRand:
double GetRand::getRand(double min, double max)
{
    std::srand(std::time(nullptr));
    resDouble = (double)std::rand() / RAND_MAX;
    return min + resDouble * (max - min);
}
int GetRand::getRand(int min, int max)
{
    std::srand(std::time(nullptr));
    return std::rand() % max + min;
}