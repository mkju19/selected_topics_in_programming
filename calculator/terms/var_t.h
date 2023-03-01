#ifndef CALCULATOR_VAR_T_H
#define CALCULATOR_VAR_T_H

#include "term_t.h"
#include "assign_t.h"
//#include "../calculator.hpp"

namespace calculator {
    class var_t : term_t {
        size_t id;

    public:
        explicit var_t(const size_t &index) : id(index) {};

        double operator()(state_t &s) const override { return s[id]; }

        var_t(const var_t &) = default;

        friend class assign_t;

//        friend class symbol_table_t;
    };
}
//    class var_t
//    {
//        size_t id;
//        /** only friends are allowed to construct variable instances */
//        explicit var_t(size_t id): id{id} {}
//    public:
//        var_t(const var_t&) = default;
//        var_t& operator=(const var_t&) = default;
//        /** returns the value of the variable stored in a state */
//        double operator()(const state_t& s) const { return s[id]; }
//        /** evaluates an assignment to a given expression and returns the resulting value */
//        double operator()(state_t&, const expr_t&) const;
//        friend class symbol_table_t;
//    };


#endif //CALCULATOR_VAR_T_H
