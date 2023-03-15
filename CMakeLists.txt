cmake_minimum_required(VERSION 3.14) 
project(utf8pp)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(range-v3
  GIT_REPOSITORY https://github.com/ericniebler/range-v3.git
  GIT_TAG master
)
FetchContent_MakeAvailable(range-v3)

add_executable(utf8pp test_main.cpp)
target_link_libraries(utf8pp fmt::fmt range-v3)
