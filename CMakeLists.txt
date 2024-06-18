cmake_minimum_required(VERSION 3.28)
project(afpractica C)

set(CMAKE_C_STANDARD 99)

add_executable(afpractica main.c
        zadaniya/zadanie_1.c
        zadaniya/zadanie.h)
add_subdirectory(zadaniya)
target_link_libraries(zadaniya)