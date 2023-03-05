#ifndef CALCULATOR_BINARY_T_H
#define CALCULATOR_BINARY_T_H

#include <memory>
#include "term_t.h"

namespace calculator {
    class binary_t : public term_t {
    public:
        enum op_t { add, sub, mul, div};

        binary_t(std::shared_ptr<term_t> t1, std::shared_ptr<term_t> t2, op_t o) : term1(std::move(t1)), term2(std::move(t2)), op(o) {}

        double operator()(state_t &s) const override{
            switch (op) {
                case op_t::add:
                    return (*term1)(s) + (*term2)(s);
                case op_t::sub:
                    return (*term1)(s) - (*term2)(s);
                case op_t::mul:
                    return (*term1)(s) * (*term2)(s);
                case op_t::div:
                    auto t2 = (*term2)(s);
                    if (t2 == 0)
                        throw std::runtime_error("division by zero");
                    return (*term1)(s) / t2;
            }
        }
    private:
        std::shared_ptr<term_t> term1;
        std::shared_ptr<term_t> term2;
        op_t op;
    };
}

#endif //CALCULATOR_BINARY_T_H
