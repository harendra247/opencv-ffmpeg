cmake_minimum_required(VERSION 2.8)
project( video-recorder )
set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
find_package( OpenCV REQUIRED )
add_executable( video-recorder video-recorder.cpp )
target_link_libraries( video-recorder ${OpenCV_LIBS} )
install(TARGETS video-recorder DESTINATION bin)
