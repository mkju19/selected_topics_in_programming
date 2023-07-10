#include "unary_t.h"
#include "visitors/term_visitor.h"

void calculator::unary_t::accept(calculator::term_visitor &v) {
    v.visit(*this);
}
