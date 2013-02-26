### CMakeLists.txt --- 
## 
## Author: Julien Wintz
## Created: Mon Jan 28 12:12:40 2013 (+0100)
## Version: 
## Last-Updated: Tue Jan 29 20:59:18 2013 (+0100)
##           By: Julien Wintz
##     Update #: 22
######################################################################
## 
### Change Log:
## 
######################################################################

project(qtrNewtonViewer)

qt5_add_resources(${PROJECT_NAME}_QRC main.qrc)

add_executable(${PROJECT_NAME} main.cpp ${${PROJECT_NAME}_QRC})

qt5_use_modules(${PROJECT_NAME} Core)
qt5_use_modules(${PROJECT_NAME} Gui)
qt5_use_modules(${PROJECT_NAME} Quick)
qt5_use_modules(${PROJECT_NAME} Widgets)

target_link_libraries(${PROJECT_NAME} qtrCore)
