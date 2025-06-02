#include "chronolog/console_sink.hpp"
#include <chronolog/chronolog.hpp>
#include <chronolog/log_level.hpp>

int main() {
  using namespace chronolog;

  Chronolog::set_log_level(LogLevel::DEBUG);
  Chronolog::enable_thread_ids(true);
  // auto file_sink = std::make_shared<chronolog::FileSink>("log.txt");
  // Chronolog::add_sink(file_sink);
  auto console_sink = std::make_shared<chronolog::ConsoleSink>();
  Chronolog::add_sink(console_sink);

  Chronolog::debug("debug");
  Chronolog::info("info");
  Chronolog::warn("warn");
  Chronolog::error("error");
  Chronolog::fatal("fatal");

  return 0;
}
