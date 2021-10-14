#include <benchmark/benchmark.h>
#include <vector>

class ConstructorArgCopy
{
public:
    ConstructorArgCopy(std::vector<int> v) : _v(v) {}
    const std::vector<int> & getV() const {return _v;}

private:
    std::vector<int> _v;
};

static void constructorArgCopy(benchmark::State& state) {
    std::vector<int> v(state.range(0), state.range(0));
    std::size_t sum = 0;
    for (auto _ : state)
    {
        ConstructorArgCopy c(v);
        sum += c.getV().size();
    }
}
BENCHMARK(constructorArgCopy)->DenseRange(128, 512, 128);

class ConstructorArgCopyWithMove
{
public:
    ConstructorArgCopyWithMove(std::vector<int> v) : _v(std::move(v)) {}
    const std::vector<int> & getV() const {return _v;}

private:
    std::vector<int> _v;
};

static void constructorArgCopyWithMove(benchmark::State& state) {
    std::vector<int> v(state.range(0), state.range(0));
    std::size_t sum = 0;
    for (auto _ : state)
    {
        ConstructorArgCopyWithMove c(v);
        sum += c.getV().size();
    }
}
BENCHMARK(constructorArgCopyWithMove)->DenseRange(128, 512, 128);

class ConstructorArgConstRef
{
public:
    ConstructorArgConstRef(const std::vector<int> & v) : _v(v) {}
    const std::vector<int> & getV() const {return _v;}

private:
    std::vector<int> _v;
};

static void constructorArgConstRef(benchmark::State& state) {
    std::vector<int> v(state.range(0), state.range(0));
    std::size_t sum = 0;
    for (auto _ : state)
    {
        ConstructorArgConstRef c(v);
        sum += c.getV().size();
    }
}
BENCHMARK(constructorArgConstRef)->DenseRange(128, 512, 128);

static void constructorArgCopyWithMoveFromTemp(benchmark::State& state) {
    std::size_t sum = 0;
    for (auto _ : state)
    {
        ConstructorArgCopyWithMove c(std::vector<int>(state.range(0), state.range(0)));
        sum += c.getV().size();
    }
}
BENCHMARK(constructorArgCopyWithMoveFromTemp)->DenseRange(128, 512, 128);

static void constructorArgConstRefFromTemp(benchmark::State& state) {
    std::size_t sum = 0;
    for (auto _ : state)
    {
        ConstructorArgConstRef c(std::vector<int>(state.range(0), state.range(0)));
        sum += c.getV().size();
    }
}
BENCHMARK(constructorArgConstRefFromTemp)->DenseRange(128, 512, 128);

BENCHMARK_MAIN();
