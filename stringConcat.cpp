#include <benchmark/benchmark.h>
#include <sstream>
#include <absl/strings/str_cat.h>
#include <fmt/core.h>

static void stringConcatPlus(benchmark::State& state) {
  std::string str1 = "test1";
  std::string str2 = "test2";
  std::string str3 = "test3";
  for (auto _ : state) {
    std::string str("Unable to find: unit['" + str1 + "'].geoids['" + str2 + "'].projs['" + str3 + "']");
    benchmark::DoNotOptimize(str);
  }
}
BENCHMARK(stringConcatPlus);

static void stringConcatOss(benchmark::State& state) {
  std::string str1 = "test1";
  std::string str2 = "test2";
  std::string str3 = "test3";
  for (auto _ : state) {
    std::ostringstream oss;
    oss << "Unable to find: unit['" << str1 << "'].geoids['" << str2 << "'].projs['" << str3 + "']";
    std::string str(oss.str());
    benchmark::DoNotOptimize(str);
  }
}
BENCHMARK(stringConcatOss);

static void stringConcatAbs(benchmark::State& state) {
  std::string str1 = "test1";
  std::string str2 = "test2";
  std::string str3 = "test3";
  for (auto _ : state) {
    std::string str =  absl::StrCat("Unable to find: unit['", str1, "'].geoids['", str2, "'].projs['", str3, "']");
    benchmark::DoNotOptimize(str);
  }
}
BENCHMARK(stringConcatAbs);

static void stringConcatFmt(benchmark::State& state) {
  std::string str1 = "test1";
  std::string str2 = "test2";
  std::string str3 = "test3";
  for (auto _ : state) {
    std::string str = fmt::format("Unable to find: unit['{}'].geoids['{}'].projs['{}']", str1, str2, str3);
    benchmark::DoNotOptimize(str);
  }
}
BENCHMARK(stringConcatFmt);

BENCHMARK_MAIN();
