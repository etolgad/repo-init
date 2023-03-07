cmake_minimum_required()(VERSION 3.19)

project()(app LANGUAGES CXX)
set(PROJECT_VERSION 1.0.0.0)
set(PROJECT_DESCRIPTION "Project description.")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug/lib/static)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug/lib/shared)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/build/Release/lib/static)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/build/Release/lib/shared)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/build/Release/bin)

set(CMAKE_GENERATOR "Unix Makefiles")
set(CMAKE_DEBUG_POSTFIX d)
set(BUILD_SHARED_LIBS ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
include(Colorize)
include(CompilerOptions)
include(CompilerFlags)
include(ParseConfigs)

FIND_PACKAGE(Boost 1.81.0 EXACT REQUIRED COMPONENTS program_options)
if(NOT ${Boost_FOUND})
    message(FATAL_ERROR "${BoldRed}Boost Not Found!${ColourReset}")
endif()

FIND_PACKAGE(CURL 7.88.1 EXACT REQUIRED)
if(NOT ${CURL_FOUND})
    message(FATAL_ERROR "${BoldRed}Libcurl Not Found!${ColourReset}")
endif()

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/information.hpp.in 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/information.hpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)

add_executable(${PROJECT_NAME} 
                ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${Boost_include_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
                        ${Boost_LIBRARIES})
