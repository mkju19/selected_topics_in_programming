#include "Include/Simulator/StateObserver.h"

#ifndef EXAM_OBSERVER_H
#define EXAM_OBSERVER_H


struct DerivedObserver: public StateObserver {
    void observe(const std::vector<std::string>& vec) const override{
        std::cout<< "; ";
        for (const auto& item: vec){
            std::cout << item << " ; ";
        }
        std::cout<< std::endl;
    };
};


#endif //EXAM_OBSERVER_H
