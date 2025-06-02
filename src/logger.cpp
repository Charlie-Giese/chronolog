#include "chronolog/logger.hpp"
#include "chronolog/log_level.hpp"
#include "chronolog/log_message.hpp"

namespace chronolog {

Logger::Logger()
    : min_level_(LogLevel::INFO),
      formatter_(std::make_shared<DefaultFormatter>()) {}

void Logger::set_level(LogLevel level) {
  std::lock_guard<std::mutex> lock(mutex_);
  min_level_ = level;
}

void Logger::add_sink(std::shared_ptr<LogSink> sink) {
  std::lock_guard<std::mutex> lock(mutex_);
  sinks_.push_back(std::move(sink));
}

void Logger::set_formatter(std::shared_ptr<Formatter> formatter) {
  std::lock_guard<std::mutex> lock(mutex_);
  formatter_ = std::move(formatter);
}

void Logger::set_include_thread_id(bool enable) { include_thread_id_ = enable; }

void Logger::log(LogLevel level, const std::string &msg) {
  std::lock_guard<std::mutex> lock(mutex_);
  if (level < min_level_) {
    return;
  }

  LogMessage log_msg{
      level,
      msg,
      std::chrono::system_clock::now(),
  };

  if (include_thread_id_) {
    log_msg.thread_id = std::this_thread::get_id();
    log_msg.has_thread_id = true;
  }

  const std::string formatted = formatter_->format(log_msg);
  for (const auto &sink : sinks_) {
    sink->log(log_msg, formatted);
  }
}

} // namespace chronolog
