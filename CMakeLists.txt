cmake_minimum_required(VERSION 3.10)

project(RayTracing)

include_directories(include)
include_directories(include/maths)

file (GLOB SRC_FILES
    "${PROJECT_SOURCE_DIR}/include/maths/*.h"
    "${PROJECT_SOURCE_DIR}/include/maths/*.cpp"
    "${PROJECT_SOURCE_DIR}/include/*.h"
    "${PROJECT_SOURCE_DIR}/include/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)
