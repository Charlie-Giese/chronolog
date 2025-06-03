#pragma once

#include <chronolog/formatter.hpp>
#include <string>

namespace chronolog {

struct JsonFormatterOptions {
  bool nested = false;
  bool pretty = false;
};

class JsonFormatter : public Formatter {
public:
  explicit JsonFormatter(JsonFormatterOptions opts = {});
  std::string format(const LogMessage &log_msg) override;

private:
  JsonFormatterOptions options;
};

} // namespace chronolog
