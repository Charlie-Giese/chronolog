#pragma once

#include <chrono>
#include <string>
#include <thread>

#include <chronolog/log_level.hpp>

namespace chronolog {

struct LogMessage {
  LogLevel level;
  std::string text;
  std::chrono::system_clock::time_point timestamp;
  std::thread::id thread_id;
  bool has_thread_id = false;
  // can add more metadata later (file, line, logger name, etc.)
};

} // namespace chronolog
