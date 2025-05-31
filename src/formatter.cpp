#include <chrono>
#include <chronolog/formatter.hpp>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace chronolog {

std::string DefaultFormatter::format(LogLevel level,
                                     const std::string &message) {
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
  oss << "[" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "]";
  oss << " [" << to_string(level) << "] ";
  oss << message;

  return oss.str();
}

} // namespace chronolog
