cmake_minimum_required(VERSION 3.16)
project(app LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../)
# option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# SFML 2.6.x
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# EnTT
FetchContent_Declare(
    entt
    GIT_REPOSITORY https://github.com/skypjack/entt.git
    GIT_TAG master
)
FetchContent_MakeAvailable(entt)
include_directories(${entt_SOURCE_DIR}/src)

# spdlog 1.12.0
FetchContent_Declare(
     spdlog
     GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
     GIT_TAG v1.12.0
)
FetchContent_MakeAvailable(spdlog)
include_directories("${CMAKE_CURRENT_BINARY_DIR}/_deps/spdlog-src/include")

# Box2D
FetchContent_Declare(
    box2d
    GIT_REPOSITORY https://github.com/erincatto/box2d.git
    GIT_TAG v2.4.1
)
set(BOX2D_BUILD_UNIT_TESTS OFF CACHE BOOL "Build Box2D unit tests" FORCE)
FetchContent_MakeAvailable(box2d)
include_directories(${box2d_SOURCE_DIR}/include)

add_subdirectory(Phoenix)
add_subdirectory(Sandbox)

if(WIN32)
    add_custom_command(
            TARGET ${PROJECT_NAME}
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
            VERBATIM)
endif()

install(TARGETS ${PROJECT_NAME})
