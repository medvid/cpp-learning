add_executable(test_rational test_rational.cpp)
target_link_libraries(test_rational PRIVATE rational gtest_main)
add_test(test_rational test_rational)
