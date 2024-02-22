#include <vector>
#include <algorithm>
#include "curves.h"
#include "random_generation.h"

int main() {
    
    const size_t vec_sz = 10;
    const double pi = std::acos(-1);
    std::vector<Pcurv> p_vec;

    Random_generator generator;
    try {
        generator.set_diapason(0, 100);
        for (size_t i = 0; i < vec_sz; ++i) {
            p_vec.emplace_back(generator.random_shape());
        }
    } catch(const std::invalid_argument& ex) {
        std::cout << ex.what() << '\n';
    } catch(const std::bad_alloc& e) {
        std::cout << e.what() << '\n';
    }
    
    using PCircle = std::shared_ptr<Circle>;
    std::vector<PCircle> circle_vec;
    double radius_sum = 0;

    for (auto& pv : p_vec) {

        const std::type_info& typeInfoCurv = typeid(*pv);
        std::cout << typeInfoCurv.name() << ' ' << pv->along_the_curve_point(pi / 4) << ' '
            << pv->along_the_curve_deriative(pi / 4) << '\n'; 

        if (typeid(*pv) == typeid(Circle)) {

            circle_vec.emplace_back(std::dynamic_pointer_cast<Circle>(pv)); 
            radius_sum += circle_vec.back()->radius();
        }
    }

    std::sort(circle_vec.begin(), circle_vec.end(), [](const auto& lhs, const auto& rhs) 
        {
            return lhs->radius() < rhs->radius();
        });

    for (auto& pc : circle_vec) {
        std::cout << pc->radius() << std::endl;
    }
    std::cout << "sum = " << radius_sum << std::endl;
}