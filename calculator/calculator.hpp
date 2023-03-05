#ifndef INCLUDE_ALGEBRA_HPP
#define INCLUDE_ALGEBRA_HPP

#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include "terms/term_t.h"
#include "terms/var_t.h"
#include "terms/unary_t.h"
#include "terms/binary_t.h"


namespace calculator
{
    /** Type to capture the state of entire calculator (one number per variable): */
    using state_t = std::vector<double>;
    /** Forward declarations to get around circular dependencies: */
    struct expr_t;

    struct expr_t
    {
        std::shared_ptr<term_t> term;

        expr_t& operator=(expr_t&& other) noexcept = default;
        expr_t(expr_t&& other) noexcept = default;
        ~expr_t() noexcept = default;

        explicit expr_t(std::shared_ptr<var_t> t) : term(std::move(t)) {};
        explicit expr_t(std::shared_ptr<unary_t> t) : term(std::move(t)) {};
        explicit expr_t(std::shared_ptr<binary_t> t) : term(std::move(t)) {};
        explicit expr_t(std::shared_ptr<assign_t> t) : term(std::move(t)) {};
        double operator()(state_t& s) const { return (*term)(s);}

    };

    class symbol_table_t
    {
        std::vector<std::string> names;
        std::vector<double> initial;
    public:
        [[nodiscard]] expr_t var(std::string name, double init = 0) {
            auto res = names.size();
            names.push_back(std::move(name));
            initial.push_back(init);
            auto v = std::make_shared<var_t>(res);
            return expr_t{std::move(v)};
        }
        [[nodiscard]] state_t state() const { return {initial}; }

//        expr_t operator()(var_t& v) const {
//            auto varP = std::make_shared<var_t>(v);
//            return calculator::expr_t{std::move(varP)};
//        }
    };

    /** assignment operation */
//    inline double var_t::operator()(state_t& s, const expr_t& e) const { return s[id] = e(s); }


    /** unary operators: */
    inline expr_t operator+(const expr_t& e) {
        auto unaryP = std::make_shared<unary_t>(e.term, unary_t::plus);
        return expr_t{std::move(unaryP)};
    }
    inline expr_t operator-(const expr_t& e) {
        auto unaryP = std::make_shared<unary_t>(e.term, unary_t::minus);
        return expr_t{std::move(unaryP)};
    }

    /** binary operators: */
    inline expr_t operator+(const expr_t& e1, const expr_t& e2) {
        auto binaryP = std::make_shared<binary_t>(e1.term, e2.term, binary_t::add);
        return expr_t{binaryP};
    }
    inline expr_t operator-(const expr_t& e1, const expr_t& e2) {
        auto binaryP = std::make_shared<binary_t>(e1.term, e2.term, binary_t::sub);
        return expr_t{binaryP};
    }
    inline expr_t operator/(const expr_t& e1, const expr_t& e2) {
        auto binaryP = std::make_shared<binary_t>(e1.term, e2.term, binary_t::div);
        return expr_t{binaryP};
    }
    inline expr_t operator*(const expr_t& e1, const expr_t& e2) {
        auto binaryP = std::make_shared<binary_t>(e1.term, e2.term, binary_t::mul);
        return expr_t{binaryP};
    }
    inline expr_t operator<<=(const expr_t& v, const expr_t& e) {
        auto varP = std::dynamic_pointer_cast<var_t>(v.term);
        if (varP == nullptr)
            throw std::runtime_error("assignment destination must be a variable expression");
        auto assignP = std::make_shared<assign_t>(std::move(varP), e.term, assign_t::op_t::eq);
        return expr_t{assignP};
    }
    inline expr_t operator+=(const expr_t& v, const expr_t& e) {
        auto varP = std::dynamic_pointer_cast<var_t>(v.term);
        if (varP == nullptr)
            throw std::runtime_error("assignment destination must be a variable expression");
        auto assignP = std::make_shared<assign_t>(std::move(varP), e.term, assign_t::op_t::add);
        return expr_t{assignP};
    }
    inline expr_t operator-=(const expr_t& v, const expr_t& e) {
        auto varP = std::dynamic_pointer_cast<var_t>(v.term);
        if (varP == nullptr)
            throw std::runtime_error("assignment destination must be a variable expression");
        auto assignP = std::make_shared<assign_t>(std::move(varP), e.term, assign_t::op_t::sub);
        return expr_t{assignP};
    }
    inline expr_t operator*=(const expr_t& v, const expr_t& e) {
        auto varP = std::dynamic_pointer_cast<var_t>(v.term);
        if (varP == nullptr)
            throw std::runtime_error("assignment destination must be a variable expression");
        auto assignP = std::make_shared<assign_t>(std::move(varP), e.term, assign_t::op_t::mul);
        return expr_t{assignP};
    }
    inline expr_t operator/=(const expr_t& v, const expr_t& e) {
        auto varP = std::dynamic_pointer_cast<var_t>(v.term);
        if (varP == nullptr)
            throw std::runtime_error("assignment destination must be a variable expression");
        auto assignP = std::make_shared<assign_t>(std::move(varP), e.term, assign_t::op_t::div);
        return expr_t{assignP};
    }

}


#endif // INCLUDE_ALGEBRA_HPP

