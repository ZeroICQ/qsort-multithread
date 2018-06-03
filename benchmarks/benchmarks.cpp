#include <cstdlib>
#include <algorithm>
#include "inc/benchmark.h"
#include "qsort.h"

std::shared_ptr<std::vector<int>> small_default_vector;
std::shared_ptr<std::vector<int>> medium_default_vector;
std::shared_ptr<std::vector<int>> large_default_vector;
std::shared_ptr<std::vector<int>> super_large_default_vector;


static void BM_sort_nothreads_small(benchmark::State &state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *small_default_vector;
        state.ResumeTiming();
        atl::qsort_nt(test_vector.begin(), test_vector.end());
    }
}

static void BM_sort_nothreads_medium(benchmark::State &state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *medium_default_vector;
        state.ResumeTiming();
        atl::qsort_nt(test_vector.begin(), test_vector.end());
    }
}

static void BM_sort_nothreads_large(benchmark::State &state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *large_default_vector;
        state.ResumeTiming();
        atl::qsort_nt(test_vector.begin(), test_vector.end());
    }
}

static void BM_sort_nothreads_super_large(benchmark::State &state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *super_large_default_vector;
        state.ResumeTiming();
        atl::qsort_nt(test_vector.begin(), test_vector.end());
    }
}

static void BM_sort_threads_small(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *small_default_vector;
        state.ResumeTiming();
        atl::qsort_t(test_vector.begin(), test_vector.end(), state.range(0));
    }
}

static void BM_sort_threads_medium(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *medium_default_vector;
        state.ResumeTiming();
        atl::qsort_t(test_vector.begin(), test_vector.end(), state.range(0));
    }
}

static void BM_sort_threads_large(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *large_default_vector;
        state.ResumeTiming();
        atl::qsort_t(test_vector.begin(), test_vector.end(), state.range(0));
    }
}

static void BM_sort_threads_super_large(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *super_large_default_vector;
        state.ResumeTiming();
        atl::qsort_t(test_vector.begin(), test_vector.end(), state.range(0));
    }
}

static void BM_sort_std_small(benchmark::State &state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *small_default_vector;
        state.ResumeTiming();
        std::sort(test_vector.begin(), test_vector.end());
    }
}

static void BM_sort_std_medium(benchmark::State &state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *medium_default_vector;
        state.ResumeTiming();
        std::sort(test_vector.begin(), test_vector.end());
    }
}

static void BM_sort_std_large(benchmark::State &state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *medium_default_vector;
        state.ResumeTiming();
        std::sort(test_vector.begin(), test_vector.end());
    }
}

static void BM_sort_std_super_large(benchmark::State &state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto test_vector = *super_large_default_vector;
        state.ResumeTiming();
        std::sort(test_vector.begin(), test_vector.end());
    }
}

// Register the functions as a benchmark
BENCHMARK(BM_sort_std_small);
BENCHMARK(BM_sort_nothreads_small);
BENCHMARK(BM_sort_threads_small)->RangeMultiplier(2)->Range(2, 16);

BENCHMARK(BM_sort_std_medium);
BENCHMARK(BM_sort_nothreads_medium);
BENCHMARK(BM_sort_threads_medium)->RangeMultiplier(2)->Range(2, 16);

BENCHMARK(BM_sort_std_large);
BENCHMARK(BM_sort_nothreads_large);
BENCHMARK(BM_sort_threads_large)->RangeMultiplier(2)->Range(2, 16);

BENCHMARK(BM_sort_std_super_large);
BENCHMARK(BM_sort_nothreads_super_large);
BENCHMARK(BM_sort_threads_super_large)->RangeMultiplier(2)->Range(2, 16);

//BENCHMARK_MAIN();
int main(int argc, char** argv)
{
    large_default_vector = atl::get_default_vector(atl::SIZE_LARGE);
    medium_default_vector = atl::get_default_vector(atl::SIZE_MEDIUM);
    small_default_vector = atl::get_default_vector(atl::SIZE_SMALL);
    super_large_default_vector = atl::get_default_vector(atl::SIZE_SUPER_LARGE);

    ::benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
    ::benchmark::RunSpecifiedBenchmarks();
}
