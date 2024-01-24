cmake_minimum_required(VERSION 3.16)
project(app LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# sfml 2.6.x
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# spdlog 1.12.0
include(FetchContent)
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
  GIT_TAG v1.12.0
)
FetchContent_MakeAvailable(spdlog)
include_directories("${CMAKE_CURRENT_BINARY_DIR}/_deps/spdlog-src/include")


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/View/Window.cpp
        src/View/Window.h
        src/Game/Game.cpp
        src/Game/Game.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-system sfml-audio)

if(WIN32)
    add_custom_command(
            TARGET ${PROJECT_NAME}
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
            VERBATIM)
endif()

install(TARGETS ${PROJECT_NAME})