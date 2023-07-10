


#ifndef CALCULATOR_UNARY_T_H
#define CALCULATOR_UNARY_T_H

#include "term_t.h"
#include <memory>

namespace calculator {

    class unary_t : public term_t {
    public:
        enum class op_t { plus, minus};

        ~unary_t() override = default;

        unary_t(std::shared_ptr<term_t> term, op_t op) : term(std::move(term)), op(op) {}

        void accept(calculator::term_visitor & v) override;

    private:
        std::shared_ptr<term_t> term;
        op_t op;

        friend class evaluator;
        friend class printer;
    };
}

#endif //CALCULATOR_UNARY_T_H
