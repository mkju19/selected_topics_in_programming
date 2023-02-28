#include <memory>
#include "term_t.h"

#ifndef CALCULATOR_BINARY_T_H
#define CALCULATOR_BINARY_T_H

namespace calculator {
    class binary_t : term_t {
    public:
        enum op_t {
            add, sub, mul, div
        };
    private:
        op_t op;
        std::shared_ptr<term_t> term1;
        std::shared_ptr<term_t> term2;

        double operator()(state_t s) {
            switch (op) {
                case op_t::add:
                    return (*term1)(s) + (*term2)(s);
                case op_t::sub:
                    return (*term1)(s) - (*term2)(s);
                case op_t::mul:
                    return (*term1)(s) * (*term2)(s);
                case op_t::div:
                    return (*term1)(s) / (*term2)(s);
            }
        }
    };
}

#endif //CALCULATOR_BINARY_T_H
