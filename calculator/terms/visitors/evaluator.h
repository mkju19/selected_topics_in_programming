#ifndef CALCULATOR_EVALUATOR_H
#define CALCULATOR_EVALUATOR_H
#include "vector"
#include "memory"
#include "term_visitor.h"

namespace calculator {
    struct evaluator : public term_visitor {
        double res = 0;
        state_t& state;

        explicit evaluator (state_t& s) : state(s) {}

        void visit(var_t &) override;

        void visit(const_t&) override;

        void visit(unary_t&) override;

        void visit(binary_t&) override;

        void visit(assign_t&) override;

    };
}
#endif //CALCULATOR_EVALUATOR_H
