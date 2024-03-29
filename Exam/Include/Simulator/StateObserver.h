//
// Created by marco on 09-08-2023.
//

#ifndef EXAM_STATEOBSERVER_H
#define EXAM_STATEOBSERVER_H


#include <vector>
#include <string>
#include <iostream>

struct StateObserver {
    virtual void observe(const std::vector<std::string>& vec){
        std::cout<< "| ";
        for (const auto& item: vec){
            std::cout << item << " | ";
        }
        std::cout<< std::endl;
    }
    virtual void observeParallel(const std:: vector<std::string>& vec, int id){
        observe(vec);
    }
    virtual void stop(){
        std::cout<< "stopped" << std::endl;
    }
    virtual void stopParallel(){
        stop();
    }
    virtual ~StateObserver()=default;
};


#endif //EXAM_STATEOBSERVER_H
