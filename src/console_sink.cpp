#include <chronolog/console_sink.hpp>
#include <iostream>

namespace chronolog {

ConsoleSink::ConsoleSink(bool use_stderr_for_errors)
    : use_stderr_(use_stderr_for_errors) {}

void ConsoleSink::write(const LogMessage &raw, const std::string &formatted) {
  // Very simple version: just use cout or cerr depending on flag

  if (use_stderr_) {
    if (formatted.find("[ERROR]") != std::string::npos ||
        formatted.find("[FATAL]") != std::string::npos) {
      std::cerr << formatted << std::endl;
      return;
    }
  }

  std::cout << formatted << std::endl;
}

} // namespace chronolog
