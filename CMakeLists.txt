cmake_minimum_required (VERSION 3.9)

project (main)
set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp)

include_directories("C:\\Users\\Danila\\vcpkg\\installed\\x64-windows\\include")
link_directories("C:\\Users\\Danila\\vcpkg\\installed\\x64-windows\\lib")

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(main PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
# If you want SFML to provide an implementation of main():
target_link_libraries(main PRIVATE sfml-main)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
