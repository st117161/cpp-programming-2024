cmake_minimum_required(VERSION 3.10)
project(Hw4 LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR}/helper_src ${CMAKE_SOURCE_DIR}/bank_src ${CMAKE_SOURCE_DIR}/text_editor_src)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/helper_src/helper.cpp
    ${CMAKE_SOURCE_DIR}/bank_src/bank.cpp
    ${CMAKE_SOURCE_DIR}/bank_src/bankaccount.cpp
    ${CMAKE_SOURCE_DIR}/text_editor_src/texteditor.cpp
)

set(TEST_SOURCES
    tests/bank_and_account_test.cpp
    tests/texteditor_test.cpp
)

set(MAIN_SOURCE ${CMAKE_SOURCE_DIR}/main.cpp)

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/tests/bank_and_account_test.cpp)
    message(FATAL_ERROR "Test file tests/bank_and_account_test.cpp not found!")
endif()
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/tests/texteditor_test.cpp)
    message(FATAL_ERROR "Test file tests/texteditor_test.cpp not found!")
endif()

find_package(GTest REQUIRED)

if (NOT GTest_FOUND)
    message(FATAL_ERROR "GoogleTest not found!")
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

