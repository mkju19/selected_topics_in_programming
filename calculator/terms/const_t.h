#ifndef CALCULATOR_CONST_T_H
#define CALCULATOR_CONST_T_H
#include "term_t.h"

namespace calculator {
    class const_t : public term_t {
        double value = 0;

    public:
        const_t(double c) : value(c){};
        const_t(int c) : value(c){};
        ~const_t() override = default;

        double operator()(state_t &_) const override { return value; }
    };
}

#endif //CALCULATOR_CONST_T_H
