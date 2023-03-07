cmake_minimum_required(VERSION 3.19)

project(app LANGUAGES CXX)
set(PROJECT_VERSION 1.0.0.0)
set(PROJECT_DESCRIPTION "Project description.")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug/lib/static)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug/lib/shared)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/build/Release/lib/static)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/build/Release/lib/shared)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/build/Release/bin)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
include(CompilerOptions)
include(CompilerFlags)
include(ParseConfigs)

find_package(Boost 1.81.0 EXACT REQUIRED COMPONENTS program_options)

find_package(CURL 7.88.1 EXACT)

find_package(RapidJSON)

find_package(ZeroMQ)

if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif()

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/information.hpp.in 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/information.hpp)

add_executable(${PROJECT_NAME} 
                ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
                        ${Boost_LIBRARIES}
                        spdlog::spdlog
                        CURL::libcurl
                        ${ZeroMQ_LIBRARY})
