#pragma once

#include <chronolog/console_sink.hpp>
#include <chronolog/file_sink.hpp>
#include <chronolog/log_level.hpp>
#include <chronolog/logger.hpp>
#include <memory>
#include <string>

namespace chronolog {

class Chronolog {
public:
  static void set_log_level(LogLevel level);
  static void add_sink(std::shared_ptr<LogSink> sink);

  static void info(const std::string &message);
  static void warn(const std::string &message);
  static void error(const std::string &message);
  static void debug(const std::string &message);
  static void fatal(const std::string &message);

private:
  static class Logger &logger();
};

} // namespace chronolog
