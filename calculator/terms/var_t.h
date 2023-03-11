#ifndef CALCULATOR_VAR_T_H
#define CALCULATOR_VAR_T_H

#include <vector>
#include <iostream>
#include "term_t.h"

namespace calculator {

    class assign_t;

    class var_t : public term_t {
        size_t id;

    public:
        explicit var_t(const size_t &index) : id(index) {};

        void accept(term_visitor& v) override ;

        var_t(const var_t &) = default;

        friend class assign_t;
        friend class symbol_table_t;
        friend class evaluator;
        friend class printer;
    };
}


#endif //CALCULATOR_VAR_T_H
