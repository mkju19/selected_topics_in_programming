//
// Created by marco on 07-08-2023.
//

#ifndef EXAM_SYMBOLTABLE_H
#define EXAM_SYMBOLTABLE_H

#include <string>
#include <unordered_map>
#include "Exceptions.h"

//REQUIREMENT 3 - Generic symbol table
template <typename T>
class SymbolTable {
    std::unordered_map<std::string, T> table;

public:
    void addElement(std::string id,T element) {
        if(table.contains(id))
            throw ExistingIDException(id);
        else
            table.emplace(id, element);
   }

    T getElement(std::string id) {
        if(!table.contains(id))
            throw IDNotFoundException(id);
        else
            return table.at(id);
    }

    void updateElement(std::string id, T val) {
        if (!table.contains(id))
            throw IDNotFoundException(id);
        else
            table[id] = val;

    }


};




#endif //EXAM_SYMBOLTABLE_H
