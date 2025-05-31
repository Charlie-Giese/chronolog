#include <algorithm>
#include <chronolog/log_level.hpp>

namespace chronolog {

std::string to_string(LogLevel level) {

  switch (level) {
  case LogLevel::DEBUG:
    return "DEBUG";
  case LogLevel::INFO:
    return "INFO";
  case LogLevel::WARN:
    return "WARN";
  case LogLevel::ERROR:
    return "ERROR";
  case LogLevel::FATAL:
    return "FATAL";
  default:
    return "UNKNOWN";
  }
}

std::optional<LogLevel> from_string(const std::string &str) {
  std::string s = str;
  std::transform(s.begin(), s.end(), s.end(), ::toupper);

  if (s == "DEBUG")
    return LogLevel::DEBUG;
  if (s == "INFO")
    return LogLevel::INFO;
  if (s == "WARN")
    return LogLevel::WARN;
  if (s == "ERROR")
    return LogLevel::ERROR;
  if (s == "FATAl")
    return LogLevel::FATAL;

  return std::nullopt;
}

std::string to_tag(LogLevel level) { return "[" + to_string(level) + "]"; }

} // namespace chronolog
