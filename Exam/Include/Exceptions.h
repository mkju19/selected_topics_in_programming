//
// Created by marco on 07-08-2023.
//

#ifndef EXAM_EXCEPTIONS_H
#define EXAM_EXCEPTIONS_H
#include "exception"
struct ExistingIDException : public std::exception {
    const std::string whatMsg;

    explicit ExistingIDException(std::string& id): whatMsg("ID: \"" + id  +  "\" Already exist in the symbol table"){}
    [[nodiscard]] const char* what () const noexcept override{
        return whatMsg.c_str();
    }

};

struct IDNotFoundException : public std::exception {
    const std::string whatMsg;

    explicit IDNotFoundException(std::string& id): whatMsg("ID:\"" + id + "\" Does not exist in the symbol table"){}
    [[nodiscard]] const char* what () const noexcept override{
        return whatMsg.c_str();
    }

};
#endif //EXAM_EXCEPTIONS_H
