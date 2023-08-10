#include <iostream>
#include "Include/Simulator/StateObserver.h"
#include "Examples/SimpleExample.h"
#include "Examples/CircadianRythmExample.h"
#include "Examples/CovidExample.h"

//#include <graphviz/gvc.h>
//#include "graphviz/cgraph.h"


class Printer : public StateObserver{
    std::vector<std::vector<std::string>> lines;

    void printVector(const std::vector<std::string>& vec){
//        std::cout<< "| ";
        for (const auto& item: vec){
            std::cout << item << " ; ";
        }
        std::cout<< std::endl;
    }
public:
    void observe(const std::vector<std::string>& vec) override{
        lines.push_back(vec);
    };
    void stop() override {
        std::cout<< "STARTS PRINTING" << std::endl;
        for (const auto &line : lines){
            printVector(line);
        }
        std::cout << "STOP PRINTING" << std::endl;
        lines.clear();
    }
};

class Counter : public StateObserver{
    size_t numberOfReactions = 0;
    void observe(const std::vector<std::string>& vec) override{
        numberOfReactions++;
    }
    void stop() override{
        std::cout<< "Counted " << numberOfReactions << " reactions." << std::endl;
        numberOfReactions = 0;
    }
};

class AveragePeakHospitalized : public StateObserver {
    std::unordered_map<int, int> peaks;
    size_t peak = 0;
    void observe(const std::vector<std::string>& vec)override{
        for(const auto &element : vec){
            //The hospitalized variable will have H: as the first to chars in the string
            if (element.at(0) == 'H' && element.at(1) == ':'){
                auto val_str = element.substr(2);

                auto val = std::stoi(val_str);

                peak = val > peak ? val : peak;
            }
        }
    }
    void stop() override{
        std::cout<< "The peak of hospitalized agents is: " << peak << std::endl;
        peak = 0;
    }
    void observeParallel(const std::vector<std::string> &vec, int id) override{
        for(const auto &element : vec){
            //The hospitalized variable will have H: as the first to chars in the string
            if (element.at(0) == 'H' && element.at(1) == ':'){
                auto val_str = element.substr(2);
                auto val = std::stoi(val_str);

                if(peaks.contains(id)){
                    auto old = peaks.at(id);
                    peaks.at(id) = val > old ? val : old;
                } else {
                    peaks.emplace(id, val);
                }
            }
        }
    }
    void stopParallel() override{
        auto size = peaks.size();
        auto sum = 0;
        for(const auto& [id, val] : peaks){
            sum += val;
        }
        std::cout << "The estimated average peak hospitalized over " << size << " simulations: " << sum/size << std::endl;
        peaks.clear();
    }
};

int main() {
    auto observerPrinter = Printer{};
    auto observerCounter = Counter{};
    SimpleExample::run(observerCounter);
    SimpleExample::runParallel(observerCounter, 10);

//    auto observerCounter = Counter{};
//    CircadianRythmExample::run(observerCounter);

    int N = 10'000;
    std::cout << "---- Covid example with a population " << N << " ----" << std::endl;
    auto observerPeak = AveragePeakHospitalized{};
    std::cout << "running a single simulation." << std::endl;
    CovidExample::run(observerPeak, N);

    auto numberOfSims = 100;
    std::cout << "running " << numberOfSims << " simulations in parallel." << std::endl;
    CovidExample::runParallel(observerPeak, numberOfSims, N);

//    int N_NJ = 589'755;
//    std::cout << "---- Covid example with a population " << N_NJ << " ----" << std::endl;
//    CovidExample::run(observerPeak, N_NJ);
//
//    int N_DK = 5'822'763;
//    std::cout << "---- Covid example with a population " << N_DK << " ----" << std::endl;
//    CovidExample::run(observerPeak, N_DK);
    return 0;
}

