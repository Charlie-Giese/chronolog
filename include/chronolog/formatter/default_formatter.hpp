#pragma once

#include <chronolog/formatter.hpp>
#include <string>

namespace chronolog {

class DefaultFormatter : public Formatter {
public:
  std::string format(const LogMessage &log_msg) override;
};

} // namespace chronolog
