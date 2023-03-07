if(NOT EXISTS ${CMAKE_SOURCE_DIR}/config.json)
    message(FATAL_ERROR "config.json not found!")
endif()

file(READ ${CMAKE_SOURCE_DIR}/config.json APP_CONFIG_FILE)

string(JSON CONFIGS_LENGTH LENGTH ${APP_CONFIG_FILE})

math(EXPR CONFIGS_LENGTH "${CONFIGS_LENGTH} - 1" OUTPUT_FORMAT DECIMAL)

foreach(IDX RANGE ${CONFIGS_LENGTH})
    string(JSON CONFIG MEMBER ${APP_CONFIG_FILE} ${IDX})
    string(JSON VALUE GET ${APP_CONFIG_FILE} ${CONFIG})
    set(${CONFIG} ${VALUE})
endforeach()

configure_file(
    ${CMAKE_SOURCE_DIR}/cmake/config.hpp.in
    ${CMAKE_SOURCE_DIR}/include/config.hpp
)