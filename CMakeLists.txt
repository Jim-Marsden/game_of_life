cmake_minimum_required(VERSION 3.17)
project(Game_Of_Life VERSION 1.0.0 DESCRIPTION "Thank you John Conway for all you contributed")

#on windows you must add the option -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE -DBUILD_SHARED_LIBS=TRUE
# Otherwise it won't export the dll symbols. It's a windows issue :c

set(CMAKE_CXX_STANDARD 20)

add_executable(Game_Of_Life main.cpp)

add_library(rules SHARED
        rules_dll/main.cpp
        rules_dll/main.hpp)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_library(renderer SHARED
        renderer_lib/main.hpp
        renderer_lib/main.cpp)

target_link_libraries(renderer PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
#target_link_libraries(renderer PRIVATE sfml-graphics sfml-window)

target_link_libraries(Game_Of_Life PUBLIC rules renderer)



