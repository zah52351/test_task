#pragma once
#include <stdexcept>
#include "curves.h"

using Pcurv = std::shared_ptr<Curves>;
class Random_generator {
	enum curve_t { circle_t, ellipse_t, helixe_t };
	static std::random_device rd;
	std::uniform_real_distribution<double> real_distr{ -1, 1 };
	std::uniform_int_distribution<> curve_distr{ circle_t, helixe_t };
public:	
	void set_diapason(double min, double max);
	Pcurv circle();
	Pcurv ellipse();
	Pcurv helixe();
	Pcurv random_shape();
};