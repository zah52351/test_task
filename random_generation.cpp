#include "random_generation.h"


void Random_generator::set_diapason(double min, double max) {
	
	if ((std::abs(max) + std::abs(min)) == 0) throw std::invalid_argument("zero diapason");
	real_distr.param(std::uniform_real_distribution<double>::param_type(min, max));;
}

Pcurv Random_generator::circle() {

	double radius = std::abs(real_distr(rd));
	return std::make_shared<Circle>(Point{real_distr(rd), real_distr(rd)}, radius);
}

Pcurv Random_generator::ellipse() {

	double radX = std::abs(real_distr(rd));
	double radY = std::abs(real_distr(rd));
	return std::make_shared<Ellipse>(Point{real_distr(rd), real_distr(rd)}, radX, radY);
}

Pcurv Random_generator::helixe() {

	double radius = std::abs(real_distr(rd));
	double step = real_distr(rd);
	return std::make_shared<Helixe>
		(Point{ real_distr(rd), real_distr(rd), real_distr(rd) }, radius, step);
}

Pcurv Random_generator::random_shape() {

	switch (curve_distr(rd)) {
	case circle_t:
		return circle();
	case ellipse_t:
		return ellipse();
	case helixe_t:
		return helixe();
	default:
		return circle();
	}
}

std::random_device Random_generator::rd;