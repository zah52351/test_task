#pragma once
#include <iostream>
#include <random>
#include <cmath>
#include <memory>


struct Point { double x_, y_, z_ = 0; };
struct Deriative { double x_, y_, z_; };

class Curves {
protected:
	Point center_;
public:
	Curves() = default;
	Curves(const Point& center) : center_(center) {}
	virtual ~Curves() {}
public:
	virtual Point along_the_curve_point(double t) const = 0;
	virtual Deriative along_the_curve_deriative(double t) const = 0;
};

class Circle : public Curves {
	double radius_;
public:
	Circle() = default;
	Circle(const Point& center, double radius) : Curves(center), radius_(radius) {}
	~Circle() {}
public:
	double radius() const;
	Point along_the_curve_point(double t) const override;
	Deriative along_the_curve_deriative(double t) const override;
};

class Ellipse : public Curves {
	double radX_;
	double radY_;
public:
	Ellipse() = default;
	Ellipse(const Point& center, double radius_x, double radius_y)
		: Curves(center)
		, radX_(radius_x)
		, radY_(radius_y) {}
	~Ellipse() {}
public:
	Point along_the_curve_point(double t) const override;
	Deriative along_the_curve_deriative(double t) const override;
};

class Helixe : public Curves {
	double rad_;
	double step_;
public:
	Helixe() = default;
	Helixe(const Point& center, double radius, double step)
		: Curves(center)
		, rad_(radius)
		, step_(step) {}
	~Helixe() {}
public:
	Point along_the_curve_point(double t) const override;
	Deriative along_the_curve_deriative(double t) const override;
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
	return os << p.x_ << ' ' << p.y_ << ' ' << p.z_ << '\n';
}

std::ostream& operator<<(std::ostream& os, const Deriative& d) {
	return os << d.x_ << ' ' << d.y_ << ' ' << d.z_ << '\n';
}