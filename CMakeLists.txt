cmake_minimum_required(VERSION 3.13)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")



project(TinyC LANGUAGES C CXX)

#unset(TINY_C_RELEASE_PATH CACHE)
#unset(TINY_C_DEBUG_PATH CACHE)
set(TINY_C_RELEASE_PATH  "${PROJECT_SOURCE_DIR}/release")
set(TINY_C_DEBUG_PATH  "${PROJECT_SOURCE_DIR}/debug")

find_package(SDL2 CONFIG REQUIRED)
find_package(asio CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(sdl2-mixer CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(OpenAL CONFIG REQUIRED)
find_package(EASTL CONFIG REQUIRED)
find_path(STB_INCLUDE_DIRS "stb.h")


add_subdirectory(TinyEngine)
add_subdirectory(TinyTester)

target_include_directories(TinyTester PRIVATE ${CMAKE_SOURCE_DIR}/TinyEngine/src)
if (MSVC)
  set_target_properties(TinyTester PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${TINY_C_RELEASE_PATH})
endif()