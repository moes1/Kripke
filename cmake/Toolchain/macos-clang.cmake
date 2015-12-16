
set(CMAKE_CXX_COMPILER "mpic++" CACHE STRING barfoo FORCE)
set(CMAKE_LINKER "mpic++" CACHE STRING barfoo FORCE)

set(CMAKE_CXX_FLAGS "-Wall -O3 -g -std=c++14 -DRAJA_PLATFORM_X86_SSE -DRAJA_COMPILER_CLANG" CACHE STRING barfoo FORCE)

set(CMAKE_LINKER_FLAGS "" CACHE STRING barfoo FORCE)

# CUDA Compiler Setup
#set(CUDA_NVCC_FLAGS "-arch compute_35 -std=c++11" CACHE STRING foobar FORCE)
#set(CUDA_HOST_COMPILER ${CMAKE_CXX_COMPILER} CACHE STRING barfoo FORCE)
