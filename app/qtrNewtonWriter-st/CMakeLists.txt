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

project(qtrNewtonWriter-st)

## #################################################################
## Build rules
## #################################################################

add_executable(${PROJECT_NAME} main.cpp)

qt5_use_modules(${PROJECT_NAME} Concurrent)
qt5_use_modules(${PROJECT_NAME} Core)
qt5_use_modules(${PROJECT_NAME} Gui)

target_link_libraries(${PROJECT_NAME} qtrCore)

## #################################################################
## Install rules - targets
## #################################################################

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

######################################################################
### CMakeLists.txt ends here
