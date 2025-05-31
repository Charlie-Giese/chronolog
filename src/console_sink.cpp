#include <chronolog/console_sink.hpp>
#include <iostream>

namespace chronolog {

ConsoleSink::ConsoleSink(bool use_stderr_for_errors)
    : use_stderr_(use_stderr_for_errors) {}

void ConsoleSink::write(const std::string &message) {
  // Very simple version: just use cout or cerr depending on flag
  if (use_stderr_) {
    if (message.find("[ERROR]") != std::string::npos ||
        message.find("[FATAL]") != std::string::npos) {
      std::cerr << message << std::endl;
      return;
    }
  }

  std::cout << message << std::endl;
}

} // namespace chronolog
