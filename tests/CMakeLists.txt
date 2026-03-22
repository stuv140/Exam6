
# src/CMakeLists.txt

# Создаем исполняемый файл
add_executable(Matrix Matrix.cpp)

# Добавляем директории для include
target_include_directories(Matrix PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)

# Устанавливаем в bin
install(TARGETS Matrix 
    RUNTIME DESTINATION bin
)
