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
template <typename TKey, typename T>
class SymbolTable {
    std::unordered_map<TKey, std::unique_ptr<T>> table;

public:
    void addElement(TKey id,T element) {
        if(table.contains(id))
            throw ExistingIDException(id);
        else
            table.emplace(id, std::make_unique<T>(std::move(element)));
   }

    T getElement(TKey id) {
        if(!table.contains(id))
            throw IDNotFoundException(id);
        else
            return *table.at(id);
    }

    void updateElement(TKey id, T element) {
        if (!table.contains(id))
            throw IDNotFoundException(id);
        else
            table[id] = std::make_unique<T>(std::move(element));

    }

    bool contains(TKey id){
        return table.contains(id);
    }

};




#endif //EXAM_SYMBOLTABLE_H
