set(Boost_NO_BOOST_CMAKE ON)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(test_Matrix test.cpp)

target_include_directories(test_Matrix PRIVATE ${PROJECT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})

target_link_libraries(test_Matrix PRIVATE ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(NAME test_Matrix COMMAND test_Matrix)
