project(librational)

add_library(rational
    src/rational.h
    src/rational.cpp
    src/gcd.h
    src/gcd.cpp
)
target_include_directories(rational PUBLIC src)

add_executable(rationalapp
    src/main.cpp
)
target_link_libraries(rationalapp PRIVATE rational)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()
