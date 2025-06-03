#pragma once

#include "chronolog/log_message.hpp"
#include <chronolog/log_level.hpp>
#include <chronolog/sink.hpp>

namespace chronolog {

class ConsoleSink : public LogSink {
public:
  explicit ConsoleSink(bool use_stderr_for_errors = true);

  void write(const LogMessage &raw, const std::string &formatted) override;

private:
  bool use_stderr_;
};

} // namespace chronolog
