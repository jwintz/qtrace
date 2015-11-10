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

project(qtrNewtonViewer)

## #################################################################
## Build rules
## #################################################################

qt5_add_resources(${PROJECT_NAME}_QRC main.qrc)

add_executable(${PROJECT_NAME} main.cpp ${${PROJECT_NAME}_QRC})

qt5_use_modules(${PROJECT_NAME} Core)
qt5_use_modules(${PROJECT_NAME} Gui)
qt5_use_modules(${PROJECT_NAME} Quick)
qt5_use_modules(${PROJECT_NAME} Widgets)

target_link_libraries(${PROJECT_NAME} qtrCore)

## #################################################################
## Install rules - targets
## #################################################################

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

######################################################################
### CMakeLists.txt ends here
