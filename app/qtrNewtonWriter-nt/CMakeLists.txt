### CMakeLists.txt --- 
## 
## Author: Julien Wintz
## Copyright (C) 2008-2011 - Julien Wintz, Inria.
## Created: Fri Jan 25 23:50:05 2013 (+0100)
## Version: $Id$
## Last-Updated: Tue Jan 29 14:22:45 2013 (+0100)
##           By: Julien Wintz
##     Update #: 3
######################################################################
## 
### Commentary: 
## 
######################################################################
## 
### Change log:
## 
######################################################################

project(qtrNewtonWriter-nt)

add_executable(${PROJECT_NAME} main.cpp)

qt5_use_modules(${PROJECT_NAME} Concurrent)
qt5_use_modules(${PROJECT_NAME} Core)
qt5_use_modules(${PROJECT_NAME} Gui)

target_link_libraries(${PROJECT_NAME} qtrCore)
