cmake_minimum_required(VERSION 3.20)

project(CppDiplomProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пути
set(BOOST_ROOT "C:\\Boost")
set(OPENSSL_ROOT_DIR "C:\\Den\\openssl-3.4.1")
set(libpqxx_DIR "C:\\Den\\NetologyDiplom\\libpqxx-7.9.2")

# Найдём зависимости
find_package(OpenSSL REQUIRED)
find_package(Boost 1.87.0 REQUIRED COMPONENTS system thread locale)

# Подключим libpqxx из исходников
add_subdirectory(${libpqxx_DIR} libpqxx-build)

# Цель
add_executable(crawler 
    crawler/main.cpp 
    crawler/crawler.cpp 
    crawler/crawler.h
)

# Подключим зависимости
target_include_directories(crawler PRIVATE 
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_BINARY_DIR}/libpqxx-build/include
)

target_link_libraries(crawler 
    pqxx
    OpenSSL::SSL
    ${Boost_LIBRARIES}
)


