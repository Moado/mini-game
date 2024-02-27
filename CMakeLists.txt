cmake_minimum_required(VERSION 3.22)
project(mini_game)

set(CMAKE_CXX_STANDARD 17)

file(GLOB MY_FILES "data/")
file(COPY ${MY_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_custom_target(data
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/data
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/data ${CMAKE_BINARY_DIR}/data
        COMMENT "copying ${CMAKE_SOURCE_DIR}/data to ${CMAKE_BINARY_DIR}/data"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_package(X11 REQUIRED)
    find_package(OpenGL REQUIRED)
    find_package(Threads REQUIRED)
    find_package(PNG REQUIRED)
endif ()

set (
        CMAKE_CXX_FLAGS_DEBUG
        "${CMAKE_CXX_FLAGS_DEBUG} --debug -Wall"
)

set (
        CMAKE_FLAGS_RELEASE
        "${CMAKE_CXX_FLAGS_RELEASE} -Wall"
)

add_executable(mini_game main.cpp)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(mini_game X11 GL pthread png stdc++fs)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_link_libraries(mini_game OpenGL GLUT Carbon png)
endif ()
