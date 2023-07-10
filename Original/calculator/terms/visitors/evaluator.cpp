#include "evaluator.h"
#include "../var_t.h"
#include "../const_t.h"
#include "../unary_t.h"
#include "../binary_t.h"
#include "../assign_t.h"

void calculator::evaluator::visit(var_t& v) {
    res = state[v.id];
}

void calculator::evaluator::visit(const_t& c ) {
    res = c.value;
}

void calculator::evaluator::visit(unary_t& u) {
    auto op = u.op;

    switch (op) {
        case unary_t::op_t::plus:
            (*u.term).accept(*this);
            break;
        case unary_t::op_t::minus:
            (*u.term).accept(*this);
            res = -res;
            break;
    }
}

void calculator::evaluator::visit(binary_t& b) {
    auto op = b.op;
    auto e2 = evaluator{this->state};

    switch (op) {
        case binary_t::op_t::add:
            b.term1->accept(*this);
            b.term2->accept(e2);
            res = res + e2.res;
            break;
        case binary_t::op_t::sub:
            b.term1->accept(*this);
            b.term2->accept(e2);
            res = res - e2.res;
            break;
        case binary_t::op_t::mul:
            b.term1->accept(*this);
            b.term2->accept(e2);
            res = res * e2.res;
            break;
        case binary_t::op_t::div:
            b.term2->accept(e2);
            if (e2.res == 0)
                throw divisionByZeroException();

            b.term1->accept(*this);
            res = res / e2.res;
            break;
    }
}

void calculator::evaluator::visit(assign_t& a) {
    auto op = a.op;
    auto var = a.var;

    switch (op) {
        case assign_t::op_t::eq:
            a.term->accept(*this);
            state[var->id] = res;
            break;
        case assign_t::op_t::add:
            a.term->accept(*this);
            state[var->id] += res;
            res = state[var->id];
            break;
        case assign_t::op_t::sub:
            a.term->accept(*this);
            state[var->id] -= res;
            res = state[var->id];
            break;
        case assign_t::op_t::mul:
            a.term->accept(*this);
            state[var->id] *= res;
            res = state[var->id];
            break;
        case assign_t::op_t::div:
            a.term->accept(*this);
            if (res == 0)
                throw divisionByZeroException();

            state[var->id] /= res;
            res = state[var->id];
            break;
    }
}