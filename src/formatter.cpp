#include <chrono>
#include <chronolog/formatter.hpp>
#include <ctime>
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

std::string DefaultFormatter::format(LogMessage message) {
  // Get timestamp
  auto now = std::chrono::system_clock::now();
  std::time_t tt = std::chrono::system_clock::to_time_t(now);
  std::tm tm;
#if defined(_WIN32)
  localtime_s(&tm, &tt);
#else
  localtime_r(&tt, &tm);
#endif

  std::ostringstream oss;

  const char *color = color_for_level(message.level);

  oss << "[" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "]" << color << " ["
      << to_string(message.level) << "] " << reset_color << message.text;

  return oss.str();
}

} // namespace chronolog
