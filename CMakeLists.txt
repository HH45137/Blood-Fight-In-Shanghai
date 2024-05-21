cmake_minimum_required(VERSION 3.25.1)

set(PROJECT_NAME BFISH)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CURRENT_BINARY_DIR /build/bin/)

file(GLOB_RECURSE H_SRC
        src/*.h
        src/*.hpp
)
file(GLOB_RECURSE CPP_SRC
        src/*.cpp
)

# If current platform is Linux
if (CMAKE_SYSTEM_NAME MATCHES "Linux")

    add_executable(${PROJECT_NAME} src/main.cpp ${H_SRC} ${CPP_SRC})

endif (CMAKE_SYSTEM_NAME MATCHES "Linux")


# If current platform is Windows
if (CMAKE_SYSTEM_NAME MATCHES "Windows")

    set(CMAKE_EXE_LINKER_FLAGS "-static")

    # GLM
    find_package(glm CONFIG REQUIRED)
    #SDL
    find_package(SDL2 CONFIG REQUIRED)

    add_executable(${PROJECT_NAME} src/main.cpp ${H_SRC} ${CPP_SRC})

    # GLM library
    target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm-header-only)
    # SDL library
    target_link_libraries(${PROJECT_NAME}
            PRIVATE
            $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
            $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
    )

endif (CMAKE_SYSTEM_NAME MATCHES "Windows")
