cmake_minimum_required(VERSION 3.13)

project(TinyTester LANGUAGES C CXX)

set(TINY_TESTER_PROJECT_PATH ${CMAKE_SOURCE_DIR}/TinyTester)
set(TINY_TESTER_SRC_PATH ${TINY_TESTER_PROJECT_PATH}/src)
set(TINY_TESTER_RESOURCE_PATH ${TINY_TESTER_PROJECT_PATH}/res)

file(GLOB_RECURSE TINY_TESTER_PROJECT_SOURCES ${TINY_TESTER_SRC_PATH}/*.cpp ${TINY_TESTER_SRC_PATH}/*.c)
file(GLOB_RECURSE TINY_TESTER_PROJECT_HEADERS ${TINY_TESTER_SRC_PATH}/*.h)
file(GLOB_RECURSE TINY_TESTER_PROJECT_RESOURCES ${TINY_TESTER_RESOURCE_PATH}/*.*)


source_group(TREE ${TINY_TESTER_PROJECT_PATH} FILES ${TINY_TESTER_PROJECT_SOURCES})
source_group(TREE ${TINY_TESTER_PROJECT_PATH} FILES ${TINY_TESTER_PROJECT_HEADERS})
source_group(TREE ${TINY_TESTER_PROJECT_PATH} FILES ${TINY_TESTER_PROJECT_RESOURCES})

add_executable(TinyTester ${TINY_TESTER_PROJECT_HEADERS} ${TINY_TESTER_PROJECT_SOURCES} ${TINY_TESTER_RESOURCE_PATH})

set_property(TARGET TinyTester PROPERTY CXX_STANDARD 11)
set_property(TARGET TinyEngine PROPERTY C_STANDARD 17)

target_include_directories(TinyTester PRIVATE ${STB_INCLUDE_DIRS} PRIVATE ${TINY_TESTER_SRC_PATH} ) 
target_link_libraries(TinyTester PRIVATE SDL2::SDL2 SDL2::SDL2main 
                                        PRIVATE asio asio::asio 
                                        PRIVATE Catch2::Catch2 
                                        PRIVATE glad::glad
                                        PRIVATE imgui::imgui 
                                        PRIVATE nlohmann_json nlohmann_json::nlohmann_json
                                        PRIVATE SDL2::SDL2_image 
                                        PRIVATE SDL2::SDL2_mixer 
                                        PRIVATE SDL2::SDL2_ttf 
                                        PRIVATE spdlog::spdlog spdlog::spdlog_header_only 
                                        PRIVATE OpenAL::OpenAL 
                                        PRIVATE EASTL 
                                        PRIVATE TinyEngine
)

set_target_properties(TinyTester PROPERTIES 
ARCHIVE_OUTPUT_DIRECTORY "${TINY_C_RELEASE_PATH}/lib" 
LIBRARY_OUTPUT_DIRECTORY "${TINY_C_RELEASE_PATH}/lib" 
RUNTIME_OUTPUT_DIRECTORY "${TINY_C_RELEASE_PATH}" 
)

if (MSVC)
  set_property(TARGET TinyTester PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${TINY_C_RELEASE_PATH})
  set_target_properties(TinyTester PROPERTIES 
  ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${TINY_C_DEBUG_PATH}/lib" 
  ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${TINY_C_RELEASE_PATH}/lib"  
  LIBRARY_OUTPUT_DIRECTORY_DEBUG "${TINY_C_DEBUG_PATH}/lib" 
  LIBRARY_OUTPUT_DIRECTORY_RELEASE "${TINY_C_RELEASE_PATH}/lib"  
  RUNTIME_OUTPUT_DIRECTORY_DEBUG "${TINY_C_DEBUG_PATH}" 
  RUNTIME_OUTPUT_DIRECTORY_RELEASE "${TINY_C_RELEASE_PATH}" 
)

elseif(UNIX AND NOT APPLE)
  target_link_libraries(TinyTester PRIVATE  SDL2::SDL2-static Catch2::Catch2WithMain)
  target_link_libraries(TinyTester PRIVATE  X11  Xext )

endif()

add_custom_command(TARGET TinyTester POST_BUILD 
                   COMMAND ${CMAKE_COMMAND} -E copy_directory 
                      ${CMAKE_SOURCE_DIR}/TinyTester/res ${TINY_C_RELEASE_PATH}/res 
)

