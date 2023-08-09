//
// Created by marco on 09-08-2023.
//

#ifndef EXAM_SIMPLEEXAMPLE_H
#define EXAM_SIMPLEEXAMPLE_H
#include <utility>

#include "..//Include/Simulator/StateObserver.h"

class SimpleExample {
    StateObserver observer;
public:
    void run();
    explicit SimpleExample(StateObserver  obs): observer(std::move(obs)){};
};


#endif //EXAM_SIMPLEEXAMPLE_H