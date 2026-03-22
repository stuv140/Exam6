cmake_minimum_required(VERSION 3.10)

project(matrix VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Опция для включения Boost.Test
option(WITH_BOOST_TEST "Build with Boost.Test" ON)

# Добавляем поддиректории
add_subdirectory(src)

# Включаем тестирование
enable_testing()
add_subdirectory(tests)

# Настройка CPack
include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "matrix")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "otus")

# Указываем, что устанавливать
install(TARGETS Matrix 
    RUNTIME DESTINATION bin
)

include(CPack)
