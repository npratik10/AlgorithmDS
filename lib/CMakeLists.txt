include_directories(${CMAKE_CURRENT_LIST_DIR}/sorting/quicksort)
include_directories(${CMAKE_CURRENT_LIST_DIR}/sorting/mergesort/)

list(APPEND ds_inc
    "${CMAKE_CURRENT_LIST_DIR}/structures/LinkList/LinkList.hpp"
)

list(APPEND ds_src
    "${CMAKE_CURRENT_LIST_DIR}/structures/LinkList/LinkList.cpp"
)

add_library(data_structure STATIC ${ds_src} ${ds_inc})

#list(APPEND ds_gtest_inc
#    "${CMAKE_CURRENT_LIST_DIR}/structures/LinkList/linkList_gtest.hpp"
#)

#list(APPEND ds_gtest_src
#    "${CMAKE_CURRENT_LIST_DIR}/structures/LinkList/linkList_gtest.cpp"
#)

list(APPEND ds_gtest_src
    "${CMAKE_CURRENT_LIST_DIR}/structures/LinkList/LinkListval.cpp"
)

#add_executable(data_structure_gtest
#    ${ds_gtest_inc}
#    ${ds_gtest_src}
#)

add_executable(data_structure_gtest
    ${ds_gtest_src}
)

#add_dependencies(data_structure_gtest gtest)
target_link_libraries(data_structure_gtest
    data_structure
)

#target_include_directories(libutil PUBLIC ${CMAKE_SOURCE_DIR}/libutil/inc)
add_definitions(-DEXPMODULE)