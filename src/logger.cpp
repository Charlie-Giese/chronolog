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

void Logger::log(LogLevel level, const std::string &msg) {
  std::lock_guard<std::mutex> lock(mutex_);
  if (level < min_level_) {
    return;
  }

  LogMessage message{
      level,
      msg,
      std::chrono::system_clock::now(),
      std::this_thread::get_id(),
  };

  const std::string formatted = formatter_->format(message);
  for (const auto &sink : sinks_) {
    sink->log(message, formatted);
  }
}

} // namespace chronolog
