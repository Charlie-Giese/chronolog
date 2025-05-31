# chronolog

**chronolog** is a lightweight, modular logging and tracing library for modern C++.  
It offers configurable log levels, flexible formatting, and pluggable log sinks.

---

## Features

- 📋 Multiple log levels: `DEBUG`, `INFO`, `WARN`, `ERROR`, `FATAL`
- 🧱 Pluggable sink architecture (e.g., console, file, custom)
- 🎨 Customizable message formatting
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
