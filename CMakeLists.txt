cmake_minimum_required(VERSION 3.16)
project(app LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# SFML 2.6.x
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# EnTT
include(ExternalProject)
ExternalProject_Add(
    entt
    PREFIX ${CMAKE_BINARY_DIR}/entt
    GIT_REPOSITORY https://github.com/skypjack/entt.git
    GIT_TAG master  # or specify the commit hash you need
    UPDATE_DISCONNECTED 1
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
)
ExternalProject_Get_Property(entt source_dir binary_dir)
include_directories(${source_dir}/src)

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

file(GLOB SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/Phoenix/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Phoenix/Game/*cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Phoenix/View/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Phoenix/Scene/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Phoenix/Scene/Systems/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Phoenix/Scene/Scenes/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Phoenix/Asset/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Phoenix/Utils/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Phoenix/Utils/*.cpp
)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/Phoenix
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-system sfml-audio box2d)

add_dependencies(${PROJECT_NAME} entt)

if(WIN32)
    add_custom_command(
            TARGET ${PROJECT_NAME}
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
            VERBATIM)
endif()

install(TARGETS ${PROJECT_NAME})
