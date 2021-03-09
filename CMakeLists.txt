cmake_minimum_required(VERSION 3.5)
project(JWT-drogon)

message(STATUS "compiler: " ${CMAKE_CXX_COMPILER_ID})

if (HAS_ANY AND HAS_STRING_VIEW AND HAS_COROUTINE)
    set(CMAKE_CXX_STANDARD 20)
elseif (HAS_ANY AND HAS_STRING_VIEW)
    set(CMAKE_CXX_STANDARD 17)
else ()
    set(CMAKE_CXX_STANDARD 14)
endif ()

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(WRITE test.cc "int main() { return 0; }")

add_library(JWTTestLibrary OBJECT test.cc)
add_executable(${PROJECT_NAME} $<TARGET_OBJECTS:JWTTestLibrary>)

add_subdirectory(json)
add_subdirectory(cpp-jwt)

target_link_libraries(${PROJECT_NAME} PUBLIC nlohmann_json::nlohmann_json cpp-jwt::cpp-jwt)

set(BUILD_EXAMPLES FALSE)
set(BUILD_TESTING TRUE)

if(BUILD_EXAMPLES)
  add_subdirectory(examples)
endif(BUILD_EXAMPLES)

if(BUILD_TESTING)
  find_package(GTest)
  if(GTest_FOUND)
    message(STATUS "gtest found")
    enable_testing()
    add_subdirectory(unittest)
  endif(GTest_FOUND)
endif(BUILD_TESTING)