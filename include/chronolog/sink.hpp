#pragma once

#include "chronolog/log_message.hpp"

namespace chronolog {

class LogSink {
public:
  virtual ~LogSink() = default;
  virtual void write(const LogMessage &raw, const std::string &formatted) = 0;
};

} // namespace chronolog
