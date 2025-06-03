#pragma once

#include <chronolog/log_level.hpp>
#include <chronolog/sink.hpp>
#include <fstream>
#include <mutex>

namespace chronolog {

class FileSink : public LogSink {
public:
  explicit FileSink(const std::string &filename, bool truncate = false);
  ~FileSink();

  void write(const LogMessage &raw, const std::string &formatted) override;

private:
  std::ofstream out_;
  std::mutex mutex_;
};
} // namespace chronolog
