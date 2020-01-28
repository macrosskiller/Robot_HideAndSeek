#This work is licensed under the Creative Commons
#Attribution-NonCommercial-ShareAlike 4.0 International License.
#To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/
#or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.

cmake_minimum_required(VERSION 2.8)
project( Robot_HideAndSeek ) #project name

find_package( OpenCV REQUIRED )
if (OpenCV_FOUND)
    include_directories( ${OpenCV_INCLUDE_DIRS} )
else ()
    message(FATAL_ERROR "OpenCV not found, please install it")
endif ()

set(SRCS
    main.cpp
    Actuator.cpp
    Master.cpp
)

set(HEADERS
    Actuator.h
    Master.h
)

add_subdirectory(Detector)

add_executable( Robot_HideAndSeek ${SRCS} ${HEADERS} ) #project name and files names
target_link_libraries( Robot_HideAndSeek ${OpenCV_LIBS} )