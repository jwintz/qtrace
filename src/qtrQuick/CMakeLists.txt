### CMakeLists.txt --- 
## 
## Author: Julien Wintz
## Created: Mon Jan 28 20:26:10 2013 (+0100)
## Version: 
## Last-Updated: Wed Jan 30 15:15:55 2013 (+0100)
##           By: Julien Wintz
##     Update #: 26
######################################################################
## 
### Change Log:
## 
######################################################################

project(qtrQuick)

## #################################################################
## Sources
## #################################################################

set(${PROJECT_NAME}_HEADERS
  qtrCanvas.h
  qtrQuickPlugin.h)

set(${PROJECT_NAME}_SOURCES
  qtrCanvas.cpp
  qtrQuickPlugin.cpp)

## #################################################################
## Build rules
## #################################################################

add_definitions(-DQT_PLUGIN)

add_library(${PROJECT_NAME} SHARED
  ${${PROJECT_NAME}_SOURCES}
  ${${PROJECT_NAME}_HEADERS})

qt5_use_modules(${PROJECT_NAME} Concurrent)
qt5_use_modules(${PROJECT_NAME} Core)
qt5_use_modules(${PROJECT_NAME} Gui)
qt5_use_modules(${PROJECT_NAME} Quick)

target_link_libraries(${PROJECT_NAME} qtrCore)
