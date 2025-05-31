#include <chronolog/file_sink.hpp>
#include <stdexcept>

namespace chronolog {

FileSink::FileSink(const std::string &filename, bool truncate) {
  std::ios_base::openmode mode = std::ios::out;
  if (!truncate) {
    mode |= std::ios::app;
  }
  out_.open(filename, mode);
  if (!out_) {
    throw std::runtime_error("Failed to open log file: " + filename);
  }
}

FileSink::~FileSink() { out_.close(); }

void FileSink::write(const std::string &message) {
  std::lock_guard<std::mutex> lock(mutex_);
  out_ << message << std::endl;
}

} // namespace chronolog

