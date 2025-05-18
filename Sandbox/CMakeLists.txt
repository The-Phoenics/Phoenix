file(GLOB SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sandbox.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

message(${CMAKE_CURRENT_SOURCE_DIR}/../Phoenix)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/../Phoenix
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC phoenix)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-system sfml-audio box2d)