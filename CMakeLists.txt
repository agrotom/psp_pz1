cmake_minimum_required(VERSION 3.28.3)

project(PSPGenerator)

add_executable(PSPGenerator)

file(GLOB SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

target_sources(PSPGenerator
    PRIVATE
        ${SOURCES}
)

target_include_directories(PSPGenerator PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)