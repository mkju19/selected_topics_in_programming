#ifndef CALCULATOR_EVALUATE_H
#define CALCULATOR_EVALUATE_H
#include "vector"
#include "memory"
#include "term_visitor.h"


namespace calculator {
    struct evaluate : public term_visitor {
        double res;
        std::shared_ptr<state_t> state;

        explicit evaluate (std::shared_ptr<state_t> s) : state(std::move(s)) {}
        evaluate() = default;

        void visit(var_t &) override;

        void visit(const_t&) override;

        void visit(unary_t&) override;

        void visit(binary_t&) override;

        void visit(assign_t&) override;

    };
}
#endif //CALCULATOR_EVALUATE_H
