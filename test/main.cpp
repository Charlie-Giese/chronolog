#include <chronolog/chronolog.hpp>
#include <chronolog/log_level.hpp>

int main() {
  using namespace chronolog;

  Chronolog::set_log_level(LogLevel::DEBUG);

  auto file_sink = std::make_shared<chronolog::FileSink>("log.txt");
  Chronolog::add_sink(file_sink);

  Chronolog::debug("File log");

  return 0;
}
