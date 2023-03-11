#ifndef CALCULATOR_TERM_T_H
#define CALCULATOR_TERM_T_H

#include <vector>

namespace calculator {

    struct term_visitor;
    struct evaluator;
    struct printer;
    class ostream;

    using state_t = std::vector<double>;

    struct term_t {
        using state_t = std::vector<double>;

        term_t() = default;

        virtual ~term_t() noexcept = default;

        virtual double operator()(state_t &s) const = 0;

        virtual void accept(term_visitor&) = 0;
    };
}

#endif //CALCULATOR_TERM_T_H
