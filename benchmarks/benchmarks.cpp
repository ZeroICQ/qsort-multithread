#include <cstdlib>
#include <algorithm>
#include "inc/benchmark.h"
#include "qsort.h"

std::shared_ptr<std::vector<int>> default_vector;


static void BM_sort_nt(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *default_vector;
        state.ResumeTiming();
        atl::qsort_nt(test_vector.begin(), test_vector.end());
    }
}

static void BM_sort_t(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *default_vector;
        state.ResumeTiming();
        atl::qsort_t(test_vector.begin(), test_vector.end());
    }
}

static void BM_std_sort(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *default_vector;
        state.ResumeTiming();
        std::sort(test_vector.begin(), test_vector.end());
    }
}

// Register the functions as a benchmark
BENCHMARK(BM_std_sort);
BENCHMARK(BM_sort_nt);
BENCHMARK(BM_sort_t);

//BENCHMARK_MAIN();
int main(int argc, char** argv)
{
    default_vector = atl::get_default_vector();
    ::benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
    ::benchmark::RunSpecifiedBenchmarks();
}
