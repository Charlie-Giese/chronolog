#include <chronolog/chronolog.hpp>
#include <chronolog/log_level.hpp>

int main() {
  using namespace chronolog;

  Chronolog::set_log_level(LogLevel::DEBUG);

  auto console_sink = std::make_shared<ConsoleSink>();
  Chronolog::add_sink(console_sink);

  Chronolog::debug("This is a debug message");
  Chronolog::info("System initialized");
  Chronolog::warn("Low disk space");
  Chronolog::error("Failed to open file");
  Chronolog::fatal("Unrecoverable error");

  return 0;
}
