cmake_minimum_required(VERSION 3.16)
project(CS2353)

set(CMAKE_CXX_STANDARD 14)
configure_file(data/set_A.txt data/set_A.txt NEWLINE_STYLE UNIX)
configure_file(data/set_A.txt data/set_A.txt NEWLINE_STYLE UNIX)
configure_file(data/set_B.txt data/set_B.txt NEWLINE_STYLE UNIX)
configure_file(data/set_B.txt data/set_B.txt NEWLINE_STYLE UNIX)
add_executable(CS2353 main.cpp Element.cpp Element.h SetOfElements.cpp SetOfElements.h StableMatch.cpp StableMatch.h driver.cpp driver.h)
