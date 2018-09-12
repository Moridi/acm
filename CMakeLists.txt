cmake_minimum_required(VERSION 2.8)

project(AdvancedCoffeeMakers)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS})
