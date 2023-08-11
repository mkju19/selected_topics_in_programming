#include <chrono>
#include <iostream>
#include <iostream>
#include "Observers.h"
#include "benchmark/benchmark.h"
#include "Examples/SimpleExample.h"
#include "Examples/CircadianRhythmExample.h"
#include "Examples/CovidExample.h"

using clk = std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::milli;


static void BM_Simulation(benchmark::State& state){
    auto observer = SilentCounterObserver{};

    for (auto _ : state){
        for (auto i = 0; i < 100; i++) {
            CovidExample::run(observer, state.range());
        }
    }
}

static void BM_ParallelSimulation(benchmark::State& state){
    auto observer = SilentCounterObserver{};
    for (auto _ : state){
            CovidExample::runParallel(observer, 100, state.range());
    }
}
BENCHMARK(BM_Simulation)->Arg(10000);
BENCHMARK(BM_ParallelSimulation)->Arg(10000);

BENCHMARK_MAIN();
