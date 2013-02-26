### CMakeLists.txt --- 
## 
## Author: Julien Wintz
## Created: Tue Jan 29 18:55:21 2013 (+0100)
## Version: 
## Last-Updated: Tue Jan 29 19:59:56 2013 (+0100)
##           By: Julien Wintz
##     Update #: 6
######################################################################
## 
### Change Log:
## 
######################################################################

add_subdirectory(qtrQuick)

configure_file(qtrQuickConfig.h.in ${CMAKE_SOURCE_DIR}/src/qtrQuick/qtrQuickConfig)
configure_file(qtrQuickConfig.h.in ${CMAKE_SOURCE_DIR}/src/qtrQuick/qtrQuickConfig.h)
