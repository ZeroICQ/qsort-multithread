#include "inc/benchmark.h"
#include "qsort.h"

static void BM_Sort(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        std::vector<int> test_vector = {9, 8, 7, 6, 5, 4};
        state.ResumeTiming();
        atl::qsort(test_vector.begin(), test_vector.end());
    }
}

// Register the function as a benchmark
BENCHMARK(BM_Sort);


BENCHMARK_MAIN();