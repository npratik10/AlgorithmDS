include_directories(${CMAKE_CURRENT_LIST_DIR}/sorting/quicksort)
include_directories(${CMAKE_CURRENT_LIST_DIR}/sorting/mergesort/)

list(APPEND algo_inc
    "${CMAKE_CURRENT_LIST_DIR}/sorting/quicksort/quicksort.hpp"
    "${CMAKE_CURRENT_LIST_DIR}/sorting/mergesort/mergesort.hpp"
)

list(APPEND algo_src
    "${CMAKE_CURRENT_LIST_DIR}/sorting/quicksort/quicksort.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/sorting/mergesort/mergesort.cpp"
)

add_library(algorithm STATIC ${algo_src} ${algo_inc})

#target_include_directories(libutil PUBLIC ${CMAKE_SOURCE_DIR}/libutil/inc)
add_definitions(-DEXPMODULE)