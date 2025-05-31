#pragma once

#include <chronolog/log_level.hpp>
#include <string>

namespace chronolog {

class Formatter {
public:
  virtual ~Formatter() = default;
  virtual std::string format(LogLevel level, const std::string &message) = 0;
};

class DefaultFormatter : public Formatter {
public:
  std::string format(LogLevel level, const std::string &message) override;
};

} // namespace chronolog
