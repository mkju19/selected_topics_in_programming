#include <iostream>
#include "Include/Simulator/StateObserver.h"
#include "Examples/SimpleExample.h"
#include "Examples/CircadianRythmExample.h"
#include "Examples/CovidExample.h"
#include "Observers.h"
#include <fstream>

//#include <graphviz/gvc.h>
//#include "graphviz/cgraph.h"

int main() {

    auto csvObserver = CsvObserver{"simple"};
    SimpleExample::run(csvObserver);
    csvObserver.setFileName("simpleParallel");
    SimpleExample::runParallel(csvObserver, 10);

    csvObserver.setFileName("CircadianRythm");
    CircadianRythmExample::run(csvObserver);

    int N = 10'000;
    std::cout << "---- Covid example with a population " << N << " ----" << std::endl;
    auto observerPeak = AveragePeakHospitalized{};
    std::cout << "running a single simulation." << std::endl;
    CovidExample::run(observerPeak, N);

    auto numberOfSims = 100;
    std::cout << "running " << numberOfSims << " simulations in parallel." << std::endl;
    CovidExample::runParallel(observerPeak, numberOfSims, N);

    int N_NJ = 589'755;
    std::cout << "---- Covid example with a population " << N_NJ << " ----" << std::endl;
    CovidExample::run(observerPeak, N_NJ);

    int N_DK = 5'822'763;
    std::cout << "---- Covid example with a population " << N_DK << " ----" << std::endl;
    CovidExample::run(observerPeak, N_DK);
    return 0;
}

