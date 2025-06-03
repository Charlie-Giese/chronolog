#pragma once

#include <chronolog/formatter/default_formatter.hpp>
#include <chronolog/log_level.hpp>
#include <chronolog/sink.hpp>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

namespace chronolog {

class Logger {
public:
  Logger();

  void set_level(LogLevel level);
  void add_sink(std::shared_ptr<LogSink> sink);
  void set_formatter(std::shared_ptr<Formatter> formatter);

  void set_include_thread_id(bool enable);

  void log(LogLevel level, const std::string &message);

private:
  LogLevel min_level_;
  std::vector<std::shared_ptr<LogSink>> sinks_;
  std::shared_ptr<Formatter> formatter_;
  std::mutex mutex_; // thread safety
  bool include_thread_id_ = false;
};

} // namespace chronolog
