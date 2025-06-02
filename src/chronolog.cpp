#include <chronolog/chronolog.hpp>

namespace chronolog {

Logger &Chronolog::logger() {
  static Logger instance;
  return instance;
}

void Chronolog::set_log_level(LogLevel level) { logger().set_level(level); }

void Chronolog::add_sink(std::shared_ptr<LogSink> sink) {
  logger().add_sink(std::move(sink));
}

void Chronolog::enable_thread_ids(bool enable) {
  logger().set_include_thread_id(enable);
}

void Chronolog::debug(const std::string &msg) {
  logger().log(LogLevel::DEBUG, msg);
}
void Chronolog::info(const std::string &msg) {
  logger().log(LogLevel::INFO, msg);
}
void Chronolog::warn(const std::string &msg) {
  logger().log(LogLevel::WARN, msg);
}
void Chronolog::error(const std::string &msg) {
  logger().log(LogLevel::ERROR, msg);
}
void Chronolog::fatal(const std::string &msg) {
  logger().log(LogLevel::FATAL, msg);
}

} // namespace chronolog
