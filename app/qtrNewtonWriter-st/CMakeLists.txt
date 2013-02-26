### CMakeLists.txt --- 
## 
## Author: Julien Wintz
## Copyright (C) 2008-2011 - Julien Wintz, Inria.
## Created: Wed Jan 23 00:01:50 2013 (+0100)
## Version: $Id$
## Last-Updated: Thu Jan 24 12:41:03 2013 (+0100)
##           By: Julien Wintz
##     Update #: 17
######################################################################
## 
### Commentary: 
## 
######################################################################
## 
### Change log:
## 
######################################################################

project(qtrNewtonWriter-st)

add_executable(${PROJECT_NAME} main.cpp)

qt5_use_modules(${PROJECT_NAME} Concurrent)
qt5_use_modules(${PROJECT_NAME} Core)
qt5_use_modules(${PROJECT_NAME} Gui)

target_link_libraries(${PROJECT_NAME} qtrCore)
