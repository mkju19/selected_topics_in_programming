
#ifndef EXAM_PARALLELSIMULATOR_H
#define EXAM_PARALLELSIMULATOR_H
#include <thread>
#include <queue>
#include <condition_variable>
#include "StateObserver.h"
#include "Simulator.h"

using resultQueue_t = std::queue<std::vector<std::string>>;

class ParallelSimulator {

    std::mutex mut;
//    StateObserver observer;
    Simulator sim;

    class ParallelObserver: public StateObserver{
        bool stopped = false;
        resultQueue_t queue;
    public:
        bool isStopped(){return stopped;}
        bool queueEmpty(){return queue.empty();}
        std::vector<std::string> popQueue(){
            auto vec = queue.front();
            queue.pop();
            return vec;
        }
        void observe(const std::vector<std::string>& vec) override {
            queue.push(vec);
        }
        void stop() override{
            stopped = true;
        }
    };

    void simulate(double endTime, StateObserver& observer, Simulator simulator);

public:
    ParallelSimulator(const Simulator& simulator/*, const StateObserver&  obs*/) : /*observer(obs),*/
                                                                               sim(simulator){};
    void run(double endTime, StateObserver& observer, int numberOfThreads);

};


#endif //EXAM_PARALLELSIMULATOR_H
