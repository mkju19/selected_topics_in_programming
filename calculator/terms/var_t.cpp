#include "var_t.h"
#include "visitors/term_visitor.h"

void calculator::var_t::accept(term_visitor &v) {
    v.visit(*this);
}

