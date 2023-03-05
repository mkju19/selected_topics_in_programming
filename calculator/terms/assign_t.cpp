#include "assign_t.h"
#include "var_t.h"

double calculator::assign_t::operator()(calculator::term_t::state_t &s) const {
    switch (op) {
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
                throw std::runtime_error("division by zero");
            s[var->id] /= t;
            break;
    }
    return s[var->id];
}
