#ifndef CALCULATOR_ASSIGN_T_H
#define CALCULATOR_ASSIGN_T_H

#include <memory>
#include "term_t.h"
#include "var_t.h"

namespace calculator {
    class assign_t : term_t {
        std::shared_ptr<var_t> var;
        std::shared_ptr<term_t> term;
    public:
        double operator()(state_t &s) { s[var->id] = term->operator()(s); }
    };
}

#endif //CALCULATOR_ASSIGN_T_H
