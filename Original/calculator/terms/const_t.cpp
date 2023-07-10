#include "const_t.h"
#include "visitors/term_visitor.h"
void calculator::const_t::accept(calculator::term_visitor &v) {
    v.visit(*this);
}
