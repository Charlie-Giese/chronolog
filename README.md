# chronolog

**chronolog** aims to be a lightweight, modular logging and tracing library for modern C++.  
It will offer configurable log levels, flexible formatting, and pluggable log sinks.

---

## Features

- 📋 Multiple log levels: `DEBUG`, `INFO`, `WARN`, `ERROR`, `FATAL`
- 🧱 Pluggable sink architecture (e.g., console, file, custom) (planned)
- 🎨 Customizable message formatting (planned)
- 🧵 Thread-safe logging (planned)
- 🧪 Minimal dependencies, easy to integrate

---

## Getting Started

### Build with CMake

```bash
git clone https://github.com/yourname/chronolog.git
cd chronolog
mkdir build && cd build
cmake ..
make
```

### Basic Usage
```C++
#include <chronolog/chronolog.hpp>
#include <chronolog/sinks/console_sink.hpp>

using namespace chronolog;

int main() {
  auto console_sink = std::make_shared<ConsoleSink>();
  ChronoLog::add_sink(console_sink);
  ChronoLog::set_log_level(LogLevel::DEBUG);

  ChronoLog::info("Hello, ChronoLog!");
  ChronoLog::debug("This is a debug message");
}
```

## License
MIT License © 2025 [Charles Giese]
