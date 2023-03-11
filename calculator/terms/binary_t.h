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
            switch (op) {
                using enum calculator::binary_t::op_t;
                case add:
                    return (*term1)(s) + (*term2)(s);
                case sub:
                    return (*term1)(s) - (*term2)(s);
                case mul:
                    return (*term1)(s) * (*term2)(s);
                case div:
                    auto t2 = (*term2)(s);
                    if (t2 == 0)
                        throw divisionByZeroException();
                    return (*term1)(s) / t2;
            }
        }
        void accept(term_visitor& v) override;
    private:
        std::shared_ptr<term_t> term1;
        std::shared_ptr<term_t> term2;
        op_t op;

        friend class evaluate;
    };
}

#endif //CALCULATOR_BINARY_T_H
