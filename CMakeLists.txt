cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(Multiclock)

#Bring the headers into the project
include_directories(include)
link_directories(/usr/local/lib/prolog)

#Add sources and includes:
file(GLOB SOURCES "src/*.cpp")
file(GLOB INCLUDES "include/*.h")

# Define library and include directories
set(STATIC_LIB_DIR /usr/local/lib/multiclock)
set(INCLUDE_DIR /usr/local/include/multiclock)

# generate libmulticlock.a file
add_library(multiclock STATIC ${SOURCES})

# install lib and include directories
install(TARGETS multiclock DESTINATION ${STATIC_LIB_DIR})
install(FILES ${INCLUDES} DESTINATION ${INCLUDE_DIR})
