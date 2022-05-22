cmake_minimum_required(VERSION 3.13)

project(TinyEngine LANGUAGES C CXX)


set(TINY_ENGINE_PROJECT_PATH ${CMAKE_SOURCE_DIR}/TinyEngine)
set(TINY_ENGINE_SRC_PATH ${TINY_ENGINE_PROJECT_PATH}/src)

file(GLOB_RECURSE TINY_ENGINE_PROJECT_SOURCES ${TINY_ENGINE_SRC_PATH}/*.cpp ${TINY_ENGINE_SRC_PATH}/*.c)

file(GLOB_RECURSE TINY_ENGINE_PROJECT_HEADERS ${TINY_ENGINE_SRC_PATH}/*.h)


source_group(TREE ${TINY_ENGINE_PROJECT_PATH} FILES ${TINY_ENGINE_PROJECT_SOURCES})
source_group(TREE ${TINY_ENGINE_PROJECT_PATH} FILES ${TINY_ENGINE_PROJECT_HEADERS})

add_library(TinyEngine SHARED ${TINY_ENGINE_PROJECT_HEADERS} ${TINY_ENGINE_PROJECT_SOURCES})

set_property(TARGET TinyEngine PROPERTY CXX_STANDARD 11)
set_property(TARGET TinyEngine PROPERTY C_STANDARD 17)

target_include_directories(TinyEngine PRIVATE ${STB_INCLUDE_DIRS} PRIVATE ${TINY_ENGINE_SRC_PATH} ) 
target_link_libraries(TinyEngine PRIVATE SDL2::SDL2 SDL2::SDL2main 
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
)



set_target_properties(TinyEngine PROPERTIES 
ARCHIVE_OUTPUT_DIRECTORY "${TINY_C_RELEASE_PATH}/lib" 
LIBRARY_OUTPUT_DIRECTORY "${TINY_C_RELEASE_PATH}/lib" 
RUNTIME_OUTPUT_DIRECTORY "${TINY_C_RELEASE_PATH}" 
)

if (MSVC)
  set_property(TARGET TinyEngine PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${TINY_C_RELEASE_PATH})
  set_target_properties(TinyEngine PROPERTIES 
  ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${TINY_C_DEBUG_PATH}/lib" 
  ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${TINY_C_RELEASE_PATH}/lib"  
  LIBRARY_OUTPUT_DIRECTORY_DEBUG "${TINY_C_DEBUG_PATH}/lib" 
  LIBRARY_OUTPUT_DIRECTORY_RELEASE "${TINY_C_RELEASE_PATH}/lib"  
  RUNTIME_OUTPUT_DIRECTORY_DEBUG "${TINY_C_DEBUG_PATH}" 
  RUNTIME_OUTPUT_DIRECTORY_RELEASE "${TINY_C_RELEASE_PATH}" 
)

elseif(UNIX AND NOT APPLE)
  target_link_libraries(TinyEngine PRIVATE  SDL2::SDL2-static Catch2::Catch2WithMain)
  target_link_libraries(TinyEngine PRIVATE  X11  Xext )
endif()

