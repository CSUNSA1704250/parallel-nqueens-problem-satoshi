# AsulconS - Config File
# Copyright (c) 2021 Adrian Bedregal
#
# This software is provided 'as-is', without any express or implied
# warranty. In no event will the authors be held liable for any damages
# arising from the use of this software.
#
# Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it
# freely, subject to the following restrictions:
#
# 1. The origin of this software must not be misrepresented; you must not
#    claim that you wrote the original software. If you use this software
#    in a product, an acknowledgment in the product documentation would be
#    appreciated but is not required.
# 2. Altered source versions must be plainly marked as such, and must not be
#    misrepresented as being the original software.
# 3. This notice may not be removed or altered from any source distribution.
cmake_minimum_required(VERSION 3.12)

# Disable CYGWIN Legacy Warning
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

# * Set where .dlls should go (in revision)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_SOURCE_DIR}>)

# Project info
project(NQueens)

# Set C++11 as the standard
set(CMAKE_CXX_STANDARD 11)

# Set generic lib name
set(NQUEENS_LIB_NAME nqueens)

# GNU Install Dirs
include(GNUInstallDirs)

# Get Source Files
set(NQUEENS_SOURCES
    src/nqueens.cpp
)

# Buil library
add_library(${NQUEENS_LIB_NAME} STATIC ${NQUEENS_SOURCES})
set_target_properties(${NQUEENS_LIB_NAME}
PROPERTIES
    PUBLIC_HEADER include/nqueens.hpp
)
target_compile_definitions(${NQUEENS_LIB_NAME}
PRIVATE
    __STDC_LIB_EXT1__
    __NQUEENS_COMPILING
)
target_include_directories(${NQUEENS_LIB_NAME} PRIVATE include)

# Build main executable
add_executable(main src/main.cpp)
target_include_directories(main PRIVATE include)
target_compile_definitions(main
PRIVATE
    __STDC_LIB_EXT1__
)
target_compile_options(main PRIVATE /openmp)
target_link_libraries(main LINK_PUBLIC ${NQUEENS_LIB_NAME})
