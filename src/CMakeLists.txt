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

set(I2CDEV_ROOT_DIR
	"${I2CDEV_ROOT_DIR}"
	CACHE
	PATH
	"Directory to search for libi2c-dev")

if(CMAKE_SIZEOF_VOID_P MATCHES "8")
	set(_LIBSUFFIXES /lib64 /lib)
else()
	set(_LIBSUFFIXES /lib)
endif()

find_path(I2CDEV_INCLUDE_DIR
	NAMES
	linux/i2c-dev.h
	HINTS
	"${_libdir}"
	PATHS
	"${I2CDEV_ROOT_DIR}"
	PATH_SUFFIXES
	include/)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(I2CDEV
	DEFAULT_MSG
	I2CDEV_INCLUDE_DIR
	)

if(I2CDEV_FOUND)
	set(I2CDEV_INCLUDE_DIRS "${I2CDEV_INCLUDE_DIR}")
	mark_as_advanced(I2CDEV_ROOT_DIR)
endif()

mark_as_advanced(I2CDEV_INCLUDE_DIR)

set(SRCS
    main.cpp
    Master.cpp
)

set(HEADERS
    Master.h
)

add_subdirectory(Actuator)
add_subdirectory(Detector)

add_executable( Robot_HideAndSeek ${SRCS} ${HEADERS} ) #project name and files names
target_link_libraries( Robot_HideAndSeek ${OpenCV_LIBS} )
target_link_libraries( Robot_HideAndSeek ${I2CDEV} )