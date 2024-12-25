cmake_minimum_required(VERSION 3.10)
project(ProjectTexTabl LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/data_line.cpp
    ${CMAKE_SOURCE_DIR}/src/column.cpp
    ${CMAKE_SOURCE_DIR}/src/dataset.cpp
)

set(HEADERS
    ${CMAKE_SOURCE_DIR}/include/data_line.h
    ${CMAKE_SOURCE_DIR}/include/enums.h
    ${CMAKE_SOURCE_DIR}/include/column.h
    ${CMAKE_SOURCE_DIR}/include/dataset.h
    ${CMAKE_SOURCE_DIR}/include/utility.h
)

set(TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/tests/test_dataset.cpp
)

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/tests/test_dataset.cpp)
    message(FATAL_ERROR "Test file tests/test_dataset.cpp not found!")
endif()

find_package(GTest REQUIRED)

if (NOT GTest_FOUND)
    message(FATAL_ERROR "GoogleTest not found!")
endif()

add_executable(ProjectTexTabl
    ${SOURCES}
    ${HEADERS}
    ${TEST_SOURCES}
)

target_link_libraries(ProjectTexTabl GTest::GTest pthread)

install(TARGETS ProjectTexTabl
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set(TEST_FILES
    ${CMAKE_SOURCE_DIR}/tests/test_data.txt
    ${CMAKE_SOURCE_DIR}/tests/test_data.csv
)

target_sources(ProjectTexTabl PRIVATE ${TEST_FILES})
