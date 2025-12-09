cmake_minimum_required(VERSION 3.10)
project(SmartCalculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(calculator STATIC src/calculator.cpp)
target_include_directories(calculator PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(smart_calculator smart_calculator.cpp)
target_link_libraries(smart_calculator PRIVATE calculator)

if (MSVC)
    target_compile_options(smart_calculator PRIVATE /W4 /permissive-)
    target_compile_options(calculator PRIVATE /W4 /permissive-)
else()
    target_compile_options(smart_calculator PRIVATE -Wall -Wextra -Wpedantic -Werror)
    target_compile_options(calculator PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

# Testing
include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(catch2)

enable_testing()
add_executable(tests tests/test_calculator.cpp)
target_link_libraries(tests PRIVATE calculator Catch2::Catch2WithMain)
add_test(NAME calculator_tests COMMAND tests)
