#include <chronolog/formatter/json_formatter.hpp>
#include <iomanip>
#include <sstream>

namespace chronolog {

JsonFormatter::JsonFormatter(JsonFormatterOptions opts) : options(opts) {}

std::string escape_json(const std::string &input) {
  std::ostringstream oss;
  for (char c : input) {
    switch (c) {
    case '"':
      oss << "\\\"";
      break;
    case '\\':
      oss << "\\\\";
      break;
    case '\n':
      oss << "\\n";
      break;
    case '\t':
      oss << "\\t";
      break;
    default:
      oss << c;
    }
  }
  return oss.str();
}

std::string JsonFormatter::format(const LogMessage &log_msg) {
  std::ostringstream oss;

  auto quote = [](const auto &value) -> std::string {
    std::ostringstream oss;
    if constexpr (std::is_convertible_v<decltype(value), std::string>) {
      oss << '"' << value << '"';
    } else if constexpr (std::is_convertible_v<decltype(value), const char *>) {
      oss << '"' << value << '"';
    } else {
      oss << value;
    }
    return oss.str();
  };

  auto indent = [this](int level) -> std::string {
    return options.pretty ? std::string(level * 2, ' ') : "";
  };

  auto newline = [this]() -> std::string { return options.pretty ? "\n" : ""; };

  auto time = std::chrono::system_clock::to_time_t(log_msg.timestamp);
  std::tm tm = *std::localtime(&time);

  if (options.nested) {
    oss << "{" << newline();
    oss << indent(1) << quote("timestamp") << ": " << quote(time) << ","
        << newline();
    oss << indent(1) << quote("level") << ": "
        << quote(to_string(log_msg.level)) << "," << newline();
    oss << indent(1) << quote("thread") << ": " << quote(log_msg.thread_id)
        << "," << newline();
    oss << indent(1) << quote("message") << ": {" << newline();
    oss << indent(2) << quote("text") << ": " << quote(log_msg.text) << ","
        << newline();
    oss << indent(1) << "}" << newline();
    oss << "}";
  } else {
    oss << "{" << newline();
    oss << indent(1) << quote("timestamp") << ": " << quote(time) << ","
        << newline();
    oss << indent(1) << quote("level") << ": "
        << quote(to_string(log_msg.level)) << "," << newline();
    oss << indent(1) << quote("thread") << ": " << quote(log_msg.thread_id)
        << "," << newline();
    oss << indent(1) << quote("message") << ": " << quote(log_msg.text)
        << newline();
    oss << "}";
  }

  return oss.str();
}

} // namespace chronolog
