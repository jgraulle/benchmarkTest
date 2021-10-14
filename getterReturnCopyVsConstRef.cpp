#include <benchmark/benchmark.h>
#include <vector>

class Test
{
public:
    Test(const std::vector<int> & s) : _s(s) {}
    std::vector<int> getCopy() {return _s;}
    const std::vector<int> & getConstRef() {return _s;}

private:
    std::vector<int> _s;
};

static void getCopy(benchmark::State& state) {
    std::vector<int> v(state.range(0), state.range(0));
    Test t(v);
    std::size_t sum = 0;
    for (auto _ : state)
        sum += t.getCopy().size();
}
BENCHMARK(getCopy)->DenseRange(128, 512, 128);

static void getConstRef(benchmark::State& state) {
    std::vector<int> v(state.range(0), state.range(0));
    Test t(v);
    std::size_t sum = 0;
    for (auto _ : state)
        sum += t.getConstRef().size();
}
BENCHMARK(getConstRef)->DenseRange(128, 512, 128);

BENCHMARK_MAIN();
