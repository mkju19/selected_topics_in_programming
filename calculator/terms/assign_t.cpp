#include "assign_t.h"
#include "var_t.h"
#include "visitors/term_visitor.h"
#include "../exceptions.h"

void calculator::assign_t::accept(calculator::term_visitor &v) {
    v.visit(*this);
}
