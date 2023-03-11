#ifndef CALCULATOR_VAR_T_H
#define CALCULATOR_VAR_T_H

//#include "term_t.h"
//#include "assign_t.h"
//#include "visitors/term_visitor.h"
//#include "visitors/evaluate.h"
//#include "../symbol_table_t.h"
#include <vector>
#include "term_t.h"

namespace calculator {

    class assign_t;

    class var_t : public term_t {
        size_t id;

    public:
        explicit var_t(const size_t &index) : id(index) {};

        double operator()(state_t& s) const override { return s[id]; }
        void accept(term_visitor& v) override ;

        var_t(const var_t &) = default;

        friend class assign_t;
        friend class evaluate;
        friend class symbol_table_t;
    };
}


#endif //CALCULATOR_VAR_T_H
