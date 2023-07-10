#include "assign_t.h"
#include "var_t.h"
#include "visitors/term_visitor.h"

void calculator::assign_t::accept(calculator::term_visitor &v) {
    v.visit(*this);
}
