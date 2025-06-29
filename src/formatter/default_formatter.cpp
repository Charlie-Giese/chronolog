#include <chronolog/formatter/default_formatter.hpp>
#include <iomanip>
#include <sstream>

namespace chronolog {

const char *color_for_level(LogLevel level) {
  switch (level) {
  case LogLevel::DEBUG:
    return "\033[34m"; // Blue
  case LogLevel::INFO:
    return "\033[32m"; // Green
  case LogLevel::WARN:
    return "\033[33m"; // Yellow
  case LogLevel::ERROR:
    return "\033[31m"; // Red
  case LogLevel::FATAL:
    return "\033[35m"; // Magenta
  default:
    return "\033[0m"; // Reset
  }
}

constexpr const char *reset_color = "\033[0m";

std::string DefaultFormatter::format(const LogMessage &log_msg) {

  std::ostringstream oss;

  auto time = std::chrono::system_clock::to_time_t(log_msg.timestamp);
  std::tm tm = *std::localtime(&time);

  const char *color = color_for_level(log_msg.level);

  oss << "[" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "]" << color << " ["
      << to_string(log_msg.level) << "]" << reset_color;

  if (log_msg.has_thread_id) {
    oss << "[Thread " << log_msg.thread_id << "] ";
  }
  oss << log_msg.text;

  return oss.str();
}

} // namespace chronolog
