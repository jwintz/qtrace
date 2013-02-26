### CMakeLists.txt --- 
## 
## Author: Julien Wintz
## Copyright (C) 2008-2011 - Julien Wintz, Inria.
## Created: Wed Jan 23 00:01:50 2013 (+0100)
## Version: $Id$
## Last-Updated: Thu Jan 24 12:39:29 2013 (+0100)
##           By: Julien Wintz
##     Update #: 16
######################################################################
## 
### Commentary: 
## 
######################################################################
## 
### Change log:
## 
######################################################################

project(qtrNewtonWriter-mt)

add_executable(${PROJECT_NAME} main.cpp)

qt5_use_modules(${PROJECT_NAME} Concurrent)
qt5_use_modules(${PROJECT_NAME} Core)
qt5_use_modules(${PROJECT_NAME} Gui)
qt5_use_modules(${PROJECT_NAME} Widgets)

target_link_libraries(${PROJECT_NAME} qtrCore)
