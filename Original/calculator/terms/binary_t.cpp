#include "binary_t.h"
#include "visitors/term_visitor.h"

void calculator::binary_t::accept(calculator::term_visitor &v) {
    v.visit(*this);
}
