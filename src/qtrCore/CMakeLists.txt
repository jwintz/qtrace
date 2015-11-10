## Version: $Id$
##
######################################################################
##
### Commentary:
##
######################################################################
##
### Change Log:
##
######################################################################
##
### Code:

project(qtrCore)

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

if(UNIX AND NOT APPLE)
  target_link_libraries(${PROJECT_NAME} bsd)
endif(UNIX AND NOT APPLE)

## ###################################################################
## Install rules - targets
## ###################################################################

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

######################################################################
### CMakeLists.txt ends here
