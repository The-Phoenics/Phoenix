file(GLOB SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/*cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/View/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene/Systems/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene/Scenes/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Asset/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils/*.cpp
)

# target_compile_options("-fPIC")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/
)

add_library(phoenix SHARED ${SOURCE_FILES})

target_link_libraries(phoenix PRIVATE sfml-graphics sfml-system sfml-audio box2d)
add_dependencies(phoenix entt)