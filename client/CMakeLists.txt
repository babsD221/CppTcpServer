cmake_minimum_required(VERSION 3.10)

project(ChatApp)

set(CMAKE_CXX_STANDARD 20)

#set(HEADER_FILES )
set(HEADER_FILES 
Client.hpp)
set (SRCS 
main.cpp
Client.cpp)

add_executable(ChatClient ${HEADER_FILES} ${SRCS})