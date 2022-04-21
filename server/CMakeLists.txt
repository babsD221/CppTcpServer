cmake_minimum_required(VERSION 3.10)

project(ChatApp)

set(CMAKE_CXX_STANDARD 20)

#set(HEADER_FILES )
set(HEADER_FILES 
Server.hpp)
set (SRCS 
main.cpp 
Server.cpp
)

add_executable(ChatServer ${SRCS} ${HEADER_FILES} )