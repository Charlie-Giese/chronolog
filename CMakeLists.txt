cmake_minimum_required(VERSION 3.12)
project(chronolog LANGUAGES CXX)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Library target
add_library(chronolog
    src/log_level.cpp
    src/console_sink.cpp
    src/logger.cpp
    src/chronolog.cpp
    src/file_sink.cpp
    src/formatter/json_formatter.cpp
    src/formatter/default_formatter.cpp
)

target_include_directories(chronolog PUBLIC $(PROJECT_SOURCE_DIR)/include)

add_executable(chronolog_demo test/main.cpp)
target_link_libraries(chronolog_demo chronolog)

