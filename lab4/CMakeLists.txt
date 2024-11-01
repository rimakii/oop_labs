cmake_minimum_required(VERSION 3.10)
project(lab4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ?????????? ???? ? ????????????, ???? ??????????
# set(CMAKE_C_COMPILER "/path/to/gcc")
# set(CMAKE_CXX_COMPILER "/path/to/g++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
  TLS_VERIFY false
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(include)
add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp)

enable_testing()

add_executable(tests test/Tests.cpp)
target_link_libraries(tests gtest_main)

add_test(NAME MyProjectTests COMMAND tests)