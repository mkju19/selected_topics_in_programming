#include "calculator.hpp"
#include "symbol_table_t.h"


calculator::expr_t calculator::symbol_table_t::var(std::string name, double init) {
    auto res = names.size();
    names.push_back(std::move(name));
    initial.push_back(init);
    auto v = std::make_shared<var_t>(res);
    return expr_t{std::move(v)};
}
