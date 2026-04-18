project(ut)

add_executable(${PROJECT_NAME} test.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)

enable_testing()
add_test(NAME AllTests COMMAND ${PROJECT_NAME})