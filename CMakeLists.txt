cmake_minimum_required(VERSION 3.16)
project(VibeCasino LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# Try to find raylib via pkg-config first (Linux/macOS). If not found,
# fall back to a bundled submodule at external/raylib (useful on Windows).
find_package(PkgConfig QUIET)
set(USE_SUBMODULE OFF)
if(PKG_CONFIG_FOUND)
	pkg_check_modules(PKG_RAYLIB QUIET raylib)
endif()

if(PKG_RAYLIB_FOUND)
	include_directories(${PKG_RAYLIB_INCLUDE_DIRS})
	link_directories(${PKG_RAYLIB_LIBRARY_DIRS})
	add_definitions(${PKG_RAYLIB_CFLAGS_OTHER})
	set(RAYLIB_LIBS ${PKG_RAYLIB_LIBRARIES})
else()
	# Expect a git submodule checkout at external/raylib
	set(RAYLIB_SUBMODULE_PATH "${CMAKE_SOURCE_DIR}/external/raylib")
	if(EXISTS "${RAYLIB_SUBMODULE_PATH}/CMakeLists.txt")
		message(STATUS "Using bundled raylib submodule at ${RAYLIB_SUBMODULE_PATH}")
		add_subdirectory(${RAYLIB_SUBMODULE_PATH} external_raylib_build)
		# raylib's CMake provides a target called raylib
		set(RAYLIB_LIBS raylib)
		include_directories(${RAYLIB_SUBMODULE_PATH}/src)
	else()
		message(FATAL_ERROR "raylib not found via pkg-config and submodule missing.\n\nAdd the submodule with:\n  git submodule add https://github.com/raysan5/raylib.git external/raylib\n  git submodule update --init --recursive\n\nOr install raylib on your system and ensure pkg-config can find it.")
	endif()
endif()

file(GLOB SRC "src/*.cpp")
add_executable(vibecasino ${SRC})
target_include_directories(vibecasino PRIVATE src)
target_link_libraries(vibecasino PRIVATE ${RAYLIB_LIBS})
