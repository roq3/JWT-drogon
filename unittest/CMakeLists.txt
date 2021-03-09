cmake_minimum_required(VERSION 3.5)
project(JWT-drogon-unit-tests CXX)

message(STATUS "compiler: " ${CMAKE_CXX_COMPILER_ID})

add_executable(simple_unittest SimpleUnittest.cpp)
add_executable(simple_secret SimpleSecret.cpp)

set(UNITTEST_TARGETS
  simple_unittest
  simple_secret
)

set_property(TARGET ${UNITTEST_TARGETS}
             PROPERTY CXX_STANDARD ${CMAKE_CXX_STANDARD})
set_property(TARGET ${UNITTEST_TARGETS} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${UNITTEST_TARGETS} PROPERTY CXX_EXTENSIONS OFF)

include(GoogleTest)
foreach(T ${UNITTEST_TARGETS})
  target_link_libraries(${T} PRIVATE nlohmann_json::nlohmann_json cpp-jwt::cpp-jwt GTest::GTest)
  gtest_discover_tests(${T})
endforeach()
