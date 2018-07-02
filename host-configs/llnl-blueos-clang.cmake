##
## Copyright (c) 2016, Lawrence Livermore National Security, LLC.
##
## Produced at the Lawrence Livermore National Laboratory.
##
## All rights reserved.
##
##

set(RAJA_COMPILER "RAJA_COMPILER_CLANG" CACHE STRING "")

set(CMAKE_C_COMPILER   "mpiclang" CACHE PATH "")
set(CMAKE_CXX_COMPILER "mpiclang++" CACHE PATH "")
#set(CMAKE_C_COMPILER   "/usr/tcetmp/bin/mpiclang" CACHE PATH "")
#set(CMAKE_CXX_COMPILER "/usr/tcetmp/bin/mpiclang++" CACHE PATH "")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -ffast-math -std=c++14" CACHE STRING "")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O3 -g -std=c++14 -ffast-math" CACHE STRING "")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -std=c++14" CACHE STRING "")

set(ENABLE_CUDA Off CACHE BOOL "")
set(ENABLE_OPENMP On CACHE BOOL "")
set(ENABLE_MPI_WRAPPER On CACHE BOOL "")

set(RAJA_RANGE_ALIGN 4 CACHE INT "")
set(RAJA_RANGE_MIN_LENGTH 32 CACHE INT "")
set(RAJA_DATA_ALIGN 64 CACHE INT "")
set(RAJA_COHERENCE_BLOCK_SIZE 64 CACHE INT "")

set(RAJA_HOST_CONFIG_LOADED On CACHE Bool "")

