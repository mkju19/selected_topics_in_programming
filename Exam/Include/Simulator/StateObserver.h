//
// Created by marco on 09-08-2023.
//

#ifndef EXAM_STATEOBSERVER_H
#define EXAM_STATEOBSERVER_H


#include <string>
#include <vector>
#include <iostream>

struct StateObserver {
    virtual void observe(const std::vector<std::string>& vec) const {
        std::cout<< "| ";
        for (const auto& item: vec){
            std::cout << item << " | ";
        }
        std::cout<< std::endl;
    };
    virtual void stop() const {/* does nothing when not overridden*/};
};


#endif //EXAM_STATEOBSERVER_H
