### CMakeLists.txt --- 
## 
## Author: Julien Wintz
## Copyright (C) 2008-2011 - Julien Wintz, Inria.
## Created: Tue Jan 22 12:07:46 2013 (+0100)
## Version: $Id$
## Last-Updated: Tue Jan 29 18:55:43 2013 (+0100)
##           By: Julien Wintz
##     Update #: 27
######################################################################
## 
### Commentary: 
## 
######################################################################
## 
### Change log:
## 
######################################################################

cmake_minimum_required(VERSION 2.8.10)

######################################################################

project(qtr)

## #################################################################
## 
## #################################################################

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

## #################################################################
## 
## #################################################################

mark_as_advanced(CMAKE_BUILD_TYPE)
mark_as_advanced(CMAKE_INSTALL_PREFIX)
mark_as_advanced(CMAKE_OSX_ARCHITECTURES)
mark_as_advanced(CMAKE_OSX_DEPLOYMENT_TARGET)
mark_as_advanced(CMAKE_OSX_SYSROOT)

## #################################################################
## Dependencies - Qt
## #################################################################

find_package(Qt5Concurrent  REQUIRED)
find_package(Qt5Core        REQUIRED)
find_package(Qt5Gui         REQUIRED)
find_package(Qt5Quick       REQUIRED)
find_package(Qt5Widgets     REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

## #################################################################
## Dependencies - internal
## #################################################################

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/qtrCore)
include_directories(${CMAKE_SOURCE_DIR}/src/qtrQuick)

## #################################################################
## Input
## #################################################################

add_subdirectory(src)
add_subdirectory(qml)
add_subdirectory(app)
add_subdirectory(bench)
