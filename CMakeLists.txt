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
set(NQUEENS_LIB_NAME nqueensLib)

# GNU Install Dirs
include(GNUInstallDirs)

# Get Source Files
set(NQUEENS_SOURCES
    src/utils.cpp
    src/nqueens.cpp
)

# Buil library
add_library(${NQUEENS_LIB_NAME} STATIC ${NQUEENS_SOURCES})
target_compile_definitions(${NQUEENS_LIB_NAME}
PRIVATE
    __STDC_LIB_EXT1__
)
target_include_directories(${NQUEENS_LIB_NAME} PRIVATE include)

# Build main executable
add_executable(nqueens src/main.cpp)
target_include_directories(nqueens PRIVATE include)
target_compile_definitions(nqueens
PRIVATE
    __STDC_LIB_EXT1__
)
target_compile_options(nqueens PRIVATE /openmp)
target_link_libraries(nqueens LINK_PUBLIC ${NQUEENS_LIB_NAME})
