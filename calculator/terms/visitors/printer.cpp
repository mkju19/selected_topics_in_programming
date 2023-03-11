#include <iostream>
#include "printer.h"
#include "../var_t.h"
#include "../const_t.h"
#include "../unary_t.h"
#include "../binary_t.h"
#include "../assign_t.h"

namespace calculator {
    void printer::visit(calculator::var_t& v) {
        auto name = names[v.id];
        auto val = state[v.id];

        os << "{" << name << ":" << val << "}";
    }

    void printer::visit(const_t & c) {
        os << "{" << c.value << "}";
    }

    void printer::visit(unary_t & u) {
        os << "(";
        if (u.op == unary_t::op_t::plus)
            os << "+";
        else
            os << "-";
        u.term->accept(*this);
        os << ")";
    }

    void printer::visit(binary_t & b) {

        os << "(";
        b.term1->accept(*this);

        switch (b.op) {
            using enum calculator::binary_t::op_t;
            case add:
                os << " + ";
                break;
            case sub:
                os << " - ";
                break;
            case mul:
                os << " * ";
                break;
            case div:
                os << " / ";
                break;
        }
        b.term2->accept(*this);
        os << ")";
    }

    void printer::visit(assign_t & a) {
        auto name = names[a.var->id];

        os << "{" << name << ":";

        switch (a.op) {
            using enum calculator::assign_t::op_t;
            case add:
                os << "+=";
                break;
            case sub:
                os << "-=";
                break;
            case mul:
                os << "*=";
                break;
            case div:
                os << "/=";
                break;
            case eq:
                os << "=";
                break;
        }
        a.term->accept(*this);
    }
}

