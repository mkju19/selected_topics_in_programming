#ifndef CALCULATOR_SYMBOL_TABLE_T_H
#define CALCULATOR_SYMBOL_TABLE_T_H

namespace calculator {

    class symbol_table_t {
        std::vector<std::string> names;
        std::vector<double> initial;
    public:
        [[nodiscard]] expr_t var(std::string name, double init = 0);

        [[nodiscard]] state_t state() const { return {initial}; };
    };
}

#endif //CALCULATOR_SYMBOL_TABLE_T_H
