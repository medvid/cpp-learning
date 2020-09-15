project(my_vector)
add_executable(test_my_vector my_vector.h test_my_vector.cpp)
target_link_libraries(test_my_vector PRIVATE gmock_main)
add_test(test_my_vector test_my_vector)
