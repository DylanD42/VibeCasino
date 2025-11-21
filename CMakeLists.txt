cmake_minimum_required(VERSION 3.16)
project(VibeCasino LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

include_directories(${RAYLIB_INCLUDE_DIRS})
link_directories(${RAYLIB_LIBRARY_DIRS})
add_definitions(${RAYLIB_CFLAGS_OTHER})

file(GLOB SRC "src/*.cpp")
add_executable(vibecasino ${SRC})
target_include_directories(vibecasino PRIVATE src)
target_link_libraries(vibecasino PRIVATE ${RAYLIB_LIBRARIES})
