//
// Created by marco on 07-08-2023.
//

#ifndef EXAM_SYMBOLTABLE_H
#define EXAM_SYMBOLTABLE_H

#include <string>
#include <memory>
#include <unordered_map>
#include "Exceptions.h"

//REQUIREMENT 3 - Generic symbol table
template <typename T>
class SymbolTable {
    std::unordered_map<std::string, std::unique_ptr<T>> table;

public:
    void addElement(std::string id,T element) {
        if(table.contains(id))
            throw ExistingIDException(id);
        else
            table.emplace(id, std::make_unique<T>(std::move(element)));
   }

    T getElement(std::string id) {
        if(!table.contains(id))
            throw IDNotFoundException(id);
        else
            return *table.at(id);
    }

    void updateElement(std::string id, T element) {
        if (!table.contains(id))
            throw IDNotFoundException(id);
        else
            table[id] = std::make_unique<T>(std::move(element));

    }



};




#endif //EXAM_SYMBOLTABLE_H
