#include <cstdlib>
#include <algorithm>
#include "inc/benchmark.h"
#include "qsort.h"

std::vector<int> default_vector;


static void BM_sort_nt(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> test_vector = default_vector;
        state.ResumeTiming();
        atl::qsort_nt(test_vector.begin(), test_vector.end());
    }
}


static void BM_std_sort(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = default_vector;
        state.ResumeTiming();
        std::sort(test_vector.begin(), test_vector.end());
    }
}

// Register the function as a benchmark
BENCHMARK(BM_sort_nt);
BENCHMARK(BM_std_sort);


//BENCHMARK_MAIN();
int main(int argc, char** argv)
{
    for (int i = 0; i < atl::SIZE; i++) {
        default_vector.push_back(std::rand() - RAND_MAX / 2);
    }

    ::benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
    ::benchmark::RunSpecifiedBenchmarks();

    std::srand(atl::SEED);
}
