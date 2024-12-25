cmake_minimum_required(VERSION 3.10)
project(ArrayTestProject LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/include/array_template.h)

set(TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/tests/test_array.cpp
)

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/tests/test_array.cpp)
    message(FATAL_ERROR "Test file tests/test_array.cpp not found!")
endif()

find_package(GTest REQUIRED)

if (NOT GTest_FOUND)
    message(FATAL_ERROR "GoogleTest not found!")
endif()

set(MAIN_SOURCE ${CMAKE_SOURCE_DIR}/main.cpp)

if(NOT EXISTS ${MAIN_SOURCE})
    message(FATAL_ERROR "Main file main.cpp not found!")
endif()

add_executable(run_tests
    ${MAIN_SOURCE}
    ${TEST_SOURCES}
    ${SOURCES}
)

target_link_libraries(run_tests GTest::GTest pthread)

install(TARGETS run_tests
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
