#ifndef CALCULATOR_TERM_VISITOR_H
#define CALCULATOR_TERM_VISITOR_H

namespace calculator {
    class var_t;
    class const_t;
    class unary_t;
    class assign_t;
    class binary_t;

    struct term_visitor {
        using state_t = std::vector<double>;

        virtual ~term_visitor() = default;

        virtual void visit(var_t&) = 0;

        virtual void visit(const_t&) = 0;

        virtual void visit(unary_t&) = 0;

        virtual void visit(binary_t&) = 0;

        virtual void visit(assign_t&) = 0;
    };
}

#endif //CALCULATOR_TERM_VISITOR_H
