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

add_subdirectory(qtrQuick)

configure_file(qtrQuickConfig.h.in ${CMAKE_SOURCE_DIR}/src/qtrQuick/qtrQuickConfig)
configure_file(qtrQuickConfig.h.in ${CMAKE_SOURCE_DIR}/src/qtrQuick/qtrQuickConfig.h)

######################################################################
### CMakeLists.txt ends here
