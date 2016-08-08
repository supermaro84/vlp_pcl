cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(cloud_viewer)
find_package(PCL REQUIRED COMPONENTS common io visualization segmentation)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcd_write_test pcd_write_test.cpp)
target_link_libraries(pcd_write_test ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})

add_executable(cloud_viewer cloud_viewer.cpp)
target_link_libraries(cloud_viewer ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES} ${PCL_LIBRARIES})


