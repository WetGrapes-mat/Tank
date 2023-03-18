cmake_minimum_required(VERSION 3.16)

project(game VERSION 0.1.0)

file(
  GLOB_RECURSE
  SOURCES
  "src/*.cpp"
  "src/*.hpp")


set(CMAKE_CXX_STANDARD 17)
find_package(SFML COMPONENTS graphics REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(game sfml-graphics)


