#!/bin/bash
rm -rf build/*
cmake -B build/ -S .
make -C build/ && ./build/ChatServer
