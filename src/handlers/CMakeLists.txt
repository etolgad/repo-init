ADD_LIBRARY(handlers_logger SHARED ${CMAKE_CURRENT_SOURCE_DIR}/logger.cpp)

TARGET_INCLUDE_DIRECTORIES(handlers_logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)

TARGET_LINK_LIBRARIES(handlers_logger spdlog)