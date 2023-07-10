

#ifndef CALCULATOR_EXCEPTIONS_H
#define CALCULATOR_EXCEPTIONS_H

#include <exception>

struct divisionByZeroException : public std::exception {
    [[nodiscard]] const char* what () const noexcept override{
        return "division by zero";
    }

};

struct destMustBeVariableException : public std::exception {
    [[nodiscard]] const char* what () const noexcept override{
        return "assignment destination must be a variable expression";
    }

};

#endif //CALCULATOR_EXCEPTIONS_H
