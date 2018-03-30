cmake_minimum_required(VERSION 2.8.12)
project(cppNN)

set (CMAKE_CXX_STANDARD 11)

SET(SOURCE_DIR "src/${PROJECT_NAME}")
# Tell cmake that headers are in alse in source_dir
include_directories(${SOURCE_DIR})
# SET(SOURCES "${SOURCE_DIR}/vectors.cpp")

SET(TEST_DIR "tests")
SET(TESTS ${SOURCES}
    "${TEST_DIR}/test_main.cpp"
    "${TEST_DIR}/test_vectors.cpp")

# Generate a test executable
include_directories(lib/catch/include)
add_executable("${PROJECT_NAME}_test" ${TESTS})

# Generate python module
add_subdirectory(lib/pybind11)
pybind11_add_module(${PROJECT_NAME} ${SOURCES} "${SOURCE_DIR}/bindings.cpp")
