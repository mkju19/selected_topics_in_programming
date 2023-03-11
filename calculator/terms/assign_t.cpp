#include "assign_t.h"
#include "var_t.h"
#include "visitors/term_visitor.h"
#include "../exceptions.h"
double calculator::assign_t::operator()(calculator::term_t::state_t &s) const {
    switch (op) {
        using enum calculator::assign_t::op_t;
        case eq:
            s[var->id] = (*term)(s);
            break;
        case add:
            s[var->id] += (*term)(s);
            break;
        case sub:
            s[var->id] -= (*term)(s);
            break;
        case mul:
            s[var->id] *= (*term)(s);
            break;
        case div:
            auto t = (*term)(s);
            if (t == 0)
                throw divisionByZeroException();
            s[var->id] /= t;
            break;
    }
    return s[var->id];
}

void calculator::assign_t::accept(calculator::term_visitor &v) {
    v.visit(*this);
}
