#ifndef CALCULATOR_SYMBOL_TABLE_T_H
#define CALCULATOR_SYMBOL_TABLE_T_H
namespace calculator {

    class expr_t;
    using state_t = std::vector<double>;

    class symbol_table_t {
        std::vector<double> initial{};
        std::vector<std::string> names{};
    public:
        [[nodiscard]] std::vector<std::string>const & getNames() const {return names;};
        [[nodiscard]] expr_t var(std::string name, double init = 0);

        [[nodiscard]] state_t state() const { return {initial}; };
    };
}

#endif //CALCULATOR_SYMBOL_TABLE_T_H
