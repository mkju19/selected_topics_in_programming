#ifndef CALCULATOR_BINARY_T_H
#define CALCULATOR_BINARY_T_H

#include <memory>
#include "term_t.h"
#include "../exceptions.h"

namespace calculator {

    class binary_t : public term_t {
    public:
        enum class op_t { add, sub, mul, div};

        binary_t(std::shared_ptr<term_t> t1, std::shared_ptr<term_t> t2, op_t o) : term1(std::move(t1)), term2(std::move(t2)), op(o) {}

        double operator()(state_t &s) const override{
            auto t1 = (*term1)(s);
            auto t2 = (*term2)(s);
            switch (op) {
                using enum calculator::binary_t::op_t;
                case add:
                    return t1 + t2;
                case sub:
                    return t1 - t2;
                case mul:
                    return t1 * t2;
                case div:
                    if (t2 == 0)
                        throw divisionByZeroException();
                    return t1 / t2;
                default:
                    return 0;
            }
        }
        void accept(term_visitor& v) override;
    private:
        std::shared_ptr<term_t> term1;
        std::shared_ptr<term_t> term2;
        op_t op;

        friend class evaluator;
    };
}

#endif //CALCULATOR_BINARY_T_H
