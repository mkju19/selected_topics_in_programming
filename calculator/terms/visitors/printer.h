#ifndef CALCULATOR_PRINTER_H
#define CALCULATOR_PRINTER_H
#include <vector>
#include <iostream>
#include "term_visitor.h"


namespace calculator {
    struct printer : public term_visitor {
        const state_t& state;
        const std::vector<std::string>& names;
        std::ostream& os = std::cout;

        explicit printer (const state_t& s, const std::vector<std::string>& n) : state(s), names(n) {}

        void visit(var_t &) override;

        void visit(const_t&) override;

        void visit(unary_t&) override;

        void visit(binary_t&) override;

        void visit(assign_t&) override;
    };
}

#endif //CALCULATOR_PRINTER_H
