#ifndef CALCULATOR_CONST_T_H
#define CALCULATOR_CONST_T_H
#include "term_t.h"

namespace calculator {
    struct evaluator;

    class const_t : public term_t {
        double value = 0;

    public:
        explicit const_t(double c) : value(c){};
        explicit const_t(int c) : value(c){};
        ~const_t() override = default;

        double operator()(state_t &_) const override { return value; }

        void accept(term_visitor & v) override;

        friend class evaluator;
        friend class printer;
    };
}

#endif //CALCULATOR_CONST_T_H
