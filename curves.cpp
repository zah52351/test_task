#include "curves.h"
	
double Circle::radius() const { return radius_; }

Point Circle::along_the_curve_point(double t) const {
	return Point {
		radius_ * std::cos(t) + center_.x_,
		radius_ * std::sin(t) + center_.y_,
		center_.z_
	};
}

Deriative Circle::along_the_curve_deriative(double t) const {
	return Deriative {
		-1 * radius_ * std::sin(t),
		radius_ * std::cos(t)
	};
}

Point Ellipse::along_the_curve_point(double t) const {
	return Point {
		radX_ * std::cos(t) + center_.x_,
		radY_ * std::sin(t) + center_.y_,
		center_.z_
	};
}

Deriative Ellipse::along_the_curve_deriative(double t) const {
	return Deriative {
		-1 * radX_ * std::sin(t),
		radY_* std::cos(t)
	};
}

Point Helixe::along_the_curve_point(double t) const {
	return Point {
		rad_ * t * std::cos(t) + center_.x_,
		rad_* t * std::sin(t) + center_.y_,
		step_ * t + center_.z_
	};
}
	
Deriative Helixe::along_the_curve_deriative(double t) const {
	return Deriative {
		rad_ * (std::cos(t) - t * std::sin(t)),
		rad_ * (std::sin(t) + t * std::cos(t)),
		step_
	};
}
