#pragma once

#include <optional>
#include <string>

namespace chronolog {

enum class LogLevel { DEBUG, INFO, WARN, ERROR, FATAL };

std::string to_string(LogLevel level);
std::optional<LogLevel> from_string(const std::string &str);

} // namespace chronolog
