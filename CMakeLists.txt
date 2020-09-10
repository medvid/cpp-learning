cmake_minimum_required(VERSION 3.5)

project(cpp-learning LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_TESTS TRUE CACHE BOOL "Build unit tests")

if(BUILD_TESTS)
    set(gtest_force_shared_crt ON)
    add_subdirectory(vendor/googletest)
    enable_testing()
endif()

add_subdirectory(librational)
