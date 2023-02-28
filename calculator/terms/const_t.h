#include "term_t.h"

#ifndef CALCULATOR_CONST_T_H
#define CALCULATOR_CONST_T_H

namespace calculator {
    class const_t : term_t {
        double value = 0;

    public:
        ~const_t() override = default;

        double operator()(state_t &_) const override { return value; }
    };
}

#endif //CALCULATOR_CONST_T_H
