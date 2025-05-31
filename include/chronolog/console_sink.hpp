#pragma once

#include <chronolog/log_level.hpp>
#include <chronolog/sink.hpp>

namespace chronolog {

class ConsoleSink : public LogSink {
public:
  explicit ConsoleSink(bool use_stderr_for_errors = true);

  void write(const std::string &message) override;

private:
  bool use_stderr_;
};

} // namespace chronolog
