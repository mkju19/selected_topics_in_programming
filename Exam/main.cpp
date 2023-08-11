#include <iostream>
#include "Examples/SimpleExample.h"
#include "Examples/CircadianRhythmExample.h"
#include "Examples/CovidExample.h"
#include "Observers.h"

//#include <graphviz/gvc.h>
//#include "graphviz/cgraph.h"


int main() {

    std::cout << "Writing simple example to CSV" << std::endl;
    auto csvObserver = CsvObserver{"simple"};
    SimpleExample::run(csvObserver);

    std::cout << "Writing simple parallel example to CSV" << std::endl;
    csvObserver.setFileName("simpleParallel");
    SimpleExample::runParallel(csvObserver, 10);

    std::cout << "Writing circadian rhythm example to CSV" << std::endl;
    csvObserver.setFileName("CircadianRhythm");
    CircadianRhythmExample::run(csvObserver);

    std::cout << "Writing circadian rhythm parallel example to CSV" << std::endl;
    csvObserver.setFileName("CircadianRhythmParallel");
    CircadianRhythmExample::runParallel(csvObserver, 10);

    auto numberOfSims = 100;
    auto observerPeak = AveragePeakHospitalized{};

    int N = 10'000;
    std::cout << "---- Covid example with a population " << N << " ----" << std::endl;
    std::cout << "running a single simulation." << std::endl;
    CovidExample::run(observerPeak, N);
    std::cout << "running " << numberOfSims << " simulations in parallel." << std::endl;
    CovidExample::runParallel(observerPeak, numberOfSims, N);

    int N_NJ = 589'755;
    std::cout << "---- Covid example with a population " << N_NJ << " ----" << std::endl;
    std::cout << "running a single simulation." << std::endl;
    CovidExample::run(observerPeak, N_NJ);
    //This will take a long time
//    std::cout << "running " << numberOfSims << " simulations in parallel." << std::endl;
//    CovidExample::runParallel(observerPeak, numberOfSims, N_NJ);

    int N_DK = 5'822'763;
    std::cout << "---- Covid example with a population " << N_DK << " ----" << std::endl;
    std::cout << "running a single simulation." << std::endl;
    CovidExample::run(observerPeak, N_DK);
    //This will take a very long time
//    std::cout << "running " << numberOfSims << " simulations in parallel." << std::endl;
//    CovidExample::runParallel(observerPeak, numberOfSims,N_DK);

    std::cout << "Writing covid example to CSV" << std::endl;
    csvObserver.setFileName("Covid");
    CovidExample::run(csvObserver, N_DK);

    return 0;
}

