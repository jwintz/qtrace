### CMakeLists.txt --- 
## 
## Author: Julien Wintz
## Copyright (C) 2008-2011 - Julien Wintz, Inria.
## Created: Thu Jan 24 11:12:53 2013 (+0100)
## Version: $Id$
## Last-Updated: Thu Jan 24 13:18:59 2013 (+0100)
##           By: Julien Wintz
##     Update #: 12
######################################################################
## 
### Commentary: 
## 
######################################################################
## 
### Change log:
## 
######################################################################

project(qtrCore)

######################################################################

## #################################################################
## Sources
## #################################################################

set(${PROJECT_NAME}_HEADERS
  qtrRenderer.h
  qtrTile.h
  qtrTiler.h)

set(${PROJECT_NAME}_SOURCES
  qtrRenderer.cpp
  qtrTile.cpp
  qtrTiler.cpp)

## #################################################################
## Build rules
## #################################################################

add_library(${PROJECT_NAME} SHARED
  ${${PROJECT_NAME}_SOURCES}
  ${${PROJECT_NAME}_HEADERS})

qt5_use_modules(${PROJECT_NAME} Core)
qt5_use_modules(${PROJECT_NAME} Gui)
