#pragma once

#include <string>

namespace chronolog {

class LogSink {
public:
  virtual ~LogSink() = default;
  virtual void write(const std::string &message) = 0;
};

} // namespace chronolog
