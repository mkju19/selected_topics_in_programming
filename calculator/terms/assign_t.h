#ifndef CALCULATOR_ASSIGN_T_H
#define CALCULATOR_ASSIGN_T_H

#include <memory>
#include "term_t.h"


namespace calculator {
    class var_t;

    class assign_t : public term_t {
    public:
        enum op_t {add, sub, mul, div, eq};
        assign_t(std::shared_ptr<var_t> v, std::shared_ptr<term_t> t, op_t o) :var(std::move(v)), term(std::move(t)), op(o){};
        double operator()(state_t &s)const override;
    private:
        std::shared_ptr<var_t> var;
        std::shared_ptr<term_t> term;
        op_t op;
    };
}

#endif //CALCULATOR_ASSIGN_T_H