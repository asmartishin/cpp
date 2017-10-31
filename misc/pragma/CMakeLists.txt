cmake_minimum_required(VERSION 3.4)

project(pragma)

include_directories(include/)

set(HEADERS
    include/a/class.h
    include/b/class.h
)

set(SOURCES
    src/a/class.cpp
    src/b/class.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
