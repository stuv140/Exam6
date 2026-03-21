add_executable(Matrix  Matrix.cpp)

target_include_directories(Matrix PRIVATE ${PROJECT_SOURCE_DIR}/include)

install(TARGETS Matrix RUNTIME DESTINATION bin)
