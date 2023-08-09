//
// Created by marco on 09-08-2023.
//

#ifndef EXAM_CIRCADIANRYTHMEXAMPLE_H
#define EXAM_CIRCADIANRYTHMEXAMPLE_H
#include "../Include/Simulator/StateObserver.h"

class CircadianRythmExample {
    StateObserver observer;
public:
    void run();
    explicit CircadianRythmExample(StateObserver  obs): observer(std::move(obs)){};
};


#endif //EXAM_CIRCADIANRYTHMEXAMPLE_H
